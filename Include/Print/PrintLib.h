#ifndef HIERARCHY_PRINT_LIB_H
#define HIERARCHY_PRINT_LIB_H

#include "PrintT.h"
#include "PrintFToCallback.h"
#include "PrintFToConsole.h"
#include "PrintFToFile.h"
#include "PrintFToMemoryBuffer.h"
#include "PrintFToStringDynamic.h"
#include "PrintFToStringStatic.h"
#include "PrintVToCallback.h"
#include "PrintVToConsole.h"
#include "PrintVToFile.h"
#include "PrintVToMemoryBuffer.h"
#include "PrintVToStringDynamic.h"
#include "PrintVToStringStatic.h"

extern const struct PrintLibrary {
    struct {
        ErrnoT (*ToCallback)(const char *Format,
                             va_list ArgsPtr,
                             PrintVCb *Cb,
                             void *Argument);

        SSizeT (*ToConsole)(const char *Format,
                            va_list ArgsPtr);

        SSizeT (*ToFile)(FILE *FileIO,
                         const char *Format,
                         va_list ArgsPtr);

        MemoryBufferT *(*ToMemoryBuffer)(const char *Format,
                                         va_list ArgsPtr);

        SSizeT (*ToStringStatic)(char *OutputBuffer,
                                 SizeT BufferSize,
                                 const char *Format,
                                 va_list ArgsPtr);

        char *(*ToStringDynamic)(const char *Format,
                                 va_list ArgsPtr);
    } V;

    struct {
        ErrnoT (*ToCallback)(PrintT *Print,
                             const char *Format, ...);

        SSizeT (*ToConsole)(const char *Format, ...);

        SSizeT (*ToFile)(FILE *FileIO,
                         const char *Format, ...);

        MemoryBufferT *(*ToMemoryBuffer)(const char *Format, ...);

        SSizeT (*ToStringStatic)(char *OutputBuffer,
                                 SizeT BufferSize,
                                 const char *Format, ...);

        char *(*ToStringDynamic)(const char *Format, ...);
    } F;
} PrintLib;

#endif
