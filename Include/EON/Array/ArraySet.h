#ifndef HIERARCHY_EON_ARRAY_SET_H
#define HIERARCHY_EON_ARRAY_SET_H

#include "../ArrayT.h"

ErrnoT ArraySetSimple(ArrayT *Array,
                      SizeT Index,
                      AbstractT *Value);

ErrnoT ArraySet(ObjectT *Object,
                char *Key[],
                SizeT KeyCount,
                SizeT Index,
                AbstractT *Value);

#endif
