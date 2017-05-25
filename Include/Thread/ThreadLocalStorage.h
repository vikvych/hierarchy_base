#ifndef HIERARCHY_THREAD_LOCAL_STORAGE_H
#define HIERARCHY_THREAD_LOCAL_STORAGE_H

#include <stdbool.h>
#include <stdint.h>
#include "../System/SystemLib.h"
#include "../Error/ErrorLib.h"

#if SYSTEM_FAMILY == SYSTEM_FAMILY_WINDOWS
#   include <WinSock2.h>
#   include <Windows.h>

typedef DWORD ThreadLocalStorageKeyT;

#if SYSTEM_TYPE == SYSTEM_TYPE_MOBILE
#define TLS_OUT_OF_INDEXES ((DWORD)0xFFFFFFFF)
#include <Processthreadsapi.h>
#endif
#else
#   include <pthread.h>
typedef pthread_key_t ThreadLocalStorageKeyT;

#endif

ErrnoT ThreadLSAlloc(ThreadLocalStorageKeyT *Key);
ErrnoT ThreadLSFree(ThreadLocalStorageKeyT Key);
void *ThreadLSGetValue(ThreadLocalStorageKeyT Key);
ErrnoT ThreadLSSetValue(ThreadLocalStorageKeyT Key, void *Value);


#endif
