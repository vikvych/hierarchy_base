#ifndef HIERARCHY_SHA1_LIB_H
#define HIERARCHY_SHA1_LIB_H

#include "SHA1.h"

extern const struct SHA1Library {
    void (*Init)(SHA1ContextT *Context);
    void (*Update)(SHA1ContextT *Context, const ByteT* Data, SizeT Size);
    void (*Final)(ByteT *Digest, SHA1ContextT *Context);
    void (*Digest)(const ByteT *Data, SizeT Size, ByteT *Digest);
} SHA1Lib;

#endif
