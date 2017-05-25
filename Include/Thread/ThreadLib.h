#ifndef HIERARCHY_THREAD_LIB_H
#define HIERARCHY_THREAD_LIB_H

#include "Thread.h"
#include "ThreadLocalStorage.h"

extern const struct ThreadLibrary {
    QWordT (*Id)();

    struct {
        ThreadT *(*Create)(ThreadFunctionT ThreadFunction,
                           ThreadArgumentT ThreadArgument);
        ErrnoT (*Wait)(ThreadT *Thread);
        bool (*IsEqual)(ThreadT *Thread1, ThreadT *Thread2);
    } Joinable;

    struct {
        ErrnoT (*Alloc)(ThreadLocalStorageKeyT *Key);
        ErrnoT (*Free)(ThreadLocalStorageKeyT Key);
        void *(*Get)(ThreadLocalStorageKeyT Key);
        ErrnoT (*Set)(ThreadLocalStorageKeyT Key, void *Value);
    } LocalStorage;
} ThreadLib;

#endif
