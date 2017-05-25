#ifndef HIERARCHY_HTTP_LIB_H
#define HIERARCHY_HTTP_LIB_H

#include "HTTPMessage.h"
#include "HTTPRequest.h"
#include "HTTPClient.h"
#include "HTTPAuth.h"
#include "HTTPDigestAuth.h"
#include "HTTPServer.h"
#include "HTTPHeader.h"
#include "HTTPReply.h"

extern void *NONULLIOS8;

/*extern const struct HTTPLibrary {
    struct {
        void (*Destroy)(void *HTTPClientVoid);
        int32_t (*Init)(HTTPClientT **HTTPClientPtr,
                        DNSClientT *DNSClient);
    } Client;

    struct {
        int32_t (*ListenHTTP)(HTTPSocketT **HTTPSocketPtr,
                              const SocketAddressT *ListenAddress,
                              HTTPRequestCallbackT *RequestCallback,
                              void *Argument);

        int32_t (*ListenHTTPS)(HTTPSocketT **HTTPSocketPtr,
                               const SocketAddressT *ListenAddress,
                               const char *CertificatePath,
                               HTTPRequestCallbackT *RequestCallback,
                               void *Argument);
    } Server;
} HTTPLib;*/

#endif
