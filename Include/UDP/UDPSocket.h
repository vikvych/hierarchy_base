#ifndef HIERARCHY_UDP_SOCKET_H
#define HIERARCHY_UDP_SOCKET_H

#define _BSD_SOURCE 1
#define _DEFAULT_SOURCE 1

#include <stdlib.h>
#include <string.h>

#ifdef HAVE_IO_H
#include <io.h>
#endif

#ifndef WIN32
#define __USE_POSIX 1
#define __USE_XOPEN2K 1
#include <netdb.h>
#endif

#ifdef __APPLE__
#include "TargetConditionals.h"
#endif

#include "../Memory/MemoryLib.h"
#include "../MemoryBuffer/MemoryBufferLib.h"
#include "../List/ListLib.h"
#include "../Polling/PollingLib.h"
#include "../SocketAddress/SocketAddressLib.h"
#include "../Network/NetworkLib.h"

#define UDP_INPUT_CHUNK_SIZE_LIMIT 8192

typedef void (UDPDataCb)(SocketAddressT *SourceAddress,
                         MemoryBufferT *ReceivedData,
                         void *Argument);

typedef void (UDPErrorCb)(ErrnoT Error,
                          void *Argument);

typedef struct {
    ListT UDPBridges;
    UDPDataCb *DataCb;
    UDPErrorCb *ErrorCb;
    void *Argument;
    SOCKET IPv4Socket;
    SOCKET IPv6Socket;
    bool FlagConnected;
    DWordT IncomingChunkSizeMax;
    DWordT IncomingChunkSizeOffset;
} UDPSocketT;

UDPSocketT *UDPSocketListen(const SocketAddressT *ListenAddress,
                            UDPDataCb *DataCallback,
                            void *Argument);

ErrnoT UDPSocketConnect(UDPSocketT *UDPSocket,
                        const SocketAddressT *PeerAddress);

ErrnoT UDPSendInner(UDPSocketT *UDPSocket,
                    const SocketAddressT *DestAddress,
                    MemoryBufferT *Data,
                    ListNodeT *UDPBridgeNode);

ErrnoT UDPSocketSend(UDPSocketT *UDPSocket,
                     const SocketAddressT *DestAddress,
                     MemoryBufferT *Data);

ErrnoT UDPSocketSendAnonymous(const SocketAddressT *DestAddress,
                              MemoryBufferT *Data);

ErrnoT UDPSocketLocalAddressGet(const UDPSocketT *UDPSocket,
                                SocketAddressT *LocalAddress);

ErrnoT UDPSocketOptionSet(UDPSocketT *UDPSocket,
                          int Level,
                          int OptionKey,
                          const void *OptionValue,
                          DWordT OptionLength);

ErrnoT UDPSocketBufferSizeSet(UDPSocketT *UDPSocket,
                              DWordT BufferSize);

void UDPSocketIncomingChunkSizeMaxSet(UDPSocketT *UDPSocket,
                                      DWordT IncomingChunkSizeMax);

void UDPSocketIncomingChunkSizeOffsetSet(UDPSocketT *UDPSocket,
                                         DWordT IncomingChunkSizeOffset);

void UDPSocketDataCallbackSet(UDPSocketT *UDPSocket,
                              UDPDataCb *DataCallback,
                              void *Argument);

void UDPSocketErrorCallbackSet(UDPSocketT *UDPSocket,
                               UDPErrorCb *ErrorCallback);

ErrnoT UDPSocketPollingStart(UDPSocketT *UDPSocket);

void UDPSocketPollingStop(UDPSocketT *UDPSocket);

SOCKET UDPSocketGetSocket(const UDPSocketT *UDPSocket,
                          int AddressFamily);


#endif
