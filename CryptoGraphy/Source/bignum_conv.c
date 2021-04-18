/*
 **************************************************************************************************** 
 *                                      INCLUDE
 ***************************************************************************************************
 */
#include "bignum_util.h"
#include "bignum_conv.h"


/*
 **************************************************************************************************** 
 *                                      GLOBAL LOCAL VARIABLE
 ***************************************************************************************************
 */
static char gASCBuff[8192];

/*
 **************************************************************************************************** 
 *                                      LOCAL DECLARATION
 ***************************************************************************************************
 */
static int32_t BN_strlen(__IN char* str);
static int32_t BN_Asc2Digit(__IN char asc);


/*
 **************************************************************************************************** 
 *                                      EXTERN DEFINITION
 ***************************************************************************************************
 */
int32_t BN_CreateInstance(__OUT BIGNUM_t* pBN, __IN uint32_t* pBuff, __IN int32_t capacity)
{
    int32_t ret = 0;
    int32_t i;

    if((pBuff != (uint32_t*)0) && (capacity != 0) && (pBN != (BIGNUM_t*)0))
    {
        pBN->capacity = capacity;
        pBN->pWord = pBuff;

        for(i = 0; i < capacity; i += 1)
        {
            pBuff[i] = 0U;
        }

        pBN->length     = 0;
        pBN->negative   = 0;
    }
    else
    {
        ret = -1;
    }

    return ret;
}

int32_t BN_Asc2Bignum(__OUT BIGNUM_t* pBN, __IN char* str)
{
    int32_t ret = 0;

    if((str[0] == '0') && (str[1] == 'x'))
    {
        ret = BN_Hex2Bignum(pBN, &str[2]);
    }
    else
    {
        ret = -1;
    }

    return ret;
}

int32_t BN_Hex2Bignum(__OUT BIGNUM_t* pBN, __IN char* str)
{
    int32_t ret = 0;
    int32_t length;
    int32_t digit;
    int32_t i, j, k;

    length = BN_strlen(str);
    if((length > 0) && ((length / 4) < pBN->capacity))
    {
        for(i = length, j = 0; i > -1 ; i -= 1, j += 1)
        {
            digit = BN_Asc2Digit(str[i]);
            if(digit != -1)
            {
                k = j / 8;
                pBN->pWord[k] |= digit << ((j % 8) * 4);
            }
            else
            {
                ret = -1;
                break;
            }
        }
    }
    else
    {
        ret = -1;
    }

    if(ret != -1)
    {
        pBN->length = k;
    }

    return ret;
}

int32_t BN_Dec2Bignum(__OUT BIGNUM_t* pBN, __IN char* str)
{
    return -1;
}

char* BN_Bignum2Hex(__IN BIGNUM_t* pBN)
{
    int32_t i, j, k;
    char temp;

    for(i = pBN->length, k = 0; i > -1; i -= 1, k += 8)
    {
        for(j = 0; j < 8; j += 1)
        {
            temp = (char)(pBN->pWord[i] >> (28 - (j * 4))) & 0xF;
            if((temp >= 0) && (temp <= 9))
            {
                gASCBuff[k + j] = temp + '0';
            }
            else
            {
                gASCBuff[k + j] = temp - 0xA + 'A';
            }
        }
    }
    gASCBuff[k] = '\0';

    return gASCBuff;
}

char* BN_Bignum2Dec(__IN BIGNUM_t* pBN)
{
    return (char*)0;
}


/*
 **************************************************************************************************** 
 *                                      LOCAL DEFINITION
 ***************************************************************************************************
 */
static int32_t BN_strlen(__IN char* str)
{
    volatile int32_t ret;

    for(ret = 0; str[ret] != '\0'; ret += 1)
    {
        continue;
    }
    
    return (ret - 1);
}

static int32_t BN_Asc2Digit(__IN char asc)
{
    int32_t ret;

    if((asc >= '0') && (asc <= '9'))
    {
        ret = (int32_t)(asc - '0');
    }
    else if((asc >= 'a') && (asc <= 'f'))
    {
        ret = (int32_t)(asc - 'a') + 0xA;
    }
    else if((asc >= 'A') && (asc <= 'F'))
    {
        ret = (int32_t)(asc - 'A') + 0xA;
    }
    else
    {
        ret = -1;
    }

    return ret;
}


/* END OF FILE  */
