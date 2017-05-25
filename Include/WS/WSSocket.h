#ifndef HIERARCHY_WS_SOCKET_H
#define HIERARCHY_WS_SOCKET_H

#include "WS.h"

typedef void (WSSocketShutdownCb)(void *ShutdownArg);

typedef struct {
    bool ShutdownCbProcess;
    WSSocketShutdownCb *ShutdownCb;
    void *ShutdownArg;
} WSSocketT;

void WSSocketShutdown(WSSocketT *WSSocket);
WSSocketT *WSSocketInit(WSSocketShutdownCb *ShutdownCb, void *ShutdownArg);

#endif
