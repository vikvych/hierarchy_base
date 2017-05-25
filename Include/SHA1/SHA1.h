#ifndef HIERARCHY_SHA1_H
#define HIERARCHY_SHA1_H

#include "../Error/ErrorLib.h"
#include "../Memory/MemoryLib.h"
#include "../Debug/DebugLib.h"
#include "../Endian/EndianLib.h"

#define SHA_BLOCK_SIZE 20
#define SHA_DIGEST_LENGTH 20

typedef struct {
    ByteT Buffer[64];
    DWordT State[5];
    SizeT ByteCount;
    DWordT CurrentIndex;
} SHA1ContextT;

void SHA1Init(SHA1ContextT *Context);
void SHA1Update(SHA1ContextT *Context, const ByteT* Data, SizeT Size);
void SHA1Final(ByteT *Digest, SHA1ContextT *Context);
void SHA1Digest(const ByteT *Data, SizeT Size, ByteT *Digest);

#endif
