#ifndef HIERARCHY_UDP_BRIDGE_H
#define HIERARCHY_UDP_BRIDGE_H

#include "UDPSocket.h"

typedef bool (UDPBridgeSendCb)(ErrnoT *Error,
                               SocketAddressT *DestAddress,
                               MemoryBufferT *Data,
                               void *Argument);

typedef bool (UDPBridgeDataCb)(SocketAddressT *SourceAddress,
                               MemoryBufferT *Data,
                               void *Argument);

typedef struct {
    ListNodeT BridgeNode;
    SSizeT Priority;
    UDPBridgeSendCb *SendCb;
    UDPBridgeDataCb *DataCb;
    void *Argument;
} UDPBridgeT;

void UDPBridgeDestroy(void *UDPBridgeVoid);

UDPBridgeT *UDPBridgeRegister(UDPSocketT *UDPSocket,
                              SSizeT Priority,
                              UDPBridgeSendCb *BridgeSendCb,
                              UDPBridgeDataCb *BridgeDataCb,
                              void *Argument);

ErrnoT UDPBridgeSend(UDPSocketT *UDPSocket,
                     const SocketAddressT *DestAddress,
                     MemoryBufferT *Data,
                     UDPBridgeT *UDPBridge);

#endif
