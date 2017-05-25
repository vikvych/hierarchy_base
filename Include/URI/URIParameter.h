#ifndef HIERARCHY_URI_PARAMETER_H
#define HIERARCHY_URI_PARAMETER_H

#include "URI.h"

ErrnoT URIGetParam(const MemoryBlockT *URIParametersData,
                   const MemoryBlockT *ParameterKey,
                   MemoryBlockT *ParameterValue);

ErrnoT URIEachParam(const MemoryBlockT *URIParams,
                    URIEachCb *EachCb,
                    void *Argument);

ErrnoT URIParameterCompareCallback(const MemoryBlockT *Key,
                                   const MemoryBlockT *Value,
                                   void *ParametersVoid);

#endif
