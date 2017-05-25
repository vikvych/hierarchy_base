#ifndef HIERARCHY_UDP_LIB_H
#define HIERARCHY_UDP_LIB_H

#include "UDPSocket.h"
#include "UDPMulticast.h"
#include "UDPBridge.h"

extern const struct UDPLibrary {
    struct {
        UDPSocketT *(*Listen)(const SocketAddressT *ListenAddress,
                              UDPDataCb *DataCallback,
                              void *Argument);

        ErrnoT (*Connect)(UDPSocketT *UDPSocket,
                          const SocketAddressT *PeerAddress);

        ErrnoT (*Send)(UDPSocketT *UDPSocket,
                       const SocketAddressT *DestAddress,
                       MemoryBufferT *Data);

        ErrnoT (*SendAnonymous)(const SocketAddressT *DestAddress,
                                MemoryBufferT *Data);

        ErrnoT (*LocalAddressGet)(const UDPSocketT *UDPSocket,
                                  SocketAddressT *LocalAddress);

        ErrnoT (*OptionSet)(UDPSocketT *UDPSocket,
                            int Level,
                            int OptionKey,
                            const void *OptionValue,
                            DWordT OptionLength);

        ErrnoT (*BufferSizeSet)(UDPSocketT *UDPSocket,
                                DWordT BufferSize);

        void (*IncomingChunkSizeMaxSet)(UDPSocketT *UDPSocket,
                                        DWordT IncomingChunkSizeMax);

        void (*IncomingChunkSizeOffsetSet)(UDPSocketT *UDPSocket,
                                           DWordT IncomingChunkSizeOffset);

        void (*DataCallbackSet)(UDPSocketT *UDPSocket,
                                UDPDataCb *DataCallback,
                                void *Argument);

        void (*ErrorCallbackSet)(UDPSocketT *UDPSocket,
                                 UDPErrorCb *ErrorCallback);

        ErrnoT (*PollingStart)(UDPSocketT *UDPSocket);

        void (*PollingStop)(UDPSocketT *UDPSocket);

        SOCKET (*SocketGet)(const UDPSocketT *UDPSocket,
                            int AddressFamily);
    } Socket;

    struct {
        ErrnoT (*Join)(UDPSocketT *UDPSocket,
                        const SocketAddressT *GroupAddress);

        ErrnoT (*Leave)(UDPSocketT *UDPSocket,
                         const SocketAddressT *GroupAddress);
    } Nulticast;

    struct {
        UDPBridgeT *(*Register)(UDPSocketT *UDPSocket,
                                SSizeT Priority,
                                UDPBridgeSendCb *BridgeSendCallback,
                                UDPBridgeDataCb *BridgeDataCallback,
                                void *Argument);

        ErrnoT (*Send)(UDPSocketT *UDPSocket,
                       const SocketAddressT *DestAddress,
                       MemoryBufferT *Data,
                       UDPBridgeT *UDPBridge);
    } Bridge;
} UDPLib;

#endif
