#ifndef HIERARCHY_WS_ACCEPT_H
#define HIERARCHY_WS_ACCEPT_H

#include "WS.h"
#include "WSConnection.h"

ErrnoT WSAcceptPrintCb(PrintT *Print,
                       const MemoryBlockT *SecWebSocketKey);

WSConnectionT *WSAccept(WSSocketT *WSSocket,
                        HTTPConnectionT *HTTPConnection,
                        HTTPMessageT *HTTPMessage,
                        DWordT KeepAliveInterval,
                        WSDataCb *DataCallback,
                        WSCloseCb *CloseCallback,
                        void *Argument);

#endif
