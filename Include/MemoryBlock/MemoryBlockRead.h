#ifndef HIERARCHY_MEMORY_BLOCK_READ_H
#define HIERARCHY_MEMORY_BLOCK_READ_H

#include "MemoryBlockT.h"

uint32_t MemoryBlockReadBinToUInt32(const MemoryBlockT *MemoryBlock);
uint32_t MemoryBlockReadHexToUInt32(const MemoryBlockT *MemoryBlock);
uint64_t MemoryBlockReadBinToUInt64(const MemoryBlockT *MemoryBlock);
uint64_t MemoryBlockReadHexToUInt64(const MemoryBlockT *MemoryBlock);

double MemoryBlockReadBinToDouble(const MemoryBlockT *MemoryBlock);

#endif
