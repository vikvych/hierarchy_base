#ifndef HIERARCHY_EON_NUMBER_SET_H
#define HIERARCHY_EON_NUMBER_SET_H

#include "../NumberT.h"

ErrnoT NumberSetIntSimple(ObjectT *Object,
                          char *Key,
                          int64_t Value);

ErrnoT NumberSetDoubleSimple(ObjectT *Object,
                             char *Key,
                             double Value);

ErrnoT NumberSetInt(ObjectT *Object,
                    char *Key[],
                    SizeT KeyCount,
                    int64_t Value);

ErrnoT NumberSetDouble(ObjectT *Object,
                       char *Key[],
                       SizeT KeyCount,
                       double Value);

#endif
