#ifndef HIERARCHY_PRINTV_TO_FILE_H
#define HIERARCHY_PRINTV_TO_FILE_H

#include "PrintT.h"

SSizeT PrintVToFile(FILE *FileIO,
                    const char *Format,
                    va_list ArgsPtr);

#endif
