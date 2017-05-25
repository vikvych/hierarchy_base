#ifndef HIERARCHY_EON_ARRAY_PUSH_H
#define HIERARCHY_EON_ARRAY_PUSH_H

#include "../ArrayT.h"

ErrnoT ArrayPushSimple(ArrayT *Array, AbstractT *Value);

ErrnoT ArrayPush(ObjectT *Object,
                char *Key[],
                SizeT KeyCount,
                AbstractT *Value);

#endif
