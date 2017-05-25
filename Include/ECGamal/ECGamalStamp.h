#ifndef HIERARCHY_ECGAMAL_STAMP_H
#define HIERARCHY_ECGAMAL_STAMP_H

#include "ECGamal.h"
#include "ECGamalContext.h"

ErrnoT ECContextStamp(ECGamalContextT* ECContext);

ErrnoT ECGamalStamp(MemoryBufferT **R,
               MemoryBufferT **S,
               ECGamalContextT* ECContext,
               MemoryBufferT *StampData);

ErrnoT ECStampFromBigNUM(MemoryBufferT **R,
                         MemoryBufferT **S,
                         ECGamalContextT* ECContext,
                         MemoryBufferT *BigNUM);

#endif
