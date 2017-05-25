#ifndef HIERARCHY_EON_OBJECT_ELEMENT_TYPE_H
#define HIERARCHY_EON_OBJECT_ELEMENT_TYPE_H

#include "../ObjectT.h"

EONTypeT ObjectElementTypeSimple(ObjectT *Object,
                                 char *Key);

EONTypeT ObjectElementType(ObjectT *Object,
                           char *Key[],
                           SizeT KeyCount);

#endif
