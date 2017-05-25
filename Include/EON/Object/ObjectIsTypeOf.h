#ifndef HIERARCHY_EON_OBJECT_ISTYPEOF_H
#define HIERARCHY_EON_OBJECT_ISTYPEOF_H

#include "../ObjectT.h"

bool ObjectIsTypeOfSimple(ObjectT *Object,
                          char *Key,
                          EONTypeT ValueType);

bool ObjectIsTypeOf(ObjectT *Object,
                    char *Key[],
                    SizeT KeyCount,
                    EONTypeT ValueType);

#endif
