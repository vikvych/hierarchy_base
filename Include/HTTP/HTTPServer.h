#ifndef HIERARCHY_HTTP_SERVER_H
#define HIERARCHY_HTTP_SERVER_H

#include "HTTPConnection.h"
#include "HTTPSocket.h"

#define HTTP_SERVER_TIMEOUT_ACCEPT 15000

HTTPSocketT *HTTPServerListenHTTP(const SocketAddressT *ListenAddress,
                                  HTTPRequestCallbackT *RequestCallback,
                                  void *Argument);

HTTPSocketT *HTTPServerListenHTTPS(const SocketAddressT *ListenAddress,
                                   const char *CertificatePath,
                                   HTTPRequestCallbackT *RequestCallback,
                                   void *Argument);

#endif
