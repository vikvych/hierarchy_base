#ifndef HIERARCHY_HTTP_REPLY_H
#define HIERARCHY_HTTP_REPLY_H

#include "HTTPMessage.h"

ErrnoT HTTPReplySendResponse(HTTPConnectionT *HTTPConnection,
                              WordT ResponseCode,
                              const char *ResponseReason,
                              const char *Format, ...);

ErrnoT HTTPReplySendResponseWithContent(HTTPConnectionT *HTTPConnection,
                                         WordT ResponseCode,
                                         const char *ResponseReason,
                                         const char *ContentType,
                                         const char *Format, ...);

ErrnoT HTTPReplySendError(HTTPConnectionT *HTTPConnection,
                           WordT ResponseCode,
                           const char *ResponseReason);

#endif
