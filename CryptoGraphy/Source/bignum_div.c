
#include "bignum_util.h"
#include "bignum_div.h"

#include "bignum_debug.h"

/* 
    Example)
                     ┌────────────────────────────────────
     0x2312_89ABCDEF │0x1234567_89ABCDEF_01234567_89ABCDEF

    step 1)
    0x1234567_89ABCDEF_1234567_89ABCDEF ÷ 0x2312_00000000 = 0x84E_00000000_00000000

                                  0x84E_00000000_00000000
                    ┌────────────────────────────────────
    0x2312_00000000 │0x1234567_89ABCDEF_01234567_89ABCDEF
    
    1, 3,
 
    0x00000000_89ABCDEF × 0x84E_00000000_00000000 =  0x50C836D2_00000000_00000000
 */

int32_t BN_Div(__OUT BIGNUM_t* result, __INOUT BIGNUM_t* temp, __IN BIGNUM_t* op1, __IN BIGNUM_t* op2)
{

    int32_t ret;
    BIGNUM_t* pNumerator;   /* 분자 */
    BIGNUM_t* pDenominator; /* 분모 */

    volatile int32_t    WordIndex;
    volatile int32_t    NumeratorIndex;
    volatile int32_t    DenominatorIndex;
    int32_t             DiffWordIndex;

    ret = BN_ucmp(op1, op2);
    if(ret >= 0)
    {
        pDenominator    = op1;
        pNumerator      = op2;
    }
    else
    {
        pDenominator    = op2;
        pNumerator      = op1;
    }
    
    if(ret != 0)
    {
        ret = BN_ucpy(temp, pDenominator);
        if(ret == 0)
        {
            /* 
                Example)
                    pNumerator->length      : 3
                    pDenominator->length    : 6
                    DiffWordIndex           : 3
                                                          ┌──────────────────────────────────────────────────────────────────
                    0xcb551d12_9734d12b_c4526089_6ac470dd │0xc16dc643_ac04cb97_efa9154a_9c2ce981_7ce02436_3cacd424_3498c117
            
             */

            DiffWordIndex = pDenominator->length - pNumerator->length;
            for(WordIndex = DiffWordIndex; WordIndex > -1; WordIndex -= 1)
            {

            }
        }
    }
    else
    {
        BN_Clear(result);
        result->pWord[0] = 1U;
        ret = 0;
    }

    return ret;
}


