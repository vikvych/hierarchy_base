#ifndef HIERARCHY_POLLING_LIB_H
#define HIERARCHY_POLLING_LIB_H

#include "Polling.h"
#include "PollingPoll.h"
#include "PollingTree.h"

extern const struct PollingLibrary {
    struct {
        ErrnoT (*Init)(void);
        ErrnoT (*Destroy)(void);
    } Global;

    struct {
        PollingLoopT *(*Init)();

        PollingLoopT *(*Get)(void);

        ListT *(*TimerListGet)(PollingLoopT *PollingLoop);

        ErrnoT (*Start)(PollingLoopT *PollingLoop,
                        PollingLoopSignalCb *SignalCallback);

        void (*Stop)(PollingLoopT *PollingLoop);
        void  (*Debug)(PollingLoopT *PollingLoop);

    } Loop;

    struct {
        ErrnoT (*Insert)(PollingLoopT *PollingLoop,
                         SOCKET Socket,
                         PollingSocketFlagsT SocketFlags,
                         PollingSocketCb *SocketCb,
                         void *Argument);

        void (*Remove)(PollingLoopT *PollingLoop,
                       SOCKET Socket);
    } Tree;
} PollingLib;

#endif
