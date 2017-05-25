#ifndef HIERARCHY_EON_ARRAY_REMOVE_H
#define HIERARCHY_EON_ARRAY_REMOVE_H

#include "../ArrayT.h"

void ArrayRemoveSimple(ArrayT *Array,
                       SizeT Index);

void ArrayRemove(ObjectT *Object,
                 char *Key[],
                 SizeT KeyCount,
                 SizeT Index);

#endif
