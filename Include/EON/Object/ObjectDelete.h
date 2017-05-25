#ifndef HIERARCHY_EON_OBJECT_DELETE_H
#define HIERARCHY_EON_OBJECT_DELETE_H

#include "../ObjectT.h"

void ObjectDeleteSimple(ObjectT *Object, char *Key);

void ObjectDelete(ObjectT *Object,
                  char *Key[],
                  SizeT KeyCount);

#endif
