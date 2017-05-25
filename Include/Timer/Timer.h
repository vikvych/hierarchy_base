#ifndef HIERARCHYBASE_TIMER_H
#define HIERARCHYBASE_TIMER_H

#include <string.h>

#include "../Polling/PollingPoll.h"
#include "../List/ListLib.h"
#include "../Memory/MemoryLib.h"
#include "../Debug/DebugLib.h"
#include "../Print/PrintLib.h"

typedef void (TimerCallbackT)(void *Argument);

typedef struct {
    ListNodeT ListNode;
    TimerCallbackT *PrintVCb;
    void *Argument;
    QWordT ExpireTime;
} TimerT;


void TimersPolling(ListT *TimerList);
QWordT TimerNextTimerExpireTimeLeft(ListT *TimerList);
void TimerListPrint(void);
ErrnoT TimerListPrintCallback(PrintT *Print, void *Argument);
void TimerInit(TimerT *Timer);
void TimerStart(TimerT *Timer,
                QWordT TimeoutMS,
                TimerCallbackT *TimerCallback,
                void *Argument);
void TimerClear(TimerT *Timer);
QWordT TimerGetLeftMS(const TimerT *Timer);
bool TimerIsRunning(const TimerT *Timer);

void TimerMSSleep(DWordT MS);
void TimerUSSleep(DWordT US);
void TimerSSleep(DWordT S);

#endif
