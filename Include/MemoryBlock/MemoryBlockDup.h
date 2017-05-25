#ifndef HIERARCHY_MEMORY_BLOCK_DUP_H
#define HIERARCHY_MEMORY_BLOCK_DUP_H

#include "MemoryBlockT.h"

ErrnoT MemoryBlockDupString(char **Destination,
                               const MemoryBlockT *Source);

ErrnoT MemoryBlockDupMemoryBlock(MemoryBlockT *Destination,
                       const MemoryBlockT *Source);

#endif
