#ifndef HIERARCHY_HTTP_HEADER_H
#define HIERARCHY_HTTP_HEADER_H

#include "HTTPIncludes.h"

typedef struct {
    ListNodeT ListNode;
    MemoryBlockT Key;
    MemoryBlockT Value;
} HTTPHeaderT;

void HTTPHeaderDestroy(void *HTTPHeaderVoid);

typedef bool(HTTPHeaderCallbackT)(const HTTPHeaderT *Header,
                                  void *Argument);

ErrnoT HTTPMessageHeaderAdd(HTTPMessageT *Message,
                         const MemoryBlockT *Key,
                         const char *ValuePtr,
                         SSizeT ValuePtrLength);

bool HTTPHeaderIsList(MemoryBlockT *Key);



const HTTPHeaderT *HTTPMessageHeaderGet(const HTTPMessageT *Message,
                                        char* Key);

const HTTPHeaderT *HTTPMessageHeaderApply(const HTTPMessageT *Message,
                                      bool Direct,
                                      char *Key,
                                      HTTPHeaderCallbackT *HeaderCallback,
                                      void *Argument);

SizeT HTTPMessageHeaderCount(const HTTPMessageT *Message,
                            char *Key);

bool HTTPMessageHeaderIsEqual(const HTTPMessageT *Message,
                            char *Key,
                            const char *Value);



#endif
