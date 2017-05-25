#ifndef HIERARCHY_TCP_LIB_H
#define HIERARCHY_TCP_LIB_H

#include "TCPConnection.h"
#include "TCP.h"

extern const struct TCPLibrary {
    TCPSocketT *(*Listen)(const SocketAddressT *Address,
                          TCPConnectionCb *ConnectionCb,
                          void *Argument);

    TCPConnectionT *(*Connect)(SocketAddressT *Address,
                               TCPOpenCb *OpenCb,
                               TCPDataCb *DataCb,
                               TCPCloseCb *CloseCb,
                               void *Argument);
    struct {
        ErrnoT (*Send)(TCPConnectionT *TCPConnection,
                       MemoryBufferT *Data);
    } Connection;

    struct {
        TCPBridgeT *(*Register)(TCPConnectionT *TCPConnection,
                                SSizeT Priority,
                                TCPBridgeOpenCb *OpenCb,
                                TCPBridgeSendCb *SendCb,
                                TCPBridgeDataCb *DataCb,
                                void *Argument);

        ErrnoT (*Send)(TCPConnectionT *TCPConnection,
                       MemoryBufferT *Data,
                       TCPBridgeT *TCPBridge);
    } Bridge;
} TCPLib;

#endif
