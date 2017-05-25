#ifndef HIERARCHY_MEMORY_BLOCK_T_H
#define HIERARCHY_MEMORY_BLOCK_T_H

#include <stdint.h>
#include <stdbool.h>
#include <ctype.h>

#include "../Memory/MemoryLib.h"

typedef struct {
    const ByteT *Data;
    SizeT Size;
} MemoryBlockT;



#endif
