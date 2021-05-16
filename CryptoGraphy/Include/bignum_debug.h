#ifndef __BIGNUM_DEBUG__H__
#define __BIGNUM_DEBUG__H__

#include "bignum_types.h"

extern void BN_Dump32(__IN  char strTitle[], __IN BIGNUM_t* pBignum);
extern void BN_Dump8(__IN BIGNUM_t* pBignum);

#endif  /* !__BIGNUM_DEBUG__H__ */
