#ifndef HIERARCHY_NETWORK_H
#define HIERARCHY_NETWORK_H

#include "NetworkInterface.h"
#include "NetworkRoutingTable.h"
#include "NetworkSocketOptions.h"
#include "NetworkSockets.h"
#include "NetworkTextFormat.h"

ErrnoT NetworkHostIPAddress(SocketAddressT *IP,
                            int AddressFamily);

ErrnoT NetworkDefaultSourceIPAddress(SocketAddressT *IP,
                                     int AddressFamily);

ErrnoT NetworkDefaultGatewayIPAddress(SocketAddressT *IP,
                                      int AddressFamily);

#endif
