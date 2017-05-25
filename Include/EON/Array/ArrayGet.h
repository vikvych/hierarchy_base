#ifndef HIERARCHY_EON_ARRAY_GET_H
#define HIERARCHY_EON_ARRAY_GET_H

#include "../ArrayT.h"

AbstractT *ArrayGetSimple(ArrayT *Array,
                          SizeT Index);

AbstractT *ArrayGet(ObjectT *Object,
                    char *Key[],
                    SizeT KeyCount,
                    SizeT Index);

#endif
