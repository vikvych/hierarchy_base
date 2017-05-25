#ifndef HIERARCHY_EON_ARRAY_IS_TYPE_OF_H
#define HIERARCHY_EON_ARRAY_IS_TYPE_OF_H

#include "../ArrayT.h"

bool ArrayIsTypeOfSimple(ArrayT *Array,
                         SizeT Index,
                         EONTypeT Type);

bool ArrayIsTypeOf(ObjectT *Object,
                   char *Key[],
                   SizeT KeyCount,
                   SizeT Index,
                   EONTypeT Type);

#endif
