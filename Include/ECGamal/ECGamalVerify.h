#ifndef HIERARCHY_ECGAMAL_VERIFY_H
#define HIERARCHY_ECGAMAL_VERIFY_H

#include "ECGamal.h"
#include "ECGamalContext.h"

ErrnoT ECContextVerify(bool *Verified,
                       ECGamalContextT* ECContext);

ErrnoT ECGamalVerify(bool *Verified,
                ECGamalContextT* ECContext,
                MemoryBufferT *R,
                MemoryBufferT *S,
                MemoryBufferT *VerifyData);

#endif
