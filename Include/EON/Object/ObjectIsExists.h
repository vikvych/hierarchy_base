#ifndef HIERARCHY_EON_OBJECT_ISEXISTS_H
#define HIERARCHY_EON_OBJECT_ISEXISTS_H

#include "../ObjectT.h"

bool ObjectIsExistsSimple(ObjectT *Object,
                          char *Key);

bool ObjectIsExists(ObjectT *Object,
                    char *Key[],
                    SizeT KeyCount);

#endif
