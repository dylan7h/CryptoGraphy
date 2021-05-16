#ifndef __BIGNUM_DIV__H__
#define __BIGNUM_DIV__H__

#include "bignum_types.h"

extern int32_t BN_Div(__OUT BIGNUM_t* result, __INOUT BIGNUM_t* temp, __IN BIGNUM_t* op1, __IN BIGNUM_t* op2);

#endif  /* !__BIGNUM_DIV__H__ */
