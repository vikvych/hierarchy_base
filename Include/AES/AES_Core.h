#ifndef HIERARCHY_AES_CORE_H
#define HIERARCHY_AES_CORE_H

#include "../Error/ErrorLib.h"
#include "../Memory/MemoryLib.h"
#include <stdbool.h>

#ifndef AES_BLOCK_SIZE
#define AES_BLOCK_SIZE 0x10
#endif

typedef struct {
    SSizeT RoundCount;
    DWordT *RoundKeys;
    DWordT DataBuffer[68];
} AESContextT;

ErrnoT AESContextSetKeyEnc(AESContextT *AESContext, ByteT *Key, SizeT KeySize);
ErrnoT AESContextSetKeyDec(AESContextT *AESContext, ByteT *Key, SizeT KeySize);

ErrnoT AESContextECBProcess(AESContextT *AESContext,
                            ByteT Output[16],
                            ByteT Input[16],
                            bool Encrypt);

ErrnoT AESContextCBCProcess(AESContextT *AESContext,
                            ByteT *Output,
                            ByteT *Input,
                            SizeT InputLength,
                            ByteT IV[16],
                            bool Encrypt);

ErrnoT AESContextCFB128Process(AESContextT *AESContext,
                               ByteT *Output,
                               ByteT *Input,
                               SizeT InputLength,
                               ByteT IV[16],
                               SizeT *IVOffset,
                               bool Encrypt);

ErrnoT AESContextCTRProcess(AESContextT *AESContext,
                            ByteT *Output,
                            ByteT *Input,
                            SizeT InputLength,
                            ByteT StreamBlockSaved[16],
                            SizeT *StreamBlockOffset,
                            ByteT NOnce[16]);


#endif
