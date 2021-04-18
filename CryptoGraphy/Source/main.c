#include <stdio.h>
#include "bignum_conv.h"
#include "bignum_util.h"
#include "bignum_add.h"

int main(void)
{
    int ret;
    char* str;
    BIGNUM_t BN_Op1;
    BIGNUM_t BN_Op2;
    BIGNUM_t BN_Result;
    uint32_t buf_Op1[1024];
    uint32_t buf_Op2[1024];
    uint32_t buf_Result[1024];

    BN_Op1.negative = 0;
    BN_Op2.negative = 0;

    BN_Op1.capacity     = sizeof(buf_Op1) / sizeof(uint32_t);
    BN_Op2.capacity     = sizeof(buf_Op2) / sizeof(uint32_t);
    BN_Result.capacity  = sizeof(buf_Result) / sizeof(uint32_t);
    
    BN_Op1.pWord    = buf_Op1;
    BN_Op2.pWord    = buf_Op2;
    BN_Result.pWord = buf_Result;

    (void)BN_Asc2Bignum(&BN_Op1, "0x123456789ABCDEF");
    (void)BN_Asc2Bignum(&BN_Op2, "0x89ABCDEF");

    (void)BN_Add(&BN_Result, &BN_Op1, &BN_Op2);
    str = BN_Bignum2Hex(&BN_Result);
    printf("0x%s\n", str);

    (void)BN_Sub(&BN_Result, &BN_Op1, &BN_Op2);
    str = BN_Bignum2Hex(&BN_Result);
    printf("0x%s\n", str);

    return 0;
}
