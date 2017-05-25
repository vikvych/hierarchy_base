#ifndef HIERARCHYBASE_TIME_TIMESTAMP_TO_TIMEVAL_H
#define HIERARCHYBASE_TIME_TIMESTAMP_TO_TIMEVAL_H

#include "TimeCurrentTimestamp.h"

ErrnoT TimeTimestampToTimeval(struct timeval *TimeVal, uint64_t Timestamp);

#endif
