#ifndef HIERARCHY_HMAC_SHA1_H
#define HIERARCHY_HMAC_SHA1_H

#include "../SHA1/SHA1Lib.h"

typedef struct {
    SHA1ContextT InsideContext;
    SHA1ContextT OutsideContext;

    SHA1ContextT InsideReinitContext;
    SHA1ContextT OutsideReinitContext;

    ByteT InputPaddingBlock[SHA_BLOCK_SIZE];
    ByteT OutputPaddingBlock[SHA_BLOCK_SIZE];
} HMAC_SHA1ContextT;

void HMAC_SHA1Init(HMAC_SHA1ContextT *Context,
                   const ByteT *Key,
                   SizeT KeySize);

void HMAC_SHA1Reinit(HMAC_SHA1ContextT *Context);

void HMAC_SHA1Update(HMAC_SHA1ContextT *Context,
                     const ByteT *Data,
                     SizeT DataSize);

void HMAC_SHA1Final(HMAC_SHA1ContextT *Context,
                      ByteT *Digest,
                      SizeT DigestSize);

void HMAC_SHA1Digest(const ByteT *Key,
                       SizeT KeySize,
                       const ByteT *Data,
                       SizeT DataSize,
                       ByteT *Digest,
                       SizeT DigestSize);

#endif
