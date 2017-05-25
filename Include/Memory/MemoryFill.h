#ifndef HIERARCHY_MEMORY_FILL_H
#define HIERARCHY_MEMORY_FILL_H

#include "MemoryT.h"

ErrnoT MemoryFill(void *Data, ByteT FillByte, SizeT Size);
void MemoryFillSimple(void *Data, ByteT FillByte, SizeT Size);

#endif
