#ifndef HIERARCHY_SHA2_H
#define HIERARCHY_SHA2_H

#include "../Error/ErrorLib.h"
#include "../Memory/MemoryLib.h"

#define SHA224_DIGEST_SIZE (224 / 8)
#define SHA256_DIGEST_SIZE (256 / 8)
#define SHA384_DIGEST_SIZE (384 / 8)
#define SHA512_DIGEST_SIZE (512 / 8)

#define SHA256_BLOCK_SIZE (512 / 8)
#define SHA512_BLOCK_SIZE (1024 / 8)
#define SHA384_BLOCK_SIZE SHA512_BLOCK_SIZE
#define SHA224_BLOCK_SIZE SHA256_BLOCK_SIZE

typedef struct {
    SizeT TotalLength;
    SizeT Length;
    ByteT Buffer[2 * SHA256_BLOCK_SIZE];
    DWordT State[8];
} SHA256ContextT;

typedef struct {
    SizeT TotalLength;
    SizeT Length;
    ByteT Buffer[2 * SHA512_BLOCK_SIZE];
    QWordT State[8];
} SHA512ContextT;

typedef SHA512ContextT SHA384ContextT;
typedef SHA256ContextT SHA224ContextT;

void SHA224Init(SHA224ContextT *Context);

void SHA224Update(SHA224ContextT *Context, const ByteT *Data, SizeT Size);

void SHA224Final(ByteT *Digest, SHA224ContextT *Context);

void SHA224Digest(const ByteT *Data, SizeT Size, ByteT *Digest);

void SHA256Init(SHA256ContextT *Context);

void SHA256Update(SHA256ContextT *Context, const ByteT *Data, SizeT Size);

void SHA256Final(ByteT *Digest, SHA256ContextT *Context);

void SHA256Digest(const ByteT *Data, SizeT Size, ByteT *Digest);

void SHA384Init(SHA384ContextT *Context);

void SHA384Update(SHA384ContextT *Context, const ByteT *Data, SizeT Size);

void SHA384Final(ByteT *Digest, SHA384ContextT *Context);

void SHA384Digest(const ByteT *Data, SizeT Size, ByteT *Digest);

void SHA512Init(SHA512ContextT *Context);

void SHA512Update(SHA512ContextT *Context, const ByteT *Data, SizeT Size);

void SHA512Final(ByteT *Digest, SHA512ContextT *Context);

void SHA512Digest(const ByteT *Data,  SizeT Size, ByteT *Digest);

#endif
