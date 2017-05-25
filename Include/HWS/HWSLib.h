#ifndef HIERARCHY_HWS_LIB_H
#define HIERARCHY_HWS_LIB_H

#include "HWS.h"
#include "HWSAccept.h"
#include "HWSConnect.h"
#include "HWSConnection.h"
#include "HWSRecv.h"
#include "HWSSend.h"
#include "HWSSocket.h"
#include "HWSServer.h"

extern const struct HWSLibrary {
    HWSSocketT *(*Init)(HWSSocketShutdownCb *ShutdownCb,
                              void *ShutdownArg);

    void (*Shutdown)(void *HWSSocketV);

    HWSConnectionT *(*Connect)(HWSSocketT *HWSSocket,
                               char *Host,
                               WordT Port,
                               char *Path,
                               char *UA,
                               char *DNSAddress,
                               WordT DNSPort,
                               ECCryptoModeT CryptoMode,
                               char *RootPublicKeyX,
                               char *RootPublicKeyY,
                               HWSOpenCb *OpenCb,
                               HWSDataCb *DataCb,
                               HWSCloseCb *CloseCb,
                               DWordT KeepAliveInterval,
                               void *Argument);

    ErrnoT (*Send)(HWSConnectionT *Connection,
                   MemoryBufferT *Data);

    ErrnoT (*SendObject)(HWSConnectionT *HWSConnection,
                         ObjectT *Data);

    ErrnoT (*Close)(HWSConnectionT *HWSConnection,
                    WSCloseCodeT CloseCode,
                    const char *Format, ...);

    ErrnoT (*Address)(char *RemoteAddress,
                      const HWSConnectionT *WSConnection);

    HWSServerT *(*Server)(char *ServerAddressString,
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

    void (*ServerConnectableSet)(HWSServerT *Server, bool IsConnectable);
} HWSLib;


#endif
