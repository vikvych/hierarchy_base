#ifndef HIERARCHYBASE_SSL_DTLS_H
#define HIERARCHYBASE_SSL_DTLS_H

#include "SSL.h"
#include "../UDP/UDPLib.h"
#include "../Debug/DebugLib.h"
#include "../BinaryTree/BinaryTreeLib.h"
#include "../Timer/TimerLib.h"

#define DTLS_MTU_DEFAULT 1400
#define DTLS_MTU_FALLBACK 548

typedef void (DTLSConnectionCallbackT)(const SocketAddressT *peer,
                                       void *Argument);

typedef void (DTLSOpenCallbackT)(void *Argument);

typedef void (DTLSDataCallbackT)(MemoryBufferT *Data, void *Argument);

typedef void (DTLSCloseCallbackT)(int32_t Error, void *Argument);

typedef struct {
    SocketAddressT Address;
    UDPBridgeT *UDPBridge;
    UDPSocketT *UDPSocket;
    BinaryTreeT *Connections;
    MemoryBufferT *mb;
    DTLSConnectionCallbackT *ConnectionCb;
    void *Argument;
    uint32_t MTU;
} DTLSSocketT;

typedef struct {
    SSL *SSL;
    BIO *sbio_out;
    BIO *sbio_in;
    TimerT Timer;
    SocketAddressT Address;
    DTLSSocketT *Socket;
    DTLSOpenCallbackT *OpenCallback;
    DTLSDataCallbackT *DataCb;
    DTLSCloseCallbackT *CloseCallback;
    void *Argument;
    bool ConnectingFlag;
    bool up;
} DTLSConnectionT;

DTLSSocketT *DTLSListen(const SocketAddressT *ListenAddress,
                        UDPSocketT *UDPSocket,
                        int32_t ProtocolLayer,
                        DTLSConnectionCallbackT *ConnectionCallback,
                        void *Argument);

UDPSocketT *DTLSSocketUDPSocketGet(DTLSSocketT *DTLSSocket);

void DTLSSocketMTUSet(DTLSSocketT *DTLSSocket, uint32_t MTU);

int32_t DTLSConnectionConnect(DTLSConnectionT **DTLSConnectionPtr,
                              SSLContextT *SSLContext,
                              DTLSSocketT *DTLSSocket,
                              const SocketAddressT *peer,
                              DTLSOpenCallbackT *OpenCallback,
                              DTLSDataCallbackT *DataCallback,
                              DTLSCloseCallbackT *CloseCallback,
                              void *Argument);

int32_t DTLSConnectionAccept(DTLSConnectionT **DTLSConnectionPtr,
                             SSLContextT *SSLContext,
                             DTLSSocketT *DTLSSocket,
                             DTLSOpenCallbackT *OpenCallback,
                             DTLSDataCallbackT *DataCallback,
                             DTLSCloseCallbackT *CloseCallback,
                             void *Argument);

int32_t DTLSConnectionSend(DTLSConnectionT *DTLSConnection,
                           MemoryBufferT *Data);

void DTLSConnectionSetCallbacks(DTLSConnectionT *DTLSConnection,
                               DTLSOpenCallbackT *OpenCallback,
                               DTLSDataCallbackT *DataCallback,
                               DTLSCloseCallbackT *CloseCallback,
                               void *Argument);

#endif
