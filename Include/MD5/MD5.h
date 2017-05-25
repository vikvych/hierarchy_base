#ifndef HIERARCHY_MD5_H
#define HIERARCHY_MD5_H

#include "../Memory/MemoryLib.h"
#include "../MemoryBuffer/MemoryBufferLib.h"
#include "../Print/PrintLib.h"

typedef struct{
    DWordT ByteCount[2];
    DWordT State[4];
    ByteT Buffer[64];
} MD5ContextT;

#define MD5_SIZE 16

void MD5Init(MD5ContextT *Context);
void MD5Update(MD5ContextT *Context, const ByteT *Input, SizeT Size);
void MD5Final(ByteT *Digest, MD5ContextT *Context);

void MD5Digest(const ByteT *Data,
               SizeT DataLength,
               ByteT *MD5DigestPtr);

int32_t MD5Print(ByteT *MD5DigestPtr,
                 const char *Format, ...);

#endif
