#ifndef HIERARCHY_ECGAMAL_DECRYPT_H
#define HIERARCHY_ECGAMAL_DECRYPT_H

#include "ECGamal.h"
#include "ECGamalContext.h"

ErrnoT ECContextDecrypt(ECGamalContextT* ECContext);

ErrnoT ECGamalDecrypt(MemoryBufferT **DecryptedBuffer,
                 ECGamalContextT* ECContext,
                 MemoryBufferT *M1X,
                 MemoryBufferT *M1Y,
                 MemoryBufferT *M2);

#endif
