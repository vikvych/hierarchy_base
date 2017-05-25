#ifndef HIERARCHY_HTTP_DIGEST_AUTH_H
#define HIERARCHY_HTTP_DIGEST_AUTH_H

#include "../MemoryBlock/MemoryBlockLib.h"
#include "../MD5/MD5Lib.h"


typedef void (HTTPAuthDigestParseCallbackT)(const MemoryBlockT *Key,
                                            const MemoryBlockT *Value,
                                            void *Argument);

typedef struct {
    MemoryBlockT Realm;
    MemoryBlockT ServerNonce;

    MemoryBlockT Opaque;
    MemoryBlockT Stale;
    MemoryBlockT Algorithm;
    MemoryBlockT QOP;
} HTTPAuthDigestChallengeT;

typedef struct {
    MemoryBlockT Realm;
    MemoryBlockT ServerNonce;
    MemoryBlockT Response;
    MemoryBlockT Username;
    MemoryBlockT URI;

    MemoryBlockT RequestCount;
    MemoryBlockT ClientNonce;
    MemoryBlockT QOP;
} HTTPAuthDigestResponseT;

ErrnoT HTTPDigestAuthChallengeParse(HTTPAuthDigestChallengeT *DigestChallenge,
                                      const MemoryBlockT *Header);

ErrnoT HTTPAuthDigestResponseDecode(HTTPAuthDigestResponseT *DigestResponse,
                                     const MemoryBlockT *Header);

ErrnoT HTTPAuthDigestResponseAuthCheck(const HTTPAuthDigestResponseT *DigestResponse,
                                        const MemoryBlockT *RequestMethod,
                                        const ByteT *HA1);

#endif
