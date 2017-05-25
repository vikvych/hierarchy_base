#ifndef HIERARCHY_DNS_RESOLVE_H
#define HIERARCHY_DNS_RESOLVE_H

#include "Include/System/SystemLib.h"
#include "Include/Debug/DebugLib.h"
#include "Include/MemoryBlock/MemoryBlockLib.h"
#include "Include/SocketAddress/SocketAddressLib.h"

#define DNS_PORT 53

#ifdef __ANDROID__
#include <sys/system_properties.h>
#endif

#ifdef __linux__
#   define _BSD_SOURCE 1
#   include <sys/types.h>
#   include <netinet/in.h>
#   include <arpa/nameser.h>
#   include <resolv.h>
#   if !defined(__NetBSD__) && !defined(__OpenBSD__)
#       define _DEFAULT_SOURCE 1
#   endif
ErrnoT ResolveDNS(char *domain,
               SizeT dsize,
               SocketAddressT *nsv,
               SizeT *n);
#endif

#ifdef WIN32
#   include <winsock2.h>
#ifdef OS_TYPE_DESKTOP
#   include <iphlpapi.h>
#endif
#   include <io.h>
int WindowsDNS(char *domain,
               SizeT dsize,
               SocketAddressT *nav,
               SizeT *n);
#endif

#ifdef DARWIN
#   define __CF_USE_FRAMEWORK_INCLUDES__
#   include <SystemConfiguration/SystemConfiguration.h>

int DarwinDNS(char *domain,
              SizeT dsize,
              SocketAddressT *nsv,
              SizeT *n);
#endif

ErrnoT DNSDomianAndServerNamesGet(char *domain,
                               SizeT dsize,
                               SocketAddressT *srvv,
                               SizeT *n);

#endif
