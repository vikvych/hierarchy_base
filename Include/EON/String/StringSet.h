#ifndef HIERARCHY_EON_STRING_SET_H
#define HIERARCHY_EON_STRING_SET_H

#include "../StringT.h"

ErrnoT StringSetSimple(ObjectT *Object,
                       char *Key,
                       char *Value);

ErrnoT StringSet(ObjectT *Object,
                 char *Key[],
                 SizeT KeyCount,
                 char *Value);

#endif
