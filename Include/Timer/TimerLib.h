#ifndef HIERARCHY_TIMER_LIB_H
#define HIERARCHY_TIMER_LIB_H

#include "Timer.h"

extern const struct TimerLibrary {
    struct {
        void (*US)(DWordT US);
        void (*MS)(DWordT MS);
        void (*S)(DWordT S);
    } Sleep;

    struct {
        void (*Polling)(ListT *TimerList);

        QWordT (*NextTimerExpireTimeLeft)(ListT *TimerList);

        void (*ListPrint)(void);

        void (*Init)(TimerT *Timer);

        void (*Start)(TimerT *Timer,
                      QWordT TimeoutMS,
                      TimerCallbackT *TimerCallback,
                      void *Argument);

        void (*Clear)(TimerT *Timer);

        QWordT (*GetLeftMS)(const TimerT *Timer);
        bool (*IsRunning)(const TimerT *Timer);
    } Timer;
} TimerLib;

#endif
