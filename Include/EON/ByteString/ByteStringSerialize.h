#ifndef HIERARCHY_EON_BYTESTRING_SERIALIZE_H
#define HIERARCHY_EON_BYTESTRING_SERIALIZE_H

#include "../ByteStringT.h"

ErrnoT ByteStringSerialize(MemoryBufferT *ThisBuffer,
                           ByteStringT *ByteString);

#endif
