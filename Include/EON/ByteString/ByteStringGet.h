#ifndef HIERARCHY_EON_BYTESTRING_GET_H
#define HIERARCHY_EON_BYTESTRING_GET_H

#include "../ByteStringT.h"

MemoryBufferT *ByteStringGetSimple(ObjectT *Object,
                                   char *Key);

MemoryBufferT *ByteStringGet(ObjectT *Object,
                             char *Key[],
                             SizeT KeyCount);

#endif
