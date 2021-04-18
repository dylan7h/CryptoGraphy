#ifndef __BIGNUM_ADD__H__
#define __BIGNUM_ADD__H__

#include "bignum_types.h"

extern int32_t BN_Add(BIGNUM_t* result, BIGNUM_t* op1, BIGNUM_t* op2);
extern int32_t BN_Sub(BIGNUM_t* result, BIGNUM_t* op1, BIGNUM_t* op2);

#endif  /* !__BIGNUM_ADD__H__ */
