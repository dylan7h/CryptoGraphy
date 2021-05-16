
#include "bignum_util.h"
#include "bignum_div.h"


/* 
    Example)
                     ┌────────────────────────────────────
     0x2312_89ABCDEF │0x1234567_89ABCDEF_01234567_89ABCDEF

    step 1)
    0x1234567_89ABCDEF_1234567_89ABCDEF ÷ 0x2312_00000000 = 0x84E_00000000_00000000

                                  0x84E_00000000_00000000
                    ┌────────────────────────────────────
    0x2312_00000000 │0x1234567_89ABCDEF_01234567_89ABCDEF
 
 
    0x00000000_89ABCDEF × 0x84E_00000000_00000000 =  0x50C836D2_00000000_00000000
 */

int32_t BN_Div(__OUT BIGNUM_t* result, __INOUT BIGNUM_t* temp, __IN BIGNUM_t* op1, __IN BIGNUM_t* op2)
{
    int32_t ret;
    BIGNUM_t* pNumerator;   /* 분자 */
    BIGNUM_t* pDenominator; /* 분모 */

    ret = BN_ucmp(op1, op2);
    if(ret >= 0)
    {
        pDenominator = op1;
        pNumerator = op2;
    }
    else if(ret < 0)
    {
        pDenominator = op2;
        pNumerator = op1;
    }
    
    if(ret != 0)
    {

    }
    else
    {
        BN_Clear(result);
        result->pWord[0] = 1U;
        ret = 0;
    }

    return ret;
}


