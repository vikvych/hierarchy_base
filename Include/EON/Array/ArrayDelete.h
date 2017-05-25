#ifndef HIERARCHY_EON_ARRAY_DELETE_H
#define HIERARCHY_EON_ARRAY_DELETE_H

#include "../ArrayT.h"

void ArrayDeleteSimple(ArrayT *Array,
                       SizeT Index);

void ArrayDelete(ObjectT *Object,
                 char *Key[],
                 SizeT KeyCount,
                 SizeT Index);


#endif
