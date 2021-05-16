#include <stdio.h>
#include "bignum_debug.h"

void BN_Dump32(__IN  char strTitle[], __IN BIGNUM_t* pBignum)
{
    const int32_t row = 8;
    volatile int32_t i;
    volatile int32_t ret;

    puts("====================== DUMP32 ================================");
    printf("    >> Title    : %s\n", strTitle);
    printf("    >> Capacity : %d [ word ]\n", pBignum->capacity);
    printf("    >> Length   : %d [ word ]\n", pBignum->length);
    printf("==============================================================");
    for(i = 0; i < pBignum->length; i += 1)
    {
        ret = i % row;
        if(ret == 0)
        {
            ret = i / row;
            printf("\n  0x%08X: ", ret * row);
        }

        printf("0x%08X  ", pBignum->pWord[i]);
    }
    puts("\n==============================================================\n");
}

void BN_Dump8(__IN BIGNUM_t* pBignum)
{

}
