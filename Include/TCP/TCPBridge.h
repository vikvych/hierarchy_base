#ifndef HIERARCHY_TCP_BRIDGE_H
#define HIERARCHY_TCP_BRIDGE_H

#include "TCPConnection.h"

typedef bool (TCPBridgeOpenCb)(ErrnoT *Error,
                               bool FlagActive,
                               void *Argument);

typedef bool (TCPBridgeSendCb)(ErrnoT *Error,
                               MemoryBufferT *Data,
                               void *Argument);

typedef bool (TCPBridgeDataCb)(ErrnoT *Error,
                               MemoryBufferT *Data,
                               bool *TCPBridgeOpened,
                               void *Argument);


typedef struct {
    ListNodeT BridgeNode;
    SSizeT Priority;
    TCPBridgeOpenCb *BridgeOpenCallback;
    TCPBridgeSendCb *BridgeSendCallback;
    TCPBridgeDataCb *BridgeDataCallback;
    void *Argument;
} TCPBridgeT;

TCPBridgeT *TCPBridgeRegister(TCPConnectionT *TCPConnection,
                              SSizeT Priority,
                              TCPBridgeOpenCb *OpenCb,
                              TCPBridgeSendCb *SendCb,
                              TCPBridgeDataCb *DataCb,
                              void *Argument);

ErrnoT TCPBridgeSend(TCPConnectionT *TCPConnection,
                     MemoryBufferT *Data,
                     TCPBridgeT *TCPBridge);

#endif
