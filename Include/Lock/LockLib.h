#ifndef HIERARCHY_LOCK_LIB_H
#define HIERARCHY_LOCK_LIB_H

#include "Lock.h"

extern const struct LockLibrary {
    LockT *(*Init)();
    void (*Destroy)(void *LockVoid);
    void (*Get)(LockT *Lock);
    void (*Release)(LockT *Lock);
    ErrnoT (*Try)(LockT *Lock);
} LockLib;

#endif
