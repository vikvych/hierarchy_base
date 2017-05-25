#ifndef HIERARCHY_RANDOM_LIB_H
#define HIERARCHY_RANDOM_LIB_H

#include "Random.h"

extern const struct RandomLibrary {
    uint16_t (*UInt16)(void);
    uint32_t (*UInt32)(void);
    uint64_t (*UInt64)(void);

    char (*Char)(void);
    void (*String)(char *String, uint32_t Length);

    void (*Bytes)(uint8_t *Buffer, uint32_t Length);
} RandomLib;

#endif
