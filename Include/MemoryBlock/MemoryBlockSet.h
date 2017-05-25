#ifndef HIERARCHY_MEMORY_BLOCK_SET_STRING_H
#define HIERARCHY_MEMORY_BLOCK_SET_STRING_H

#include "MemoryBlockT.h"
#include "../MemoryBuffer/MemoryBufferT.h"

void MemoryBlockSetString(MemoryBlockT *MemoryBlock,
                          const char *String);

void MemoryBlockSetMemoryBuffer(MemoryBlockT *MemoryBlock,
                                const MemoryBufferT *MemoryBuffer);

#endif
