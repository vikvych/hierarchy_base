#ifndef HIERARCHY_EON_OBJECT_SIZE_H
#define HIERARCHY_EON_OBJECT_SIZE_H

#include "../ObjectT.h"

SizeT ObjectSizeSimple(ObjectT *Object);

ErrnoT ObjectSize(SizeT *Size,
                  ObjectT *Object,
                  char *Key[],
                  SizeT KeyCount);

#endif
