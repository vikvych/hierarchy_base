#ifndef HIERARCHY_PRINTF_TO_CALLBACK_H
#define HIERARCHY_PRINTF_TO_CALLBACK_H

#include "PrintT.h"

ErrnoT PrintFToCallback(PrintT *Print,
                        const char *Format, ...);

#endif
