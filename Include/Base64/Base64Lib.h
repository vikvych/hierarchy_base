#ifndef HIERARCHY_BASE64_LIB_H
#define HIERARCHY_BASE64_LIB_H

#include "Base64.h"

extern const struct Base64Library {
    ErrnoT (*Encode)(ByteT *InputData,
                     SizeT InputDataLength,
                     char *OutputData,
                     SizeT *OutputDataLength);

    ErrnoT (*Decode)(char *InputData,
                     SizeT InputDataLength,
                     ByteT *OutputData,
                     SizeT *OutputDataLength);

    ErrnoT (*Print)(PrintT *Print,
                    ByteT *Data,
                    SizeT DataLength);
} Base64Lib;

#endif
