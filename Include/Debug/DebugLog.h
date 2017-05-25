#ifndef HIERARCHY_DEBUG_LOG_H
#define HIERARCHY_DEBUG_LOG_H

#include "DebugT.h"

void DebugLog(DebugLevelT DebugLevel,
              const char *Format,
              va_list ArgsPtr);

#endif
