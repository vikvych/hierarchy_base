#ifndef HIERARCHY_MEMORY_BLOCK_COPY_H
#define HIERARCHY_MEMORY_BLOCK_COPY_H

#include "MemoryBlockT.h"

ErrnoT MemoryBlockCopyString(const MemoryBlockT *MemoryBlock,
                                char *StringBuffer,
                                SizeT StringBufferLength);

#endif
