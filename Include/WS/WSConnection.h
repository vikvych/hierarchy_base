#ifndef HIERARCHY_WS_CONNECTION_H
#define HIERARCHY_WS_CONNECTION_H

#include "WS.h"
#include "WSSocket.h"

typedef struct {
    TimerT KeepAliveTimer;
    SocketAddressT Address;
    char Nonce[24];
    WSSocketT *WSSocket;
    TCPConnectionT *TCPConnection;
    TLSConnectionT *TLSConnection;
    MemoryBufferT *RecvBuffer;
    HTTPRequestT *HTTPRequest;
    WSOpenCb *OpenCb;
    WSDataCb *DataCb;
    WSCloseCb *CloseCb;
    void *Argument;
    WSStateT State;
    DWordT KeepAliveInterval;
    bool IsClient;

    void *ParentServer;

    bool PongReveived;
} WSConnectionT;

void WSConnectionCloseCb(ErrnoT Error, void *WSConnectionV);

void WSConnectionKeepAliveCb(void *WSConnectionV);

void WSConnectionDataCbEmpty(const WSHeaderT *WSHeader,
                             MemoryBufferT *Data,
                             void *Argument);

void WSConnectionCloseCbEmpty(ErrnoT Error,
                              void *WSConnectionV);

void WSConnectionTimeoutCb(void *WSConnectionVoid);

void WSConnectionDestroy(void *WSConnectionV);

void WSConnectionClose(WSConnectionT *WSConnection, ErrnoT Error);

ErrnoT WSClose(WSConnectionT *WSConnection,
               WSCloseCodeT CloseCode,
               const char *Format,
               ...);

const SocketAddressT *WSConnectionAddress(const WSConnectionT *WSConnection);


#endif
