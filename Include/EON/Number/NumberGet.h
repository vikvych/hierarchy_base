#ifndef HIERARCHY_EON_NUMBER_GET_H
#define HIERARCHY_EON_NUMBER_GET_H

#include "../NumberT.h"

int64_t NumberGetIntSimple(ObjectT *Object,
                           char *Key);

double NumberGetDoubleSimple(ObjectT *Object,
                             char *Key);

int64_t NumberGetInt(ObjectT *Object,
                     char *Key[],
                     SizeT KeyCount);

double NumberGetDouble(ObjectT *Object,
                       char *Key[],
                       SizeT KeyCount);

#endif
