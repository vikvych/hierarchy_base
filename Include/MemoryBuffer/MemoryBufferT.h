#ifndef HIERARCHY_MEMORYBUFFER_T_H
#define HIERARCHY_MEMORYBUFFER_T_H

#include "../Memory/MemoryLib.h"

#define MEMORY_BUFFER_DEFAULT_SIZE 1024

typedef struct {
    ByteT *Data;
    SizeT Size;
    SizeT Position;
    SizeT End;
} MemoryBufferT;

void MemoryBufferDestroy(void *MemoryBufferVoid);
MemoryBufferT *MemoryBufferInitRef(MemoryBufferT *MemoryBuffer);
void MemoryBufferInitNull(MemoryBufferT *MemoryBuffer);
MemoryBufferT *MemoryBufferInit(SizeT BytesLength);

#endif
