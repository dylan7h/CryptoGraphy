#ifndef __BIGNUM_MUL__H__
#define __BIGNUM_MUL__H__

#include "bignum_types.h"

extern int32_t BN_Mul(__OUT BIGNUM_t* result, __IN BIGNUM_t* op1, __IN BIGNUM_t* op2);

#endif  /* !__BIGNUM_MUL__H__ */
