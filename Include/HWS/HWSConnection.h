#ifndef HIERARCHY_HWS_CONNECTION_H
#define HIERARCHY_HWS_CONNECTION_H

#include "HWS.h"
#include "HWSSocket.h"

typedef struct {
    HWSSocketT *HWSSocket;

    WSConnectionT *WSConnection;

    HTTPClientT *HTTPClient;
    DNSClientT *DNSClient;

    HWSOpenCb *OpenCb;
    HWSDataCb *DataCb;
    HWSCloseCb *CloseCb;

    void *Argument;

    HWSStateT State;


    ECCryptoModeT ContextMode;
    ECGamalContextT *LocalContext;
    DWordT LocalIdCounter;
    ECGamalContextT *RemoteContext;
    DWordT RemoteIdCounter;

    MemoryBufferT *HandshakeStampData;

    void *ParentServer;

    QWordT ConnectTimestamp;

    LockT *Lock;
} HWSConnectionT;

void HWSConnectionCloseCb(ErrnoT Error, void *HWSConnectionV);

void HWSConnectionDataCbEmpty(void *HWSConnectionV,
                              ObjectT *Data,
                              void *Argument);

void HWSConnectionWSDataCb(MemoryBufferT *Data,
                           void *HWSConnectionV);

void HWSConnectionDestroy(void *WSConnectionVoid);

void HWSConnectionClose(HWSConnectionT *WSConnection, ErrnoT Error);

ErrnoT HWSClose(HWSConnectionT *WSConnection,
               WSCloseCodeT CloseCode,
               const char *Format,
               ...);

ErrnoT HWSConnectionAddress(char *RemoteAddress, const HWSConnectionT *HWSConnection);

#endif
