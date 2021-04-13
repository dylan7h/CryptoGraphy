/*
 **************************************************************************************************** 
 *                                      INCLUDE
 ***************************************************************************************************
 */
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
static int32_t BN_strlen(char* str);
static int32_t BN_Asc2Digit(char asc);
static void BN_Clear(BIGNUM_t* pBN);

/*
 **************************************************************************************************** 
 *                                      EXTERN DEFINITION
 ***************************************************************************************************
 */

int32_t BN_Asc2Bignum(BIGNUM_t* pBN, char* str)
{

}

int32_t BN_Hex2Bignum(BIGNUM_t* pBN, char* str)
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

int32_t BN_Dec2Bignum(BIGNUM_t* pBN, char* str)
{

}

char* BN_Bignum2Hex(BIGNUM_t* pBN)
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

char* BN_Bignum2Dex(BIGNUM_t* pBN)
{

}


/*
 **************************************************************************************************** 
 *                                      LOCAL DEFINITION
 ***************************************************************************************************
 */
static int32_t BN_strlen(char* str)
{
    volatile int32_t ret;

    for(ret = 0; str[ret] != '\0'; ret += 1)
    {
        continue;
    }
    
    return (ret - 1);
}

static int32_t BN_Asc2Digit(char asc)
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

static void BN_Clear(BIGNUM_t* pBN)
{
    int32_t i;

    for(i = 0; i < pBN->capacity; i += 1U)
    {
        pBN->pWord[i] = 0U;
    }
}


/* END OF FILE  */
