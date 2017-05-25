#ifndef HIERARCHY_EON_ARRAY_SIZE_H
#define HIERARCHY_EON_ARRAY_SIZE_H

#include "../ArrayT.h"

SizeT ArraySizeSimple(ArrayT *Array);

ErrnoT ArraySize(SizeT *Size,
                 ObjectT *Object,
                 char *Key[],
                 SizeT KeyCount);

#endif
