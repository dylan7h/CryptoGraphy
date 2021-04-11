#ifndef __BIGNUM_CONV__H__
#define __BIGNUM_CONV__H__

#include "bignum_types.h"

extern int32_t BN_Asc2Bignum(BIGNUM_t* pBN, char* str);

extern int32_t BN_Hex2Bignum(BIGNUM_t* pBN, char* str);
extern int32_t BN_Dec2Bignum(BIGNUM_t* pBN, char* str);

extern char* BN_Bignum2Hex(BIGNUM_t* pBN);
extern char* BN_Bignum2Dex(BIGNUM_t* pBN);


#endif  /* !__BIGNUM_CONV__H__ */
