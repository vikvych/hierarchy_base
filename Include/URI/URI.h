#ifndef HIERARCHY_URI_H
#define HIERARCHY_URI_H

#include <string.h>
#include <ctype.h>

#include "../Memory/MemoryLib.h"
#include "../List/ListLib.h"
#include "../SocketAddress/SocketAddressLib.h"

typedef struct {
    MemoryBlockT Scheme;
    MemoryBlockT Username;
    MemoryBlockT Password;
    MemoryBlockT Host;
    WordT Port;
    int AddressFamily;

    MemoryBlockT Parameters;
    MemoryBlockT Headers;
} URIT;

typedef int32_t (URIEachCb)(const MemoryBlockT *name,
                                    const MemoryBlockT *val,
                                    void *Argument);
extern void *NONULLIOS12;


#endif
