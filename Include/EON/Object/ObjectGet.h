#ifndef HIERARCHY_EON_OBJECT_GET_H
#define HIERARCHY_EON_OBJECT_GET_H

#include "../ObjectT.h"

AbstractT *ObjectGetSimple(ObjectT *Object,
                           char *Key);

AbstractT *ObjectGet(ObjectT *Object,
                     char *Key[],
                     SizeT KeyCount);

#endif
