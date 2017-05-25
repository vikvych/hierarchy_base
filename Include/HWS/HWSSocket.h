#ifndef HIERARCHY_HWS_SOCKET_H
#define HIERARCHY_HWS_SOCKET_H

#include "HWS.h"

typedef void (HWSSocketShutdownCb)(void *ShutdownArg);

typedef struct {
    WSSocketT *WSSocket;
    bool ShutdownCbProcess;
    HWSSocketShutdownCb *ShutdownCb;
    void *ShutdownArg;
} HWSSocketT;

void HWSSocketShutdown(void *HWSSocketV);
HWSSocketT *HWSSocketInit(HWSSocketShutdownCb *ShutdownCb,
                          void *ShutdownArg);


#endif
