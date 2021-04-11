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
    int32_t IndexOfWord;
    int32_t i;
    volatile uint8_t shifer;

    length = BN_strlen(str);
    if(length > 0)
    {
        for(i = 0; i < length; i += 1)
        {
            digit = BN_Asc2Digit(str[i]);
            if(digit != -1)
            {
                IndexOfWord = i / 4;
                if(IndexOfWord >= pBN->capacity)
                {
                    ret = -1;
                    break;
                }

                shifer = (uint8_t)(i % 4);
                pBN->pWord[IndexOfWord] |= ((uint32_t)digit << (uint8_t)(shifer * 8U));
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
        pBN->length = IndexOfWord;
    }

    return ret;
}

int32_t BN_Dec2Bignum(BIGNUM_t* pBN, char* str)
{

}

char* BN_Bignum2Hex(BIGNUM_t* pBN)
{
    int32_t i, j;
    int32_t AscIdx;
    char temp;

    for(i = pBN->length; i > -1; i -= 1)
    {
        for(j = 0; j < 4; j += 1)
        {
            AscIdx  = (i * 4) + j;
            temp    = (char)((pBN->pWord[i] >> (j * 8)) & 0xFF);
            if((temp >= '0') && (temp <= '9'))
            {
                gASCBuff[AscIdx] = (temp + '0');
            }
            else if((temp >= 'a') && (temp <= 'f'))
            {
                gASCBuff[AscIdx] = (temp + 'a');
            }
            else if((temp >= 'A') && (temp <= 'F'))
            {
                gASCBuff[AscIdx] = (temp + 'A');
            }
        }
    }

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
    
    return ret;
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
        ret = (int32_t)(asc - 'a');
    }
    else if((asc >= 'A') && (asc <= 'F'))
    {
        ret = (int32_t)(asc - 'A');
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
