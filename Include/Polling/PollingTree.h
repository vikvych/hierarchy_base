#ifndef HIERARCHY_POLLING_SOCKET_H
#define HIERARCHY_POLLING_SOCKET_H

#include "Polling.h"

void PollingTreeGetSocketId(ByteT *Data,
                            SOCKET Socket);

ErrnoT PollingTreeInsert(PollingLoopT *PollingLoop,
                         SOCKET Socket,
                         PollingSocketFlagsT SocketFlags,
                         PollingSocketCb *SocketCb,
                         void *Argument);

void PollingTreeRemove(PollingLoopT *PollingLoop,
                       SOCKET Socket);

PollingSocketT *PollingTreeGetPollingSocket(PollingLoopT *PollingLoop,
                                            SOCKET Socket);

#endif
