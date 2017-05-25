#ifndef HIERARCHY_GZIP_LIB_H
#define HIERARCHY_GZIP_LIB_H

#include "GZIP.h"

extern const struct GZIPLibrary {
    MemoryBufferT *(*Compress)( MemoryBufferT *PlainData);
    MemoryBufferT *(*Decompress)(MemoryBufferT *CompressedData);
} GZIPLib;

#endif
