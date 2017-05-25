#ifndef HIERARCHY_EON_ARRAY_ELEMENT_TYPE_H
#define HIERARCHY_EON_ARRAY_ELEMENT_TYPE_H

#include "../ArrayT.h"

EONTypeT ArrayElementTypeSimple(ArrayT *Array, SizeT Index);

EONTypeT ArrayElementType(ObjectT *Object,
                          char *Key[],
                          SizeT KeyCount,
                          SizeT Index);

#endif
