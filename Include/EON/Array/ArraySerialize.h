#ifndef HIERARCHY_EON_ARRAY_SERIALIZE_H
#define HIERARCHY_EON_ARRAY_SERIALIZE_H

#include "../ArrayT.h"

ErrnoT ArraySerializeExciting(MemoryBufferT *ThisBuffer,
                              ArrayT *Array);

MemoryBufferT *ArraySerialize(ArrayT *Array);

#endif
