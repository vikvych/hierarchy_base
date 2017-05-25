#ifndef HIERARCHY_MEMORYBUFFER_REALLOC_H
#define HIERARCHY_MEMORYBUFFER_REALLOC_H

#include "MemoryBufferT.h"

ErrnoT MemoryBufferRealloc(MemoryBufferT *MemoryBuffer,
                           SizeT BytesLength);

#endif
