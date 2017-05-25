#ifndef HIERARCHY_REGEXP_LIB_H
#define HIERARCHY_REGEXP_LIB_H

#include "RegExp.h"

extern const struct RegExpLibrary {
    ErrnoT (*Match)(const char *Data,
                     SizeT DataSize,
                     const char *RegExpString,
                     WordT CaptureCount, ...);
} RegExpLib;

#endif
