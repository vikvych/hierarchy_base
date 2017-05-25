#ifndef HIERARCHY_ECGAMAL_ENCRYPT_H
#define HIERARCHY_ECGAMAL_ENCRYPT_H

#include "ECGamal.h"
#include "ECGamalContext.h"

ErrnoT ECContextEncrypt(ECGamalContextT* ECContext);

ErrnoT ECGamalEncrypt(MemoryBufferT **M1X,
                 MemoryBufferT **M1Y,
                 MemoryBufferT **M2,
                 ECGamalContextT *ECContext,
                 MemoryBufferT *PlainData);

#endif
