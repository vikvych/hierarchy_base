#ifndef HIERARCHY_NETWORK_INTERFACE_H
#define HIERARCHY_NETWORK_INTERFACE_H

#include "NetworkIncludes.h"
#include "NetworkSockets.h"
#include "../SocketAddress/SocketAddress.h"
#include "../Debug/DebugLib.h"
#include "../System/SystemLib.h"

#if defined(TARGET_IPHONE_SIMULATOR) || defined(TARGET_OS_IPHONE)
#include <unistd.h>
#endif

typedef struct {
    bool Found;
    char *InterfaceName;
    SizeT InterfaceNameSize;
    int AddressFamily;
    SocketAddressT *IPAddress;
} NetworkIFAddressT;

typedef bool (NetworkIFAddressCb)(const char *InterfaceName,
                                  SocketAddressT *SocketAddress,
                                  void *Argument);

#ifndef WIN32
#ifdef ANDROID
struct ifaddrs {
    struct ifaddrs  *ifa_next;
    char		*ifa_name;
    unsigned int	 ifa_flags;
    struct sockaddr	*ifa_addr;
    struct sockaddr	*ifa_netmask;
    struct sockaddr	*ifa_dstaddr;
    void		*ifa_data;
};

#ifndef	ifa_broadaddr
#define	ifa_broadaddr ifa_dstaddr
#endif

int getifaddrs(struct ifaddrs **ifap);
void freeifaddrs(struct ifaddrs *ifa);
#endif

ErrnoT NetworkIFGetIFAddrs(NetworkIFAddressCb *IFAddressCb,
                                  void *Argument);
#endif

#if SYSTEM_TYPE == SYSTEM_TYPE_DESKTOP
ErrnoT NetworkIFList(NetworkIFAddressCb *IFAddressCb,
                     void *Argument);
#endif

ErrnoT NetworkIFNameGet(char *InterfaceName,
                        SizeT InterfaceNameSize,
                        int AddressFamily,
                        SocketAddressT *IP);

ErrnoT NetworkIFAddressGet(SocketAddressT *IP,
                           const char *InterfaceName,
                           int AddressFamily);

#if SYSTEM_FAMILY != SYSTEM_FAMILY_WINDOWS
ErrnoT NetworkIFIPv4AddressGet(const char *InterfaceName,
                               int AddressFamily,
                               SocketAddressT *IP);
#endif

ErrnoT NetworkIFEach(NetworkIFAddressCb *IFAddressCb,
                     void *Argument);

ErrnoT NetworkIFPrint(PrintT *Print,
                      void *Argument);

ErrnoT NetworkIFLinkLocalAddressGet(const char *InterfaceName,
                                    int AddressFamily,
                                    SocketAddressT *IP);


#endif
