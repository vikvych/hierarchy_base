#ifndef HIERARCHY_THREAD_H
#define HIERARCHY_THREAD_H

#include "../System/SystemLib.h"
#include "../Error/ErrorLib.h"
#include "../Memory/MemoryLib.h"

#if SYSTEM_FAMILY == SYSTEM_FAMILY_WINDOWS
#include <WinSock2.h>
#include <Windows.h>
#if SYSTEM_TYPE == SYSTEM_TYPE_MOBILE
#include <winapifamily.h>
#include <processthreadsapi.h>
#endif
typedef HANDLE ThreadT;
#else
#include <unistd.h>
#include <pthread.h>
typedef pthread_t ThreadT;

#endif
typedef void *(*ThreadFunctionT)(void *);
typedef void * ThreadArgumentT;

ThreadT *ThreadJoinableCreate(ThreadFunctionT ThreadFunction,
                              ThreadArgumentT ThreadArgument);

void ThreadJoinableDestroy(ThreadT *Thread);

ErrnoT ThreadJoinableWait(ThreadT *Thread);

bool ThreadJoinableIsEqual(ThreadT *Thread1, ThreadT *Thread2);

QWordT ThreadId();

#endif
