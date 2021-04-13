#include <stdio.h>
#include "bignum_conv.h"

int main(void)
{
    int ret;
    char* str;
    BIGNUM_t BN;
    uint32_t buf[1024];

    BN.capacity = 1024;
    BN.pWord    = buf;

    ret = BN_Hex2Bignum(&BN, "123456789ABCDEF");

    str = BN_Bignum2Hex(&BN);
    printf("%s\n", str);

    return 0;
}
