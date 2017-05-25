#ifndef HIERARCHY_EON_BYTESTRING_SET_H
#define HIERARCHY_EON_BYTESTRING_SET_H

#include "../ByteStringT.h"

ErrnoT ByteStringSetSimple(ObjectT *Object,
                           char *Key,
                           MemoryBufferT *Value);

ErrnoT ByteStringSet(ObjectT *Object,
                     char *Key[],
                     SizeT KeyCount,
                     MemoryBufferT *Value);

#endif
