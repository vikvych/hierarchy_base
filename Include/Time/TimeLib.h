#ifndef HIERARCHY_TIME_LIB_H
#define HIERARCHY_TIME_LIB_H

#include "TimeCurrentTimestamp.h"
#include "TimeCurrentTimeval.h"
#include "TimeTimestampToTimeval.h"
#include "TimeTimevalToTimestamp.h"

extern const struct TimeLibrary {
    QWordT (*CurrentTimestamp)();
    ErrnoT (*CurrentTimeval)(struct timeval *TimeVal);
    QWordT (*TimevalToTimestamp)(struct timeval TimeVal);
    ErrnoT (*TimestampToTimeval)(struct timeval *TimeVal, uint64_t Timestamp);
} TimeLib;

#endif


