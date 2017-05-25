#ifndef HIERARCHY_NETWORK_ROUTING_TABLE_H
#define HIERARCHY_NETWORK_ROUTING_TABLE_H

#include "NetworkIncludes.h"
#include "../SocketAddress/SocketAddressLib.h"
#include "../System/SystemLib.h"

extern void *NONULLIOS4;
#if defined(__linux__)
#include <linux/netlink.h>
#include <linux/rtnetlink.h>
#else
#define IFNAMSIZ 16
#endif
#if defined(__linux__) || defined(WIN32)
typedef struct {
    int dstlen;
    char ifname[IFNAMSIZ];
    SocketAddressT Dest;
    SocketAddressT GW;
} NetworkRouteT;

typedef struct {
    int af;
    char *ifname;
    SizeT size;
    int prefix;
} NetworkRoutingTableT;

#endif

#ifdef __APPLE__
#include <net/if.h>
#ifdef OS_TYPE_DESKTOP
#include <net/route.h>
#endif
typedef struct {
    int af;
    char *ifname;
    SizeT size;
    int prefix;
} NetworkRoutingTableT;
#endif


typedef bool (NetworkRouteCallbackT)(const char *InterfaceName,
                                     const SocketAddressT *Destination,
                                     int32_t DestinationLength,
                                     const SocketAddressT *Gateway,
                                     void *Argument);

#ifdef OS_TYPE_DESKTOP
int32_t NetworkRouteTableList(NetworkRouteCallbackT *RouteCallback,
                              void *Argument);

int32_t NetworkRouteDefaultRouteName(int AddressFamily,
                                     char *InterfaceName,
                                     uint32_t InterfaceNameLength);

int32_t NetworkRouteTablePrint(PrintT *Print,
                                 void *unused);

#endif

#endif
