#ifndef HIERARCHY_AES_CBC_H
#define HIERARCHY_AES_CBC_H

#include <stdint.h>

#include "../Memory/MemoryLib.h"
#include "../MemoryBuffer/MemoryBufferLib.h"

#include "AES_Core.h"

typedef struct {
    ByteT *KeyDecrypt;
    SizeT KeyDecryptLength;
    ByteT *KeyEncrypt;
    SizeT KeyEncryptLength;

    ByteT IV[AES_BLOCK_SIZE];

    AESContextT *EncryptContext;
    AESContextT *DecryptContext;
} AESCBCT;

void AESCBCDestroy(void *AESCBC);

AESCBCT *AESCBCInit(MemoryBufferT *Key,
                    MemoryBufferT *IV);

ErrnoT AESCBCSetIV(AESCBCT *AESCBCPtr,
                   ByteT *IV);

ErrnoT AESCBCEncrypt(AESCBCT *AESCBCPtr,
                     ByteT *OutputData,
                     SizeT *OutputDataLength,
                     ByteT *InputData,
                     SizeT InputDataLength);

ErrnoT AESCBCDecrypt(AESCBCT *AESCBCPtr,
                     ByteT *OutputData,
                     SizeT *OutputDataLength,
                     ByteT *InputData,
                     SizeT InputDataLength);

MemoryBufferT *AESCBCEncryptWithAlloc(AESCBCT *AESCBCPtr,
                                      MemoryBufferT *InputData);

MemoryBufferT *AESCBCDecryptWithAlloc(AESCBCT *AESCBCPtr,
                                      MemoryBufferT *InputData);

#endif
