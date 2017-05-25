#ifndef HIERARCHY_EON_BOOLEAN_SET_H
#define HIERARCHY_EON_BOOLEAN_SET_H

#include "../BooleanT.h"

ErrnoT BooleanSetSimple(ObjectT *Object,
                        char *Key,
                        bool Value);

ErrnoT BooleanSet(ObjectT *Object,
                  char *Key[],
                  SizeT KeyCount,
                  bool Value);

#endif
