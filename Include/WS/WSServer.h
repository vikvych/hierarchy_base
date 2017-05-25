#ifndef HIERARCHY_WS_SERVER_H
#define HIERARCHY_WS_SERVER_H

#include "WS.h"
#include "WSConnection.h"
#include "../CString/CStringLib.h"

typedef void (WSServerOpenCb)(void *WSServerV,
                              WSConnectionT *ClientConnection);

typedef void (WSServerDataCb)(void *WSServerV,
                              WSConnectionT *ClientConnection,
                              MemoryBufferT *Data);

typedef void (WSServerCloseCb)(void *WSServerV,
                               WSConnectionT *ClientConnection,
                               ErrnoT Error);

typedef void (WSServerShutdownCb)(void *WSServerV);

typedef struct {
    WSSocketT *Socket;
    char *ExptecetedIP;
    DWordT KeepAliveInterval;
    WSServerOpenCb *OpenCb;
    WSServerDataCb *DataCb;
    WSServerCloseCb *CloseCb;
    WSServerShutdownCb *ShutdownCb;

    void *Argument;
} WSServerT;

WSServerT *WSServerInit(char *ServerAddressString,
                        WordT Port,
                        DWordT KeepAliveInterval,
                        WSServerOpenCb OpenCb,
                        WSServerDataCb DataCb,
                        WSServerCloseCb CloseCb,
                        WSServerShutdownCb ShutdownCb,
                        char *ExpectedIP,
                        void *Argument);

#endif
