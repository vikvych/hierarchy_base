#ifndef HIERARCHY_URI_HEADER_H
#define HIERARCHY_URI_HEADER_H

#include "URI.h"

ErrnoT URIGetHeader(const MemoryBlockT *URIHeaders,
                    const MemoryBlockT *HeaderKey,
                    MemoryBlockT *HeaderValue);

ErrnoT URIEachHeader(const MemoryBlockT *URIHeaders,
                     URIEachCb *EachCb,
                     void *Argument);

ErrnoT URIHeaderCompareCallback(const MemoryBlockT *Key,
                                const MemoryBlockT *Value,
                                void *HeadersVoid);

#endif
