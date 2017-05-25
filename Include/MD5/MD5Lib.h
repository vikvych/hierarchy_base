#ifndef HIERARCHY_MD5_LIB_H
#define HIERARCHY_MD5_LIB_H

#include "MD5.h"

extern const struct MD5Library {
    void (*Init)(MD5ContextT *Context);
    void (*Update)(MD5ContextT *Context, const ByteT *Input, SizeT Size);
    void (*Final)(ByteT *Digest, MD5ContextT *Context);

    void (*Digest)(const ByteT *Data,
                   SizeT DataLength,
                   ByteT *MD5DigestPtr);

    int32_t (*Print)(ByteT *MD5DigestPtr,
                     const char *Format, ...);
} MD5Lib;

#endif
