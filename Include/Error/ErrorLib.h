#ifndef HIERARCHY_ERROR_LIB_H
#define HIERARCHY_ERROR_LIB_H

#include "Error.h"

extern const struct ErrorLibrary {
    const char *(*ErrnoToString)(ErrnoT ErrorCode,
                                 char *ReasonString,
                                 uint32_t ReasonStringLength);
} ErrorLib;

#endif
