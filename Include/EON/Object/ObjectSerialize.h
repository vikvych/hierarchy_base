#ifndef HIERARCHY_EON_OBJECT_SERIALIZE_H
#define HIERARCHY_EON_OBJECT_SERIALIZE_H

#include "../ObjectT.h"

ErrnoT ObjectSerializeExciting(MemoryBufferT *ThisBuffer,
                               ObjectT *Object);

MemoryBufferT *ObjectSerialize(ObjectT *Object);

#endif
