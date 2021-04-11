#ifndef __BIGNUM_TYPES__H__
#define __BIGNUM_TYPES__H__

#include <stdint.h>

typedef struct bignumber_st
{
    uint32_t*   pWord;
    int32_t     capacity;
    int32_t     length;
    int32_t     negative;
} BIGNUM_t;

#endif  /* !__BIGNUM_TYPES__H__ */