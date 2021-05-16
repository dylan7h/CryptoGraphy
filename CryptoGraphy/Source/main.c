#include <stdio.h>
#include "bignum_conv.h"
#include "bignum_util.h"
#include "bignum_add.h"
#include "bignum_mul.h"
#include "bignum_div.h"
#include "bignum_debug.h"

#define ENABLE          (1U)
#define DISABLE         (0U)

#define BN_ADD_DEMO     DISABLE
#define BN_MUL_DEMO     DISABLE
#define BN_DIV_DEMO     ENABLE

int main(void)
{
    char* str;
    BIGNUM_t BN_Op1;
    BIGNUM_t BN_Op2;
    BIGNUM_t BN_Temp;
    BIGNUM_t BN_Result;

    uint32_t buf_Op1[1024];
    uint32_t buf_Op2[1024];
    uint32_t buf_temp[1024];
    uint32_t buf_Result[1024];

    BN_Op1.negative = 0;
    BN_Op2.negative = 0;

    BN_Op1.capacity     = sizeof(buf_Op1) / sizeof(uint32_t);
    BN_Op2.capacity     = sizeof(buf_Op2) / sizeof(uint32_t);
    BN_Temp.capacity    = sizeof(buf_temp) / sizeof(uint32_t);
    BN_Result.capacity  = sizeof(buf_Result) / sizeof(uint32_t);
    
    BN_Op1.pWord    = buf_Op1;
    BN_Op2.pWord    = buf_Op2;
    BN_Temp.pWord   = buf_temp;
    BN_Result.pWord = buf_Result;
#if 0
    (void)BN_Asc2Bignum(&BN_Op1, "0x123456789ABCDEF");
    (void)BN_Asc2Bignum(&BN_Op2, "0x89ABCDEF");
#else
    (void)BN_Asc2Bignum(&BN_Op1, "0x3126789457237892349789");
    (void)BN_Asc2Bignum(&BN_Op2, "0x87896427893242789");
#endif

#if (BN_ADD_DEMO == ENABLE)
    (void)BN_Add(&BN_Result, &BN_Op1, &BN_Op2);
    str = BN_Bignum2Hex(&BN_Result);
    printf("0x%s\n", str);

    (void)BN_Sub(&BN_Result, &BN_Op1, &BN_Op2);
    str = BN_Bignum2Hex(&BN_Result);
    printf("0x%s\n", str);
#endif

#if (BN_MUL_DEMO == ENABLE)
    (void)BN_Mul(&BN_Result, &BN_Op1, &BN_Op2);
    str = BN_Bignum2Hex(&BN_Result);
    printf("0x%s\n", str);
#endif

#if (BN_DIV_DEMO == ENABLE)
    BN_Div(&BN_Result, &BN_Temp, &BN_Op1, &BN_Op2);
#endif

    return 0;
}

