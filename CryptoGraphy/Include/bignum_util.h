#ifndef __BIGNUM_UTIL__H__
#define __BIGNUM_UTIL__H__

#include "bignum_types.h"

extern int32_t  BN_ucmp(BIGNUM_t* a, BIGNUM_t * b);
extern void     BN_Clear(BIGNUM_t* pBN);

#endif  /* !__BIGNUM_UTIL__H__ */
