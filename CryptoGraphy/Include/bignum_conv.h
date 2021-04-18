#ifndef __BIGNUM_CONV__H__
#define __BIGNUM_CONV__H__

#include "bignum_types.h"

extern int32_t BN_CreateInstance(__OUT BIGNUM_t* pBN, __IN uint32_t* pBuff, __IN int32_t capacity);

extern int32_t BN_Asc2Bignum(__OUT BIGNUM_t* pBN, __IN char* str);

extern int32_t BN_Hex2Bignum(__OUT BIGNUM_t* pBN, __IN char* str);
extern int32_t BN_Dec2Bignum(__OUT BIGNUM_t* pBN, __IN char* str);

extern char* BN_Bignum2Hex(__IN BIGNUM_t* pBN);
extern char* BN_Bignum2Dec(__IN BIGNUM_t* pBN);


#endif  /* !__BIGNUM_CONV__H__ */
