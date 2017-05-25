#ifndef HIERARCHY_TCP_QUEUE_H
#define HIERARCHY_TCP_QUEUE_H

#include "../MemoryBuffer/MemoryBufferLib.h"
#include "../List/ListLib.h"

typedef struct {
    ListNodeT  Element;
    MemoryBufferT Data;
} TCPQueueElementT;

#include "TCPConnection.h"

void TCPConnecionOnDataCb(PollingSocketFlagsT FDFlags, void *TCPConnectionVoid);

void TCPQueueElementDestroy(void *TCPQueueElementVoid);

ErrnoT TCPQueuePush(TCPConnectionT *TCPConnection,
                     MemoryBufferT *Data);

ErrnoT TCPQueuePop(TCPConnectionT *TCPConnection);

#endif
