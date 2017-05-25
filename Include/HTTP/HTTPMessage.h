#ifndef HIERARCHY_HTTP_MESSAGE_H
#define HIERARCHY_HTTP_MESSAGE_H

#include "../MemoryBlock/MemoryBlockLib.h"
#include "../MD5/MD5.h"

#include "HTTPIncludes.h"

#define HTTP_MESSAGE_BUFFER_LENGTH_LIMIT 20 * 1024 * 1024

void HTTPMessageDestroy(void *HTTPMessageVoid);

ErrnoT HTTPMessageContentTypeParse(HTTPMessageContentTypeT *ContentType,
                                    const MemoryBlockT *pl);

bool HTTPMessageContentTypeCompare(const HTTPMessageContentTypeT *ContentType,
                                   const char *ContentTypeString,
                                   const char *ContentSubTypeString);

ErrnoT HTTPMessagePrint(PrintT *Print,
                        const HTTPMessageT *Message);

ErrnoT HTTPMessageParser(HTTPMessageT **MessagePtr,
                          MemoryBufferT *HTTPMessageBuffer,
                          bool IsRequest);

#endif
