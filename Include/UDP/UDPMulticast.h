#ifndef HIERARCHY_UDP_MULTICAST_H
#define HIERARCHY_UDP_MULTICAST_H

#include "../UDP/UDPSocket.h"

ErrnoT UDPMulticastJoin(UDPSocketT *UDPSocket,
                        const SocketAddressT *GroupAddress);

ErrnoT UDPMulticastLeave(UDPSocketT *UDPSocket,
                         const SocketAddressT *GroupAddress);

#endif
