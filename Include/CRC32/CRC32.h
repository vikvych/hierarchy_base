#ifndef HIERARCHY_CRC32_H
#define HIERARCHY_CRC32_H

#include <stdint.h>

#include "../Memory/MemoryLib.h"
#include "../Compression/MiniZ.h"

DWordT CRC32Digest(DWordT CRCDigest, const ByteT *Data, SizeT DataLength);

#endif
