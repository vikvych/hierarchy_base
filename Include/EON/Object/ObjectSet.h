#ifndef HIERARCHY_EON_OBJECT_SET_H
#define HIERARCHY_EON_OBJECT_SET_H

#include "../ObjectT.h"

ErrnoT ObjectSetSimple(ObjectT *Object, char *Key, void *Value);
ErrnoT ObjectSet(ObjectT *Object, char *Key[], SizeT KeyCount, void *Value);

#endif
