#ifndef HIERARCHY_EON_OBJECT_KEYS_H
#define HIERARCHY_EON_OBJECT_KEYS_H

#include "../ObjectT.h"

ListT *ObjectKeysSimple(ObjectT *Object);

ListT *ObjectKeys(ObjectT *Object,
                  char *Key[],
                  SizeT KeyCount);

#endif
