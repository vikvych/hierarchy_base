#ifndef HIERARCHY_CRC32_LIB_H
#define HIERARCHY_CRC32_LIB_H

#include "CRC32.h"

extern const struct CRC32Library {
    DWordT (*Digest)(DWordT CRCDigest, const ByteT *Data, SizeT DataLength);
} CRC32Lib;

#endif
