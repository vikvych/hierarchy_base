/*#ifndef HIERARCHY_EC_BOOST_H
#define HIERARCHY_EC_BOOST_H

#include "EC.h"

typedef enum ECCryptoBoostLevel {
    EC_BOOST_LEVEL1 = 1,
    EC_BOOST_LEVEL4 = 2,
    EC_BOOST_LEVEL8 = 3
} ECCryptoBoostLevelT;

typedef struct ECCryptoBoostPointData {
    int nBits;
    EC_POINT *BoostData[530][256];
} ECCryptoBoostPointDataT;

int ECCryptoBoostSetNBits(ECCryptoBoostPointDataT *BoostStruct,  int nBits);

int ECCryptoBoostInit(const EC_GROUP *ECGroup,
               ECCryptoBoostPointDataT *BoostStruct,
               BN_CTX *BIGNUMContext,
               ECCryptoBoostLevelT BoostLevel);

int precompute(  const EC_GROUP *group,
                 void *precomputedData,
                 const EC_POINT *base,
                 BN_CTX *ctx,
                 const BIGNUM *n,
                 ECCryptoBoostLevelT BoostLevel);

int precomputedPrecompute(const EC_GROUP *group,
                          void* alreadyPrecomputedData,
                          void *nextPrecomputedData,
                          BN_CTX *ctx,
                          enum ECCryptoBoostLevel startOptLevel);

int precomputedScalarMult(EC_POINT *r, const EC_GROUP *group, void *precomputedData, const BIGNUM *n, BN_CTX *ctx, enum ECCryptoBoostLevel optLevel);
void precomputeBase1(ECContextT* cryptoCTX);
void precomputeBase4(ECContextT* cryptoCTX);
void precomputeBase8(ECContextT* cryptoCTX);

void precomputePublic1(ECContextT* cryptoCTX);
void precomputePublic4(ECContextT* cryptoCTX);
void precomputePublic8(ECContextT* cryptoCTX);

void ladderedPrecomputeBase(ECContextT* cryptoCTX);
void ladderedPrecomputePublic(ECContextT* cryptoCTX);


void ECContextEncryptFast(ECContextT* ECContext,
                          ECCryptoBoostLevelT BoostLevel);

int ECContextSignatureStampFast(ECContextT* ECContext, enum ECCryptoBoostLevel optLevel);
bool ECContextSignatureVerifyFast(ECContextT* ECContext, enum ECCryptoBoostLevel optLevel);

#endif*/
/*ECCryptoBoostPointDataT *BoostPoints1;
ECCryptoBoostPointDataT *BoostPoints4;
ECCryptoBoostPointDataT *BoostPoints8;
ECCryptoBoostPointDataT *BoostPublic1;
ECCryptoBoostPointDataT *BoostPublic4;
ECCryptoBoostPointDataT *BoostPublic8;*/

#ifndef HIERARCHY_EC_BOOST_H
#define HIERARCHY_EC_BOOST_H

#include <stdlib.h>

extern void *NONULLIOS9;

#endif
