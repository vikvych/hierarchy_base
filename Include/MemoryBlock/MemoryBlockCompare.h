#ifndef HIERARCHY_MEMORY_BLOCK_COMPARE_H
#define HIERARCHY_MEMORY_BLOCK_COMPARE_H

#include "MemoryBlockT.h"

ErrnoT MemoryBlockCompareString(const MemoryBlockT *MemoryBlock,
                                 const char *String);

ErrnoT MemoryBlockCompareStringI(const MemoryBlockT *MemoryBlock,
                                  const char *String);

ErrnoT MemoryBlockCompareMemoryBlock(const MemoryBlockT *MemoryBlock1,
                           const MemoryBlockT *MemoryBlock2);

ErrnoT MemoryBlockCompareMemoryBlockI(const MemoryBlockT *MemoryBlock1,
                            const MemoryBlockT *MemoryBlock2);

#endif
