#ifndef HIERARCHY_MEMORY_T_H
#define HIERARCHY_MEMORY_T_H

#include <memory.h>
#include <stdbool.h>
#include <stddef.h>

#include "../Error/Error.h"

#define MEMORY_SIZE_MAX 0xFFFFFFFF

#define ByteTSize 0
#define WordTSize 2
#define DWordTSize 4
#define QWordTSize 8

#define SByteTSize 0
#define SWordTSize 2
#define SDWordTSize 4
#define SQWordTSize 8

typedef bool BitT;

typedef size_t SizeT;
typedef ptrdiff_t SSizeT;

//typedef uint64_t CountT;
//typedef uint64_t NumberIntT;
//typedef double NumberDoubleT;

typedef uint8_t ByteT;
typedef uint16_t WordT;
typedef uint32_t DWordT;
typedef uint64_t QWordT;

typedef int8_t SByteT;
typedef int16_t SWordT;
typedef int32_t SDWordT;
typedef int64_t SQWordT;

typedef uint64_t ExtSizeT;
typedef int64_t SExtSizeT;

typedef void (MemoryDestroyCb)(void *Data);

typedef struct {
    SizeT Length;
    SizeT RefCount;
    MemoryDestroyCb *DestroyCb;
} MemoryT;

void *MemoryAlloc(SizeT Size, MemoryDestroyCb *DestroyCb);

#endif
