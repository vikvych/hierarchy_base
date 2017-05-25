#ifndef HIERARCHY_DEBUG_T_H
#define HIERARCHY_DEBUG_T_H

#include "../Print/PrintLib.h"
#include "../Thread/ThreadLib.h"
#include "../Time/TimeLib.h"

extern ThreadLocalStorageKeyT ThreadSpecDebug;

typedef enum DebugLevel {
    DEBUG_LEVEL_NONE = 0,
    DEBUG_LEVEL_WARNING = 1,
    DEBUG_LEVEL_NOTICE = 2,
    DEBUG_LEVEL_INFO = 3
} DebugLevelT;

typedef void (DebugPrintCb)(DebugLevelT DebugLevel,
                            QWordT ThreadId,
                            QWordT Timestamp,
                            const char *DebugData,
                            SSizeT DebugDataSize,
                            void *Argument);

typedef struct {
    QWordT StartTimestamp;
    DebugLevelT Level;
    DebugPrintCb *PrintCb;
    void *Argument;
    FILE *LogFile;
} DebugT;

void DebugDestroy(void *DebugV);
DebugT *DebugInit();
const char *DebugLevelGetLabel(DebugLevelT DebugLevel);

#endif
