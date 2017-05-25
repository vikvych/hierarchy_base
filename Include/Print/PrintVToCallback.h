#ifndef HIERARCHY_PRINTV_TO_CALLBACK_H
#define HIERARCHY_PRINTV_TO_CALLBACK_H

#include "PrintT.h"

ErrnoT PrintVToCallback(const char *Format,
                        va_list ArgsPtr,
                        PrintVCb *Cb,
                        void *Argument);

#endif
