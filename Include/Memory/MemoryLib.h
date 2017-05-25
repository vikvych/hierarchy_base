#ifndef HIERARCHY_MEMORY_LIB_H
#define HIERARCHY_MEMORY_LIB_H

#include "MemoryT.h"
#include "MemoryZAlloc.h"
#include "MemoryRealloc.h"
#include "MemoryRef.h"
#include "MemoryUnref.h"
#include "MemoryRefCount.h"
#include "MemorySize.h"
#include "MemoryFill.h"
#include "MemoryDebug.h"
#include "MemoryCompare.h"
#include "MemoryCopy.h"

extern const struct MemoryLibrary {
    void *(*Alloc)(SizeT Size, MemoryDestroyCb *DestroyCb);
    void *(*ZAlloc)(SizeT Size, MemoryDestroyCb *DestroyCb);
    void *(*Realloc)(void *Data, SizeT Size);

    void *(*Ref)(void *Data);
    void *(*Unref)(void *Data);
    SizeT (*RefCount)(void *Data);

    SizeT (*Length)(void *Data);
    ErrnoT (*Fill)(void *Data, ByteT FillByte, SizeT Size);
    void (*FillSimple)(void *Data, ByteT FillByte, SizeT Size);
    SSizeT (*Compare)(const void *Data1, const void *Data2, SizeT Size);
    void (*Copy)(void *Dest, const void *Source, SizeT Size);

    void (*Debug)(const char *Prefix, void *Data);
} MemoryLib;

#endif
