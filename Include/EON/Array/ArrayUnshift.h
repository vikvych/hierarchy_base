#ifndef HIERARCHY_EON_ARRAY_UNSHIFT_H
#define HIERARCHY_EON_ARRAY_UNSHIFT_H

#include "../ArrayT.h"

ErrnoT ArrayUnshiftSimple(ArrayT *Array, AbstractT *Value);

ErrnoT ArrayUnshift(ObjectT *Object,
                    char *Key[],
                    SizeT KeyCount,
                    AbstractT *Value);


#endif
