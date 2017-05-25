#ifndef HIERARCHY_SYSTEM_LIB_H
#define HIERARCHY_SYSTEM_LIB_H

#include "System.h"

extern const struct SystemLibrary {
    const char * (*Architecture)(void);
    const char * (*Platform)(void);
    const char * (*PlatformShort)(void);
    const char * (*Username)(void);
} SystemLib;

#endif
