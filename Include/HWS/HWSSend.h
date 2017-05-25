#ifndef HIERARCHY_HWS_SEND_H
#define HIERARCHY_HWS_SEND_H

#include "HWS.h"
#include "HWSConnection.h"

ErrnoT HWSSend(HWSConnectionT *Connection,
               MemoryBufferT *Data);

ErrnoT HWSSendObject(HWSConnectionT *HWSConnection,
                     ObjectT *Data);

#endif
