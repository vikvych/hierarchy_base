#ifndef HIERARCHY_EON_STRING_GET_H
#define HIERARCHY_EON_STRING_GET_H

#include "../StringT.h"

char *StringGetSimple(ObjectT *Object,
                      char *Key);

char *StringGet(ObjectT *Object,
                char *Key[],
                SizeT KeyCount);

#endif
