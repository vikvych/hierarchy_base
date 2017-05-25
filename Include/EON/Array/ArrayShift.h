#ifndef HIERARCHY_EON_ARRAY_SHIFT_H
#define HIERARCHY_EON_ARRAY_SHIFT_H

#include "../ArrayT.h"

ErrnoT ArrayShiftSimple(AbstractT **Value, ArrayT *Array);

ErrnoT ArrayShift(AbstractT **Value,
                  ObjectT *Object,
                  char *Key[],
                  SizeT KeyCount);

#endif
