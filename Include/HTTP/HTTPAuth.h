#ifndef HIERARCHY_HTTP_AUTH_H
#define HIERARCHY_HTTP_AUTH_H

#include "../MemoryBlock/MemoryBlockLib.h"
#include "../Random/RandomLib.h"
#include "../MD5/MD5.h"

#include "HTTPIncludes.h"

#define HTTP_AUTH_NONCE_TTL 300
#define HTTP_AUTH_NONCE_MIN_LENGTH 33

static bool AuthSecretSetFlag;
static QWordT AuthSecret;

typedef ErrnoT (HTTPAuthCallbackT)(const MemoryBlockT *Login,
                                    ByteT *HA1,
                                    void *Argument);

typedef struct {
    const char *Realm;
    bool Stale;
} HTTPAuthT;

ErrnoT HTTPAuthPrint(PrintT *Print,
                     const HTTPAuthT *Auth);

bool HTTPAuthCheckHTTPAuthDigest(const MemoryBlockT *AuthHeaderValue,
                                 const MemoryBlockT *RequestMethod,
                                 HTTPAuthT *Auth,
                                 HTTPAuthCallbackT *AuthCallback,
                                 void *Argument);

bool HTTPCheckAuthDigestRequest(const HTTPMessageT *Message,
                             HTTPAuthT *Auth,
                             HTTPAuthCallbackT *AuthCallback,
                             void *Argument);

#endif
