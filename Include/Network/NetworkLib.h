#ifndef HIERARCHY_NETWORK_LIB_H
#define HIERARCHY_NETWORK_LIB_H

#include "Network.h"
#include "../System/SystemLib.h"

extern const struct NetworkLibrary {
    struct {
        ErrnoT (*Init)(void);
        void (*Destroy)(void);
    } Sockets;

    struct {
        ErrnoT (*BlockingSet)(SOCKET FD, bool Blocking);
        ErrnoT (*ReusableSet)(SOCKET FD, bool Reusable);
    } SocketOpt;

    struct {
        const char *(*ProtocolName)(int Protocol);
        const char *(*AddressFamilyName)(int AddressFamily);
    } Format;

    struct {
        int32_t (*GetName)(char *InterfaceName,
                           uint32_t InterfaceNameSize,
                           int AddressFamily,
                           SocketAddressT *IP);

        int32_t (*GetAddress)(SocketAddressT *IP,
                              const char *InterfaceName,
                              int AddressFamily);

        #if SYSTEM_TYPE == SYSTEM_TYPE_DESKTOP
        int32_t (*List)(NetworkIFAddressCb *InterfaceAddressCallback,
                        void *Argument);
        #endif

        int32_t (*Apply)(NetworkIFAddressCb *InterfaceAddressCallback,
                         void *Argument);

        int32_t (*Debug)(PrintT *Print, void *Argument);

        int32_t (*GetLinkLocalAddress)(const char *InterfaceName,
                                       int AddressFamily,
                                       SocketAddressT *IP);
    } IF;

    struct {
        ErrnoT (*HostIP)(SocketAddressT *IP, int AddressFamily);
        ErrnoT (*DefaultSourceIP)(SocketAddressT *IP, int AddressFamily);
        ErrnoT (*DefaultGatewayIP)(SocketAddressT *IP, int AddressFamily);
    } Address;

#if SYSTEM_TYPE == SYSTEM_TYPE_DESKTOP
    struct {
        int32_t (*TableList)(NetworkRouteCallbackT *RouteCallback,
                             void *Argument);

        int32_t (*TablePrint)(PrintT *Print,
                              void *unused);

        int32_t (*DefaultRouteName)(int AddressFamily,
                                    char *InterfaceName,
                                    uint32_t InterfaceNameLength);
    } Route;
#endif

} NetworkLib;

#endif
