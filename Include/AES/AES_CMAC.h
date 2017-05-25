#ifndef HIERARCHY_AES_CMAC_H
#define HIERARCHY_AES_CMAC_H

#include "AES_Core.h"

void AESContextCMAC(AESContextT *AESContext,
                    ByteT *Output,
                    ByteT *Input,
                    SizeT InputLength);

#endif
