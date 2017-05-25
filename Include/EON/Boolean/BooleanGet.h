#ifndef HIERARCHY_EON_BOOLEAN_GET_H
#define HIERARCHY_EON_BOOLEAN_GET_H

#include "../BooleanT.h"

bool BooleanGetSimple(ObjectT *Object,
                      char *Key);

bool BooleanGet(ObjectT *Object,
                char *Key[],
                SizeT KeyCount);

#endif
