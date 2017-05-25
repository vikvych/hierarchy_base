#ifndef HIERARCHY_MEMORYBUFFER_READ_H
#define HIERARCHY_MEMORYBUFFER_READ_H

#include "MemoryBufferT.h"

ErrnoT MemoryBufferReadData(MemoryBufferT *MemoryBuffer,
                            ByteT *Data,
                            SizeT BytesLength);

ByteT MemoryBufferReadByte(MemoryBufferT *MemoryBuffer);

uint16_t MemoryBufferReadWord(MemoryBufferT *MemoryBuffer);

uint32_t MemoryBufferReadDWord(MemoryBufferT *MemoryBuffer);

uint64_t MemoryBufferReadQWord(MemoryBufferT *MemoryBuffer);

ErrnoT MemoryBufferReadString(MemoryBufferT *MemoryBuffer,
                              char *String,
                              SizeT BytesLength);


#endif
