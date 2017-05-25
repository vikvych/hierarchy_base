#ifndef HIERARCHY_DEBUG_LIB_H
#define HIERARCHY_DEBUG_LIB_H

#include "DebugT.h"
#include "DebugInfo.h"
#include "DebugLog.h"
#include "DebugNotice.h"
#include "DebugStart.h"
#include "DebugStop.h"
#include "DebugWarning.h"

extern const struct DebugLibrary {

    ErrnoT (*Start)(DebugPrintCb *PrintCallback,
                    void *Argument,
                    DebugLevelT DebugLevel);

    void (*Stop)(void);

    const char *(*LevelGetLabel)(DebugLevelT DebugLevel);

    void (*Warning)(const char *Format, ...);
    void (*Notice)(const char *Format, ...);
    void (*Info)(const char *Format, ...);
} DebugLib;


#endif
