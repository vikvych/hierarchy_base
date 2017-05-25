#ifndef HIERARCHY_MEMORYBUFFER_FILL_H
#define HIERARCHY_MEMORYBUFFER_FILL_H

#include "MemoryBufferT.h"

ErrnoT MemoryBufferFill(MemoryBufferT *MemoryBuffer,
                        ByteT Byte,
                        SizeT Count);

#endif
