#ifndef HIERARCHY_TCP_CONNECTION_H
#define HIERARCHY_TCP_CONNECTION_H

#include "TCPSocket.h"

#define TCP_INPUT_CHUNK_SIZE_LIMIT 10 * 1024
#define TCP_OUTPUT_QUEUE_SIZE_LIMIT 524288

typedef void (TCPOpenCb)(void *Argument);

typedef void (TCPSendCallbackT)(void *Argument);

typedef void (TCPDataCb)(MemoryBufferT *ReceivedData,
                                void *Argument);

typedef void (TCPCloseCb)(ErrnoT Error,
                                 void *Argument);


typedef struct {
    ListT TCPBridges;
    ListT OutputQueue;
    SOCKET Socket;
    TCPOpenCb *OpenCallback;
    TCPSendCallbackT *SendCallback;
    TCPDataCb *DataCallback;
    TCPCloseCb *CloseCallback;
    void *Argument;
    SizeT InputChunkSizeLimit;
    SizeT OutputQueueSize;
    SizeT OutputQueueSizeLimit;

    bool ConnectingFlag;
    bool ConnectedFlag;
} TCPConnectionT;

#include "TCPQueue.h"
#include "TCPBridge.h"

TCPConnectionT *TCPConnectionInit(const SocketAddressT *InitAddress,
                                  TCPOpenCb *OpenCallback,
                                  TCPDataCb *DataCallback,
                                  TCPCloseCb *CloseCallback,
                                  void *Argument);

void TCPConnectionClose(TCPConnectionT *TCPConnection,
                        ErrnoT Error);

ErrnoT TCPConnectionBind(TCPConnectionT *TCPConnection,
                           const SocketAddressT *BindAddress);

ErrnoT TCPConnectionConnect(TCPConnectionT *TCPConnection,
                             const SocketAddressT *ConnectionAddress);

ErrnoT TCPConnectionSend(TCPConnectionT *TCPConnection,
                          MemoryBufferT *Data);

ErrnoT TCPConnectionSetSendCallback(TCPConnectionT *TCPConnection,
                                     TCPSendCallbackT *SendCallback);

void TCPConnectionSetCallbacks(TCPConnectionT *TCPConnection,
                      TCPOpenCb *OpenCallback,
                      TCPDataCb *DataCallback,
                      TCPCloseCb *TCPCloseCallback,
                      void *Argument);


ErrnoT TCPConnectionLocalAddressGet(const TCPConnectionT *TCPConnection,
                        SocketAddressT *ConnectionAddress);

ErrnoT TCPConnectionRemoteAddressGet(const TCPConnectionT *TCPConnection,
                       SocketAddressT *ConnectionAddress);

SOCKET TCPConnectionSocketGet(const TCPConnectionT *TCPConnection);

void TCPConnectionInputChunkSizeLimitSet(TCPConnectionT *TCPConnection,
                                        SizeT InputDataChunkSize);

SizeT TCPConnectionInputChunkSizeLimitGet(const TCPConnectionT *TCPConnection);

void TCPConnectionOutputQueueSizeLimitSet(TCPConnectionT *TCPConnection,
                                  SizeT OutputQueueSize);

SizeT TCPConnectionOutputQueueSizeGet(const TCPConnectionT *TCPConnection);

ErrnoT TCPConnectionAccept(TCPConnectionT **TCPConnectionPtr,
                            TCPSocketT *TCPSocket,
                            TCPOpenCb *OpenCallback,
                            TCPDataCb *RecvCallback,
                            TCPCloseCb *CloseCallback,
                            void *Argument);

ErrnoT TCPConnectionSendData(TCPConnectionT *TCPConnection,
                              MemoryBufferT *Data,
                              ListNodeT *TCPBridgeLastNode);

#endif
