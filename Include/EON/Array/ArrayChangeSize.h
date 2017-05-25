#ifndef HIERARCHY_EON_ARRAY_CHANGE_SIZE_H
#define HIERARCHY_EON_ARRAY_CHANGE_SIZE_H

#include "../UndefinedT.h"
#include "ArrayClear.h"
#include "ArrayPush.h"
#include "ArrayRemove.h"

ErrnoT ArrayChangeSizeSimple(ArrayT *Array,
                             SizeT NewLength);

ErrnoT ArrayChangeSize(ObjectT *Object,
                       char *Key[],
                       SizeT KeyCount,
                       SizeT NewLength);

#endif
