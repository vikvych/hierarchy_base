#ifndef HIERARCHY_SHA2_LIB_H
#define HIERARCHY_SHA2_LIB_H

#include "SHA2.h"

extern const struct SHA2Library {
    struct {
        void (*Init)(SHA224ContextT *Context);
        void (*Update)(SHA224ContextT *Context, const ByteT* Data, SizeT Size);
        void (*Final)(ByteT *Digest, SHA224ContextT *Context);
        void (*Digest)(const ByteT *Data, SizeT Size, ByteT *Digest);
    } SHA224;

    struct {
        void (*Init)(SHA256ContextT *Context);
        void (*Update)(SHA256ContextT *Context, const ByteT* Data, SizeT Size);
        void (*Final)(ByteT *Digest, SHA256ContextT *Context);
        void (*Digest)(const ByteT *Data, SizeT Size, ByteT *Digest);
    } SHA256;

    struct {
        void (*Init)(SHA384ContextT *Context);
        void (*Update)(SHA384ContextT *Context, const ByteT* Data, SizeT Size);
        void (*Final)(ByteT *Digest, SHA384ContextT *Context);
        void (*Digest)(const ByteT *Data, SizeT Size, ByteT *Digest);
    } SHA384;

    struct {
        void (*Init)(SHA512ContextT *Context);
        void (*Update)(SHA512ContextT *Context, const ByteT* Data, SizeT Size);
        void (*Final)(ByteT *Digest, SHA512ContextT *Context);
        void (*Digest)(const ByteT *Data,  SizeT Size, ByteT *Digest);
    } SHA512;

} SHA2Lib;

#endif
