#ifndef HIERARCHY_MEMORY_ZALLOC_H
#define HIERARCHY_MEMORY_ZALLOC_H

#include "MemoryT.h"

void *MemoryZAlloc(SizeT Size, MemoryDestroyCb *DestroyCb);

#endif
