#ifndef HIERARCHY_WS_CONNECT_H
#define HIERARCHY_WS_CONNECT_H

#include "WS.h"
#include "WSConnection.h"

WSConnectionT *WSConnect(WSSocketT *WSSocket,
                         HTTPClientT *HTTPClient,
                         const char *URI,
                         DWordT KeepAliveInterval,
                         WSOpenCb *OpenCallback,
                         WSDataCb *DataCallback,
                         WSCloseCb *CloseCallback,
                         void *Argument,
                         const char *Format,
                         ...);

#endif
