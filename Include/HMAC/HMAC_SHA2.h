#ifndef HIERARCHY_HMAC_SHA256_H
#define HIERARCHY_HMAC_SHA256_H

#include "../SHA2/SHA2Lib.h"

typedef struct {
    SHA224ContextT InsideContext;
    SHA224ContextT OutsideContext;

    SHA224ContextT InsideReinitContext;
    SHA224ContextT OutsideReinitContext;

    ByteT InputPaddingBlock[SHA224_BLOCK_SIZE];
    ByteT OutputPaddingBlock[SHA224_BLOCK_SIZE];
} HMAC_SHA224ContextT;

typedef struct {
    SHA256ContextT InsideContext;
    SHA256ContextT OutsideContext;

    SHA256ContextT InsideReinitContext;
    SHA256ContextT OutsideReinitContext;

    ByteT InputPaddingBlock[SHA256_BLOCK_SIZE];
    ByteT OutputPaddingBlock[SHA256_BLOCK_SIZE];
} HMAC_SHA256ContextT;

typedef struct {
    SHA384ContextT InsideContext;
    SHA384ContextT OutsideContext;

    SHA384ContextT InsideReinitContext;
    SHA384ContextT OutsideReinitContext;

    ByteT InputPaddingBlock[SHA384_BLOCK_SIZE];
    ByteT OutputPaddingBlock[SHA384_BLOCK_SIZE];
} HMAC_SHA384ContextT;

typedef struct {
    SHA512ContextT InsideContext;
    SHA512ContextT OutsideContext;

    SHA512ContextT InsideReinitContext;
    SHA512ContextT OutsideReinitContext;

    ByteT InputPaddingBlock[SHA512_BLOCK_SIZE];
    ByteT OutputPaddingBlock[SHA512_BLOCK_SIZE];
} HMAC_SHA512ContextT;

void HMAC_SHA224Init(HMAC_SHA224ContextT *Context,
                     const ByteT *Key,
                     SizeT KeySize);

void HMAC_SHA224Reinit(HMAC_SHA224ContextT *Context);

void HMAC_SHA224Update(HMAC_SHA224ContextT *Context,
                       const ByteT *Data,
                       SizeT DataSize);

void HMAC_SHA224Final(HMAC_SHA224ContextT *Context,
                      ByteT *Digest,
                      SizeT DigestSize);

void HMAC_SHA224Digest(const ByteT *Key,
                       SizeT KeySize,
                       const ByteT *Data,
                       SizeT DataSize,
                       ByteT *Digest,
                       SizeT DigestSize);

void HMAC_SHA256Init(HMAC_SHA256ContextT *Context,
                     const ByteT *Key,
                     SizeT KeySize);

void HMAC_SHA256Reinit(HMAC_SHA256ContextT *Context);

void HMAC_SHA256Update(HMAC_SHA256ContextT *Context,
                       const ByteT *Data,
                       SizeT DataSize);

void HMAC_SHA256Final(HMAC_SHA256ContextT *Context,
                      ByteT *Digest,
                      SizeT DigestSize);

void HMAC_SHA256Digest(const ByteT *Key,
                       SizeT KeySize,
                       const ByteT *Data,
                       SizeT DataSize,
                       ByteT *Digest,
                       SizeT DigestSize);

void HMAC_SHA384Init(HMAC_SHA384ContextT *Context,
                     const ByteT *Key,
                     SizeT KeySize);

void HMAC_SHA384Reinit(HMAC_SHA384ContextT *Context);

void HMAC_SHA384Update(HMAC_SHA384ContextT *Context,
                       const ByteT *Data,
                       SizeT DataSize);

void HMAC_SHA384Final(HMAC_SHA384ContextT *Context,
                      ByteT *Digest,
                      SizeT DigestSize);

void HMAC_SHA384Digest(const ByteT *Key,
                       SizeT KeySize,
                       const ByteT *Data,
                       SizeT DataSize,
                       ByteT *Digest,
                       SizeT DigestSize);

void HMAC_SHA512Init(HMAC_SHA512ContextT *Context,
                     const ByteT *Key,
                     SizeT KeySize);

void HMAC_SHA512Reinit(HMAC_SHA512ContextT *Context);

void HMAC_SHA512Update(HMAC_SHA512ContextT *Context,
                       const ByteT *Data,
                       SizeT DataSize);

void HMAC_SHA512Final(HMAC_SHA512ContextT *Context,
                      ByteT *Digest,
                      SizeT DigestSize);

void HMAC_SHA512Digest(const ByteT *Key,
                       SizeT KeySize,
                       const ByteT *Data,
                       SizeT DataSize,
                       ByteT *Digest,
                       SizeT DigestSize);

void HMAC_SHA256(uint8_t *Key,
                 uint16_t KeyByteLength,
                 uint8_t *Data,
                 uint32_t DataByteLength,
                 uint8_t* OutputData);

#endif
