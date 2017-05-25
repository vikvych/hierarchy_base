#ifndef HIERARCHY_HTTP_REQUEST_H
#define HIERARCHY_HTTP_REQUEST_H

#include "../DNS/DNSLib.h"

#include "HTTPIncludes.h"

#define HTTP_REQUEST_BUFFERLENGTH_LIMIT 20 * 1024 * 1024

void HTTPRequestDestroy(void *HTTPRequestVoid);

ErrnoT HTTPRequestInit(HTTPRequestT **HTTPRequestPtr,
                        HTTPClientT *HTTPClient,
                        const char *Method,
                        const char *URI,
                        HTTPResponseCallbackT *ResponseCallback,
                        HTTPDataCallbackT *DataCallback,
                        void *Argument,
                        QWordT ConnectionTimeout,
                        QWordT ResponseTimeout,
                        const char *Format, ...);

void HTTPRequestClose(HTTPRequestT *HTTPRequest,
                      ErrnoT Error,
                      const HTTPMessageT *Message);

ErrnoT HTTPRequestConnect(HTTPRequestT *HTTPRequest);


TCPConnectionT *HTTPRequestTCPConnectionGet(HTTPRequestT *HTTPRequest);
TLSConnectionT *HTTPRequestTLSConnectionGet(HTTPRequestT *HTTPRequest);

#endif
