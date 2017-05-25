#ifndef HIERARCHY_BASE64_H
#define HIERARCHY_BASE64_H

#include <stdint.h>

#include "../Print/PrintLib.h"

static const char Base64Table[65] =
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz"
        "0123456789+/";

ErrnoT Base64Encode(ByteT *InputData,
                    SizeT InputDataLength,
                    char *OutputData,
                    SizeT *OutputDataLength);

ErrnoT Base64Decode(char *InputData,
                    SizeT InputDataLength,
                    ByteT *OutputData,
                    SizeT *OutputDataLength);

ErrnoT Base64Print(PrintT *Print,
                   ByteT *Data,
                   SizeT DataLength);


#endif
