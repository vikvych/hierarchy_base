#ifndef HIERARCHY_LOCK_H
#define HIERARCHY_LOCK_H

#include "../Memory/MemoryLib.h"
#include "../Debug/DebugLib.h"
#include "../System/SystemLib.h"

#ifdef WIN32
#   include <WinSock2.h>
#   include <windows.h>
#ifdef OS_TYPE_MOBILE
#   include <Synchapi.h>
#endif
#else
#   include <pthread.h>
#endif

typedef struct {
#ifdef WIN32
    CRITICAL_SECTION Mutex;
    //HANDLE Mutex;
#else
    pthread_mutex_t Mutex;
#endif
} LockT;

LockT *LockInit();
void LockDestroy(void *LockVoid);
void LockGet(LockT *Lock);
void LockRelease(LockT *Lock);
ErrnoT LockTry(LockT *Lock);

#endif
