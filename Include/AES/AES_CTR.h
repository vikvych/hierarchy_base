#ifndef HIERARCHY_AES_CTR_H
#define HIERARCHY_AES_CTR_H

#include <stdint.h>
#include "../Memory/MemoryLib.h"

#include "AES_Core.h"

typedef struct {
    ByteT *Key;
    SizeT KeyLength;
    ByteT IV[AES_BLOCK_SIZE];

    AESContextT *Context;
} AESCTRT;

void AESCTRDestroy(void *AESCTR);

ErrnoT AESCTRInit(AESCTRT **AESCTRPtr,
                  ByteT *Key,
                  SizeT KeyBitsLength,
                  ByteT *IV);

ErrnoT AESCTRSetIV(AESCTRT *AESCTRPtr,
                   ByteT *IV);

ErrnoT AESCTREncrypt(AESCTRT *AESCTRPtr,
                     ByteT *OutputData,
                     ByteT *InputData,
                     SizeT InputDataLength);

ErrnoT AESCTRDecrypt(AESCTRT *AESCTRPtr,
                     ByteT *OutputData,
                     ByteT *InputData,
                     SizeT InputDataLength);

ErrnoT AESCTREncryptWithAlloc(AESCTRT *AESCTRPtr,
                              ByteT **OutputData,
                              SizeT *OutputDataLength,
                              ByteT *InputData,
                              SizeT InputDataLength);

ErrnoT AESCTRDecryptWithAlloc(AESCTRT *AESCTRPtr,
                              ByteT **OutputData,
                              SizeT *OutputDataLength,
                              ByteT *InputData,
                              SizeT InputDataLength);

#endif
