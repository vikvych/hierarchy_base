#ifndef HIERARCHY_URI_LIB_H
#define HIERARCHY_URI_LIB_H

#include "URI.h"
#include "URIDecode.h"
#include "URIEncode.h"
#include "URICompare.h"
#include "URIParameter.h"
#include "URIHeader.h"

extern const struct URILibrary {
    ErrnoT (*Decode)(URIT *URI,
                     const MemoryBlockT *URIData);

    ErrnoT (*Encode)(PrintT *Print,
                     const URIT *URI);

    bool (*Compare)(const URIT *URI1, const URIT *URI2);

    struct {
        ErrnoT (*Get)(const MemoryBlockT *URIParametersData,
                      const MemoryBlockT *ParameterKey,
                      MemoryBlockT *ParameterValue);

        ErrnoT (*Each)(const MemoryBlockT *URIParams,
                       URIEachCb *EachCb,
                       void *Argument);
    } Parameter;

    struct {
        ErrnoT (*Get)(const MemoryBlockT *URIHeaders,
                      const MemoryBlockT *HeaderKey,
                      MemoryBlockT *HeaderValue);

        ErrnoT (*Each)(const MemoryBlockT *URIHeaders,
                       URIEachCb *EachCb,
                       void *Argument);
    } Header;


} URILib;

#endif
