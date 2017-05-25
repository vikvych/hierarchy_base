#ifndef HIERARCHY_EON_ARRAY_POP_H
#define HIERARCHY_EON_ARRAY_POP_H

#include "../ArrayT.h"

ErrnoT ArrayPopSimple(AbstractT **Value, ArrayT *Array);

ErrnoT ArrayPop(AbstractT **Value,
                ObjectT *Object,
                char *Key[],
                SizeT KeyCount);

#endif
