#ifndef HIERARCHY_MEMORYBUFFER_PRINT_H
#define HIERARCHY_MEMORYBUFFER_PRINT_H

#include "MemoryBufferT.h"
#include "../Print/PrintT.h"

ErrnoT MemoryBufferPrint(PrintT *Print,
                         const MemoryBufferT *MemoryBuffer);

#endif
