#ifndef __BIGNUM_ADD__H__
#define __BIGNUM_ADD__H__

#include "bignum_types.h"

extern int32_t BN_Add(__OUT BIGNUM_t* result, __IN BIGNUM_t* op1, __IN BIGNUM_t* op2);
extern int32_t BN_Sub(__OUT BIGNUM_t* result, __IN BIGNUM_t* op1, __IN BIGNUM_t* op2);

#endif  /* !__BIGNUM_ADD__H__ */
