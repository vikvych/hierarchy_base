#ifndef HIERARCHY_REGEXP_H
#define HIERARCHY_REGEXP_H

#include <ctype.h>

#include "../Debug/DebugLib.h"
#include "../Memory/MemoryLib.h"
#include "../CString/CStringLib.h"
#include "../Error/ErrorLib.h"
#include "../MemoryBlock/MemoryBlockLib.h"

#define MAX_CHAR 0xFFFF

typedef enum {
    REG_EXP_TYPE_GREEDY = MAX_CHAR + 1,
    REG_EXP_TYPE_OR,
    REG_EXP_TYPE_EXPR,
    REG_EXP_TYPE_NOCAPEXPR,
    REG_EXP_TYPE_DOT,
    REG_EXP_TYPE_CLASS,
    REG_EXP_TYPE_CCLASS,
    REG_EXP_TYPE_NCLASS,
    REG_EXP_TYPE_RANGE,
    REG_EXP_TYPE_CHAR,
    REG_EXP_TYPE_EOL,
    REG_EXP_TYPE_BOL,
    REG_EXP_TYPE_WB
} RegExpNodeTypeT;

typedef struct {
    RegExpNodeTypeT Type;
    SDWordT Left;
    SDWordT Right;
    SDWordT Next;
} RegExpNodeT;

typedef struct {
    const char *DataBeginPtr;
    const char *DataEndPtr;
    const char *RegExpStringPtr;


    SDWordT NodeAllocCount;
    SDWordT NodeCount;
    SDWordT FirstNode;

    SDWordT SubExpCount;
    SDWordT SubExpIndex;

    RegExpNodeT *Nodes;
    MemoryBlockT *Matches;

    ErrnoT Error;
} RegExpT;

RegExpT *RegExpInit(const char *RegExpString);

bool RegExpTest(RegExpT* RegExp,
                const char* RegExpString);

bool RegExpSearch(RegExpT* RegExp,
                  const char* Data,
                  const char** OutputBeginPtr,
                  const char** OutputEndPtr);

bool RegExpSearchRange(RegExpT* RegExp,
                       const char* DataBeginPtr,
                       const char* DataEndPtr,
                       const char** OutputBeginPtr,
                       const char** OutputEndPtr);

SDWordT RegExpSubExpCount(RegExpT* RegExp);

bool RegExpSubExp(RegExpT* RegExp,
                  SDWordT Index,
                  MemoryBlockT *SubExp);


ErrnoT RegExpMatch(const char *Data,
                   SizeT DataSize,
                   const char *RegExpString,
                   WordT CaptureCount, ...);


#endif
