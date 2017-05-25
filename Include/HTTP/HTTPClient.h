#ifndef HIERARCHY_HTTP_CLIENT_H
#define HIERARCHY_HTTP_CLIENT_H

#include "../DNS/DNSLib.h"
#include "../SSL/SSLLib.h"

#include "HTTPIncludes.h"

void HTTPClientDestroy(void *HTTPClientVoid);
HTTPClientT *HTTPClientInit(DNSClientT *DNSClient);

#endif
