#ifndef HIERARCHYBASE_TIME_CURRENT_TIMEVAL_H
#define HIERARCHYBASE_TIME_CURRENT_TIMEVAL_H

#include "../System/SystemLib.h"
#include <time.h>
#if SYSTEM_OS != SYSTEM_OS_ANDROID
#include <sys/timeb.h>
#endif
#include <stdint.h>
#ifdef __APPLE__
#include <sys/time.h>
#endif
#include "../Error/ErrorLib.h"
#include "../Memory/MemoryLib.h"

#ifdef WIN32
#include <WinSock2.h>
#include <Windows.h>
int gettimeofday(struct timeval * TimeVal, struct timezone * TimeZone);
#endif

ErrnoT TimeCurrentTimeval(struct timeval *TimeVal);

#endif
