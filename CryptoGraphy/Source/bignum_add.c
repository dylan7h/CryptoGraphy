/*
 **************************************************************************************************** 
 *                                      INCLUDE
 ***************************************************************************************************
 */
#include "bignum_util.h"
#include "bignum_add.h"



/*
 **************************************************************************************************** 
 *                                      LOCAL DECLARATION
 ***************************************************************************************************
 */
static int32_t BN_uadd(BIGNUM_t* result, BIGNUM_t* op1, BIGNUM_t* op2);
static int32_t BN_usub(BIGNUM_t* result, BIGNUM_t* op1, BIGNUM_t* op2);


/*
 **************************************************************************************************** 
 *                                      EXTERN DEFINITION
 ***************************************************************************************************
 */
int32_t BN_Add(BIGNUM_t* result, BIGNUM_t* op1, BIGNUM_t* op2)
{
    int32_t ret, cmp_ret;

    if(op1->negative == op2->negative)
    {
        /* result = op1 + op2 */
        ret = BN_uadd(result, op1, op2);
        result->negative = op1->negative;
    }
    else
    {
        cmp_ret = BN_ucmp(op1, op2);
        if(cmp_ret > 0)
        {
            /* result   = op1 + (-op2)  |   (-op1) + op2
                        = op1 - op2     |   -(op1 - op2)
            */
            ret = BN_usub(result, op1, op2);
            result->negative = op1->negative;
        }
        else if(cmp_ret < 0)
        {
            /* result   = (-op2) + op1  |   op2 + (-op1)   
                        = -(op2 - op1)  |   op2 - op1
            */
            ret = BN_usub(result, op2, op1);
            result->negative = op2->negative;
        }
        else
        {
            /* result = op1 - op2 = 0 */
            BN_Clear(result);
            result->negative = 0;
            result->length = 0;
            ret = 0;
        }
    }

    return ret;
}

int32_t BN_Sub(BIGNUM_t* result, BIGNUM_t* op1, BIGNUM_t* op2)
{
    int32_t ret, cmp_ret;

    if(op1->negative != op2->negative)
    {
        /* result   = (-op1) - op2 | op1 - (-op2) 
                    = -(op1 + op2) | op1 + op2
        */
        result->negative = op1->negative;
        ret = BN_uadd(result, op1, op2);
    }
    else
    {
        cmp_ret = BN_ucmp(op1, op2);
        if(cmp_ret > 0)
        {
            /* result   = op1 - op2 | (-op1) - (-op2)
                                    |  -op1 + op2
                                    |  -(op1 - op2)
            */
            ret = BN_usub(result, op1, op2);
            result->negative = op1->negative;
        }
        else if(cmp_ret < 0)
        {
            /* result   = op2 - op1 | (-op2) - (-op1)
                                    |  -op2 + op1
                                    |  -(op2 - op1)
            */
            ret = BN_usub(result, op2, op1);
            result->negative = op2->negative;
        }
        else
        {
            /* result = op1 - op2 = 0 */
            BN_Clear(result);
            result->length = 0;
            result->negative = 0;
            ret = 0;
        }
    }

    return ret;
}


/*
 **************************************************************************************************** 
 *                                      LOCAL DEFINITION
 ***************************************************************************************************
 */
int32_t BN_uadd(BIGNUM_t* result, BIGNUM_t* op1, BIGNUM_t* op2)
{
    int32_t i;
    uint32_t carry = 0U;

    for(i = 0; i <= op1->length; i += 1)
    {
        result->pWord[i] = op1->pWord[i] + op2->pWord[i] + carry;
        if(result->pWord[i] < op1->pWord[i])
        {
            carry = 1U;
        }
        else
        {
            carry = 0U;
        }
    }

    if((result->capacity > (op1->length + 1)) && (carry != 0))
    {
        result->pWord[i] = 1U;
        result->length = i;
    }
    else
    {
        result->length = i - 1;
    }

    return 0;
}

int32_t BN_usub(BIGNUM_t* result, BIGNUM_t* op1, BIGNUM_t* op2)
{
    int32_t i;
    uint32_t carry = 0U;

    for(i = 0; i <= op1->length; i += 1)
    {
        result->pWord[i] = op1->pWord[i] - op2->pWord[i] - carry;
        if(result->pWord[i] > op1->pWord[i])
        {
            carry = 1U;
        }
        else
        {
            carry = 0U;
        }
    }

    result->length = 0;
    for(i = op1->length; i > 0; i -= 1)
    {
        if(result->pWord[i] != 0)
        {
            result->length = i;
            break;
        }
    }

    return 0;
}

/* END OF FILE  */
