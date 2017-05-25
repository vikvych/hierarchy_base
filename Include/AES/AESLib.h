#ifndef HIERARCHY_AES_LIB_H
#define HIERARCHY_AES_LIB_H

#include "AES_CBC.h"
#include "AES_CTR.h"
#include "AES_CMAC.h"

extern const struct AESLibrary {
    struct {
        void (*Destroy)(void *AESCBC);
        AESCBCT *(*Init)(MemoryBufferT *Key,
                         MemoryBufferT *IV);

        ErrnoT (*SetIV)(AESCBCT *AESCBCPtr,
                        ByteT IV[AES_BLOCK_SIZE]);

        ErrnoT (*Encrypt)(AESCBCT *AESCBCPtr,
                          ByteT *OutputData,
                          SizeT *OutputDataLength,
                          ByteT *InputData,
                          SizeT InputDataLength);

        ErrnoT (*Decrypt)(AESCBCT *AESCBCPtr,
                          ByteT *OutputData,
                          SizeT *OutputDataLength,
                          ByteT *InputData,
                          SizeT InputDataLength);

        MemoryBufferT *(*EncryptWithAlloc)(AESCBCT *AESCBCPtr,
                                           MemoryBufferT *InputData);

        MemoryBufferT *(*DecryptWithAlloc)(AESCBCT *AESCBCPtr,
                                           MemoryBufferT *InputData);
    } CBC;

    struct {
        void (*Destroy)(void *AESCTR);

        ErrnoT (*Init)(AESCTRT **AESCTRPtr,
                       ByteT *Key,
                       SizeT KeyBitsLength,
                       ByteT IV[AES_BLOCK_SIZE]);

        ErrnoT (*SetIV)(AESCTRT *AESCTRPtr,
                        ByteT IV[AES_BLOCK_SIZE]);

        ErrnoT (*Encrypt)(AESCTRT *AESCTRPtr,
                          ByteT *OutputData,
                          ByteT *InputData,
                          SizeT InputDataLength);

        ErrnoT (*Decrypt)(AESCTRT *AESCTRPtr,
                          ByteT *OutputData,
                          ByteT *InputData,
                          SizeT InputDataLength);

        ErrnoT (*EncryptWithAlloc)(AESCTRT *AESCTRPtr,
                                   ByteT **OutputData,
                                   SizeT *OutputDataLength,
                                   ByteT *InputData,
                                   SizeT InputDataLength);

        ErrnoT (*DecryptWithAlloc)(AESCTRT *AESCTRPtr,
                                   ByteT **OutputData,
                                   SizeT *OutputDataLength,
                                   ByteT *InputData,
                                   SizeT InputDataLength);
    } CTR;
} AESLib;

#endif
