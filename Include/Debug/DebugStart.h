#ifndef HIERARCHY_DEBUG_START_H
#define HIERARCHY_DEBUG_START_H

#include "DebugT.h"

ErrnoT DebugStart(DebugPrintCb *PrintCb,
                  void *PrintArgument,
                  DebugLevelT DebugLevel);

#endif
