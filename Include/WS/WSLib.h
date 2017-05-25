#ifndef HIERARCHY_WS_LIB_H
#define HIERARCHY_WS_LIB_H

#include "WS.h"
#include "WSAccept.h"
#include "WSConnect.h"
#include "WSConnection.h"
#include "WSSend.h"
#include "WSSocket.h"
#include "WSServer.h"

extern const struct WSLibrary {
    WSSocketT *(*Init)(WSSocketShutdownCb *ShutdownCb, void *Argument);
    void (*Shutdown)(WSSocketT *WSSocket);

    WSConnectionT *(*Connect)(WSSocketT *WSSocket,
                              HTTPClientT *HTTPClient,
                              const char *URI,
                              DWordT KeepAliveInterval,
                              WSOpenCb *OpenCb,
                              WSDataCb *DataCb,
                              WSCloseCb *CloseCb,
                              void *Argument,
                              const char *Format,
                              ...);

    WSConnectionT *(*Accept)(WSSocketT *WSSocket,
                             HTTPConnectionT *HTTPConnection,
                             HTTPMessageT *HTTPMessage,
                             DWordT KeepAliveInterval,
                             WSDataCb *DataCb,
                             WSCloseCb *CloseCb,
                             void *Argument);

    ErrnoT (*Send)(WSConnectionT *WSConnection,
                   WSOpCodeT OpCode,
                   const char *Format,
                   ...);

    ErrnoT (*Close)(WSConnectionT *WSConnection,
                    WSCloseCodeT CloseCode,
                    const char *Format,
                    ...);

    const SocketAddressT *(*Address)(const WSConnectionT *WSConnection);

    WSServerT *(*Server)(char *ServerAddressString,
                         WordT Port,
                         DWordT KeepAliveInterval,
                         WSServerOpenCb OpenCb,
                         WSServerDataCb DataCb,
                         WSServerCloseCb CloseCb,
                         WSServerShutdownCb ShutdownCb,
                         char *ExpectedIP,
                         void *Argument);
} WSLib;

#endif
