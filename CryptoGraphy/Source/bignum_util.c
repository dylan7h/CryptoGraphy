/*
 **************************************************************************************************** 
 *                                      INCLUDE
 ***************************************************************************************************
 */
#include "bignum_util.h"


/*
 **************************************************************************************************** 
 *                                      LOCAL DECLARATION
 ***************************************************************************************************
 */


/*
 **************************************************************************************************** 
 *                                      EXTERN DEFINITION
 ***************************************************************************************************
 */
int32_t BN_ucmp(__IN BIGNUM_t* op1, __IN BIGNUM_t * op2)
{
    int32_t ret;

    if(op1->length > op2->length)
    {
        ret = 1;
    }
    else if(op1->length < op2->length)
    {
        ret = -1;
    }
    else
    {
        if(op1->pWord[op1->length] > op2->pWord[op2->length])
        {
            ret = 1;
        }
        else if(op1->pWord[op1->length] < op2->pWord[op2->length])
        {
            ret = -1;
        }
        else
        {
            ret = 0;
        }
    }

    return ret;
}

int32_t BN_ucpy(__OUT BIGNUM_t* pDst, __IN BIGNUM_t * pSrc)
{
    volatile int32_t i, j;
    int32_t ret;

    if(pDst->capacity >= pSrc->capacity)
    {
        ret = 0;

        for(i = 0; i <= pSrc->length; i += 1)
        {
            pDst->pWord[i] = pSrc->pWord[i];
        }

        if(pDst->capacity > pSrc->capacity)
        {
            for(j = i; j < pDst->capacity; j += 1)
            {
                pDst->pWord[i] = 0U;
            }
        }

        pDst->negative = pSrc->negative;
        pDst->length = pSrc->length;
    }
    else
    {
        ret = -1;
    }

    return ret;
}

void BN_Clear(__INOUT BIGNUM_t* pBN)
{
    int32_t i;

    for(i = 0; i < pBN->capacity; i += 1U)
    {
        pBN->pWord[i] = 0U;
    }

    pBN->length     = 0;
    pBN->negative   = 0;
}

/*
 **************************************************************************************************** 
 *                                      LOCAL DEFINITION
 ***************************************************************************************************
 */


/* END OF FILE  */
