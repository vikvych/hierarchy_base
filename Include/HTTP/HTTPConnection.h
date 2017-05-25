#ifndef HIERARCHY_HTTP_CONNECTION_H
#define HIERARCHY_HTTP_CONNECTION_H

#include "../SSL/SSLLib.h"
#include "HTTPSocket.h"

#define HTTP_CONNECTION_BUFFER_LENGTH_MAX 20 * 1024 * 1024
#define HTTP_CONNECTION_TIMEOUT_IDLE 600000

void HTTPConnectionDestroy(void *HTTPConnectionVoid);

void HTTPConnectionTCPDataCallback(MemoryBufferT *Data,
                                   void *Argument);

void HTTPConnectionCloseCallback(ErrnoT Error,
                                 void *Argument);

void HTTPConnectionTimeoutCallback(void *Argument);

void HTTPConnectionClose(HTTPConnectionT *HTTPConnection);
void HTTPConnectionCloseInner(HTTPConnectionT *HTTPConnection);

SocketAddressT *HTTPConnectionPeerAddressGet(HTTPConnectionT *HTTPConnection);
TCPConnectionT *HTTPConnectionTCPConnectionGet(HTTPConnectionT *HTTPConnection);
TLSConnectionT *HTTPConnectionTLSConnectionGet(HTTPConnectionT *HTTPConnection);

#endif
