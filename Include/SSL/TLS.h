#ifndef HIERARCHYBASE_TLS_TLS_H
#define HIERARCHYBASE_TLS_TLS_H

#include "SSL.h"
#include <openssl/bio.h>
#include "../Debug/DebugLib.h"

typedef struct {
    SSL *SSL;
    BIO *BIOOut;
    BIO *BIOIn;
    TCPBridgeT *Bridge;
    TCPConnectionT *Connection;
    bool Accepted;
    bool SSLActive;
} TLSConnectionT;

void TLSConnectionDestroy(void *TLSConnectionVoid);
int32_t TLSConnectionInit(TLSConnectionT **TLSConnectionPtr,
                           SSLContextT *SSLContext,
                           TCPConnectionT *TCPConnection,
                           int32_t Priority);

#endif
