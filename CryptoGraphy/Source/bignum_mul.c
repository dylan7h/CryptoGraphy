/*
 **************************************************************************************************** 
 *                                      INCLUDE
 ***************************************************************************************************
 */
#include "bignum_util.h"
#include "bignum_mul.h"


/*
 **************************************************************************************************** 
 *                                      LOCAL DECLARATION
 ***************************************************************************************************
 */
static int32_t BN_AddResult(__OUT BIGNUM_t* result, __IN uint64_t u64_result, __IN int32_t EntryDegree);


/*
 **************************************************************************************************** 
 *                                      EXTERN DEFINITION
 ***************************************************************************************************
 */
/* 
    Example)

            0x1234567_89ABCDEF
      x             0x89ABCDEF
    ----------------------------
    0x9ca39e_13579bdf_90f2a521
    
    step 1)    
    
            0x0000000_89ABCDEF
      x             0x89ABCDEF
    ----------------------------
           0x4a0955b6_90f2a521
    
    step 2)
            0x1234567_00000000
      x             0x89ABCDEF
    ----------------------------
    0x9ca39d_c94e4629_00000000


    step 3)
      0x9ca39d_c94e4629_00000000
    +        0x4a0955b6_90f2a521
    ----------------------------
      0x9ca39e_13579bdf_90f2a521
 */

int32_t BN_Mul(__OUT BIGNUM_t* result, __IN BIGNUM_t* op1, __IN BIGNUM_t* op2)
{
    int32_t ret = 0;

    volatile uint64_t u64_result, u64_op1, u64_op2;
    volatile int32_t i, j;

    BN_Clear(result);
    for(i = 0; i <= op2->length; i += 1)
    {
        u64_op2 = op2->pWord[i];
        if(u64_op2 != 0U)
        {
            for(j = 0; j <= op1->length; j += 1)
            {
                u64_op1 = op1->pWord[j];
                if(u64_op1 != 0U)
                {
                    u64_result  = u64_op1 * u64_op2;
                    result->length = BN_AddResult(result, u64_result, i + j);
                }
            }
        }
    }

    return ret;
}


/*
 **************************************************************************************************** 
 *                                      LOCAL DEFINITION
 ***************************************************************************************************
 */
int32_t BN_AddResult(__OUT BIGNUM_t* result, __IN uint64_t u64_op, __IN int32_t EntryDegree)
{
    volatile uint64_t u64_result, u64_op1, u64_op2;
    volatile int32_t i;

    u64_op1 = u64_op;
    for(i = EntryDegree; i < result->capacity; i += 1)
    {
        u64_op2 = result->pWord[i];
        u64_result = u64_op1 + u64_op2;

        result->pWord[i] = (uint32_t)(u64_result & 0xFFFFFFFFU);

        u64_op1 = u64_result >> 32U;
        if(u64_op1 == 0U)
        {
            break;
        }
    }

    return i;
}

/* END OF FILE  */
