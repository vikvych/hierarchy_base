#ifndef HIERARCHY_PRINT_T_H
#define HIERARCHY_PRINT_T_H

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <errno.h>
#include <stdarg.h>
#include <time.h>

#include "../System/SystemLib.h"
#include "../MemoryBuffer/MemoryBufferT.h"

typedef enum {
    PRINT_LENGTH_MODE_SHORT_SHORT = 0x00,
    PRINT_LENGTH_MODE_SHORT = 0x01,
    PRINT_LENGTH_MODE_NORMAL = 0x02,
    PRINT_LENGTH_MODE_LONG = 0x03,
    PRINT_LENGTH_MODE_LONG_LONG = 0x04,
    PRINT_LENGTH_MODE_SIZE = 0x05
} PrintLengthModeT;

typedef ErrnoT (PrintVCb)(const char *String,
                          SizeT StringSize,
                          void *Argument);

typedef struct {
    PrintVCb *PrintVCb;
    void *Argument;
} PrintT;

typedef ErrnoT (PrintCb)(PrintT *Print,
                         void *Argument);

#endif
