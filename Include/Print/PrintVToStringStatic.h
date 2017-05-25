#ifndef HIERARCHY_PRINT_V_TO_STRING_STATIC_H
#define HIERARCHY_PRINT_V_TO_STRING_STATIC_H

#include "PrintT.h"

SSizeT PrintVToStringStatic(char *OutputBuffer,
                            SizeT BufferSize,
                            const char *Format,
                            va_list ArgsPtr);

#endif
