#ifndef HIERARCHY_HMAC_LIB_H
#define HIERARCHY_HMAC_LIB_H

#include "HMAC_SHA1.h"
#include "HMAC_SHA2.h"

extern const struct HMACLibrary {
    struct {
        void (*Init)(HMAC_SHA1ContextT *Context,
                     const ByteT *Key,
                     SizeT KeySize);

        void (*Reinit)(HMAC_SHA1ContextT *Context);

        void (*Update)(HMAC_SHA1ContextT *Context,
                       const ByteT *Data,
                       SizeT DataSize);

        void (*Final)(HMAC_SHA1ContextT *Context,
                      ByteT *Digest,
                      SizeT DigestSize);

        void (*Digest)(const ByteT *Key,
                       SizeT KeySize,
                       const ByteT *Data,
                       SizeT DataSize,
                       ByteT *Digest,
                       SizeT DigestSize);
    } SHA1;

    struct {
        struct {
            void (*Init)(HMAC_SHA224ContextT *Context,
                         const ByteT *Key,
                         SizeT KeySize);

            void (*Reinit)(HMAC_SHA224ContextT *Context);

            void (*Update)(HMAC_SHA224ContextT *Context,
                           const ByteT *Data,
                           SizeT DataSize);

            void (*Final)(HMAC_SHA224ContextT *Context,
                          ByteT *Digest,
                          SizeT DigestSize);

            void (*Digest)(const ByteT *Key,
                           SizeT KeySize,
                           const ByteT *Data,
                           SizeT DataSize,
                           ByteT *Digest,
                           SizeT DigestSize);
        } SHA224;

        struct {
            void (*Init)(HMAC_SHA256ContextT *Context,
                         const ByteT *Key,
                         SizeT KeySize);

            void (*Reinit)(HMAC_SHA256ContextT *Context);

            void (*Update)(HMAC_SHA256ContextT *Context,
                           const ByteT *Data,
                           SizeT DataSize);

            void (*Final)(HMAC_SHA256ContextT *Context,
                          ByteT *Digest,
                          SizeT DigestSize);

            void (*Digest)(const ByteT *Key,
                           SizeT KeySize,
                           const ByteT *Data,
                           SizeT DataSize,
                           ByteT *Digest,
                           SizeT DigestSize);
        } SHA256;

        struct {
            void (*Init)(HMAC_SHA384ContextT *Context,
                         const ByteT *Key,
                         SizeT KeySize);

            void (*Reinit)(HMAC_SHA384ContextT *Context);

            void (*Update)(HMAC_SHA384ContextT *Context,
                           const ByteT *Data,
                           SizeT DataSize);

            void (*Final)(HMAC_SHA384ContextT *Context,
                          ByteT *Digest,
                          SizeT DigestSize);

            void (*Digest)(const ByteT *Key,
                           SizeT KeySize,
                           const ByteT *Data,
                           SizeT DataSize,
                           ByteT *Digest,
                           SizeT DigestSize);
        } SHA384;

        struct {
            void (*Init)(HMAC_SHA512ContextT *Context,
                         const ByteT *Key,
                         SizeT KeySize);

            void (*Reinit)(HMAC_SHA512ContextT *Context);

            void (*Update)(HMAC_SHA512ContextT *Context,
                           const ByteT *Data,
                           SizeT DataSize);

            void (*Final)(HMAC_SHA512ContextT *Context,
                          ByteT *Digest,
                          SizeT DigestSize);

            void (*Digest)(const ByteT *Key,
                           SizeT KeySize,
                           const ByteT *Data,
                           SizeT DataSize,
                           ByteT *Digest,
                           SizeT DigestSize);
        } SHA512;

    } SHA2;
} HMACLib;

#endif
