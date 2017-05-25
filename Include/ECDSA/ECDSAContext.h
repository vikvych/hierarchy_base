#ifndef HIERARCHY_ECDSA_CONTEXT_H
#define HIERARCHY_ECDSA_CONTEXT_H

#include "../EC/ECLib.h"

typedef struct {
    ECCryptoModeT ECCryptoType;

    BN_CTX *BigNumberContext;
    BIGNUM *p;
    BIGNUM *a;
    BIGNUM *b;
    BIGNUM *N;
    EC_GROUP *Group;
    EC_POINT *P;
    BIGNUM *x;
    BIGNUM *y;
    BIGNUM *z;
    EC_POINT *M1;
    BIGNUM *M2;
    BIGNUM *PrivateKey;
    EC_POINT *PublicKey;
    BIGNUM *Data;
    BIGNUM *R;
    BIGNUM *S;

} ECDSAContextT;

ECContextT *ECGamalContextInit(ECCryptoModeT ECCryptoType);
void ECContextDestroy(void *ECContexta);


#endif
