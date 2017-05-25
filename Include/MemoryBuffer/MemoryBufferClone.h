#ifndef HIERARCHY_MEMORYBUFFER_CLONE_H
#define HIERARCHY_MEMORYBUFFER_CLONE_H

#include "MemoryBufferT.h"

char *MemoryBufferCloneString(MemoryBufferT *MemoryBuffer,
                              SizeT StringLength);

MemoryBufferT *MemoryBufferCloneMemoryBuffer(MemoryBufferT *MemoryBuffer);

#endif
