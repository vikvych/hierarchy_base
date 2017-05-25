#ifndef HIERARCHY_HWS_SERVER_H
#define HIERARCHY_HWS_SERVER_H

#include "HWS.h"
#include "HWSConnection.h"

typedef void (HWSServerOpenCb)(void *HWSServerV,
                               HWSConnectionT *ClientConnection);

typedef void (HWSServerDataCb)(void *HWSServerV,
                               HWSConnectionT *ClientConnection,
                               ObjectT *Data);

typedef void (HWSServerCloseCb)(void *HWSServerV,
                                HWSConnectionT *ClientConnection,
                                ErrnoT Error);

typedef void (HWSServerShutdownCb)(void *HWSServerV);

typedef struct {
    WSSocketT *Socket;
    DWordT KeepAliveInterval;
    HWSServerOpenCb *OpenCb;
    HWSServerDataCb *DataCb;
    HWSServerCloseCb *CloseCb;
    HWSServerShutdownCb *ShutdownCb;

    ECGamalContextT *ECContext256;
    ECGamalContextT *ECContext384;
    ECGamalContextT *ECContext521;

    bool IsConnectable;
    void *Argument;
} HWSServerT;

HWSServerT *HWSServerInit(char *ServerAddressString,
                          WordT Port,
                          DWordT KeepAliveInterval,
                          HWSServerOpenCb OpenCb,
                          HWSServerDataCb DataCb,
                          HWSServerCloseCb CloseCb,
                          HWSServerShutdownCb ShutdownCb,
                          char *ECContextPrivateKey256,
                          char *ECContextPrivateKey384,
                          char *ECContextPrivateKey521,
                          void *Argument);

void HWSServerConnectableSet(HWSServerT *Server, bool IsConnectable);

#endif
