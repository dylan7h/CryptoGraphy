#ifndef __BIGNUM_UTIL__H__
#define __BIGNUM_UTIL__H__

#include "bignum_types.h"

extern int32_t  BN_ucmp(__IN BIGNUM_t* op1, __IN BIGNUM_t * op2);
extern void     BN_Clear(__INOUT BIGNUM_t* pBN);

#endif  /* !__BIGNUM_UTIL__H__ */
