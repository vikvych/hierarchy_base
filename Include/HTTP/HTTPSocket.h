#ifndef HIERARCHY_HTTP_SOCKET_H
#define HIERARCHY_HTTP_SOCKET_H

#include "HTTPRequest.h"

void HTTPSocketDestroy(void *HTTPSocketVoid);
TCPSocketT *HTTPSocketTCPSocketGet(HTTPSocketT *HTTPSocket);

#endif
