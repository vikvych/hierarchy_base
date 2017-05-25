#ifndef HIERARCHY_HWS_ACCEPT_H
#define HIERARCHY_HWS_ACCEPT_H

#include "HWS.h"
#include "HWSConnection.h"
#include "HWSSocket.h"
#include "HWSServer.h"

ErrnoT HWSAccept(HWSServerT *HWSSocket,
                 HWSConnectionT *HWSClient,
                 ObjectT *WSMessage,
                 HWSServerDataCb *DataCb,
                 HWSServerCloseCb *CloseCb,
                 void *Argument);

#endif
