#ifndef HIERARCHY_PRINTV_TO_MEMORYBUFFER_DYNAMIC_H
#define HIERARCHY_PRINTV_TO_MEMORYBUFFER_DYNAMIC_H

#include "PrintT.h"

MemoryBufferT *PrintVToMemoryBuffer(const char *Format,
                                    va_list ArgsPtr);

#endif
