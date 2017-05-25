#ifndef HIERARCHY_POLLING_H
#define HIERARCHY_POLLING_H

#include "PollingPoll.h"
#include "../Timer/TimerLib.h"

#define POLLING_SOCKET_SIZE_MAX 8
#define POLLING_LOOP_MAX_FD_COUNT 1024
#define POLLING_MAX_BLOCKING_MS 1000
#define POLLING_IDLE_SLEEP_MS 1000

typedef void (PollingLoopSignalCb)(int Signal);

typedef enum {
    POLLING_SOCKET_FLAGS_NONE = 0,
#ifdef FD_READ
    POLLING_SOCKET_FLAGS_READ = FD_READ,
#else
    POLLING_SOCKET_FLAGS_READ = (1<<0),
#endif
#ifdef FD_WRITE
    POLLING_SOCKET_FLAGS_WRITE = FD_WRITE,
#else
    POLLING_SOCKET_FLAGS_WRITE = (1<<1),
#endif
    POLLING_SOCKET_FLAGS_EXCEPT = (1<<2)
} PollingSocketFlagsT;

typedef void (PollingSocketCb)(PollingSocketFlagsT Flags, void *Argument);

typedef struct {
    PollSocketT SocketList[POLLING_LOOP_MAX_FD_COUNT];
    SizeT ListSize;
} PollingSocketListT;

typedef struct {
    SOCKET Socket;
    PollingSocketFlagsT SocketFlags;
    PollingSocketCb *SocketCb;
    void *SocketArg;
} PollingSocketT;

typedef struct {
    BinaryTreeT *SocketTree;
    ListT TimerList;
    bool Active;
    int Signal;
    PollingLoopSignalCb *SignalCb;
    LockT *Lock;
//TODO Child Polling
} PollingLoopT;

ErrnoT PollingGlobalInit(void);

ErrnoT PollingGlobalDestroy(void);

PollingLoopT *PollingLoopInit();

void PollingLoopDestroy(void *PollingLoopV);

PollingLoopT *PollingLoopGet(void);

ListT *PollingLoopTimerListGet(PollingLoopT *PollingLoop);

ErrnoT PollingLoopStart(PollingLoopT *PollingLoop,
                        PollingLoopSignalCb *SignalCb);

void PollingLoopStop(PollingLoopT *PollingLoop);

ErrnoT PollingLoopProcess(PollingLoopT *PollingLoop);

void PollingLoopDebug(PollingLoopT *PollingLoop);

#endif
