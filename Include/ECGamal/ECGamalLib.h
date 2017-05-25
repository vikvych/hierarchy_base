#ifndef HIERARCHY_ECGAMAL_LIB_H
#define HIERARCHY_ECGAMAL_LIB_H

#include "ECGamal.h"
#include "ECGamalContext.h"
#include "ECGamalDecrypt.h"
#include "ECGamalEncrypt.h"
#include "ECGamalStamp.h"
#include "ECGamalVerify.h"
#include "ECGamalKey.h"

extern const struct ECGamalLibrary {
    struct {
        ECGamalContextT *(*Init)(ECCryptoModeT ECCryptoType);
    } Context;

    struct {
        ErrnoT (*SetPrivate)(ECGamalContextT* ECContext,
                             MemoryBufferT *PrivateKey);

        ErrnoT (*SetPrivateHex)(ECGamalContextT* ECContext,
                                char *PrivateKeyHex);

        ErrnoT (*GetPrivate)(MemoryBufferT **PrivateKey,
                             ECGamalContextT* ECContext);

        ErrnoT (*GetPrivateHex)(char **PrivateKey,
                                ECGamalContextT* ECContext);

        ErrnoT (*SetPublic)(ECGamalContextT* ECContext,
                            MemoryBufferT *X,
                            MemoryBufferT *Y);

        ErrnoT (*SetPublicHex)(ECGamalContextT* ECContext,
                               char *X,
                               char *Y);

        ErrnoT (*GetPublic)(MemoryBufferT **X,
                            MemoryBufferT **Y,
                            ECGamalContextT* ECContext);

        ErrnoT (*GetPublicHex)(char **X,
                               char **Y,
                               ECGamalContextT* ECContext);

        MemoryBufferT *(*GeneratePrivate)(ECCryptoModeT CryptoMode);

        ErrnoT (*CalculatePublic)(ECGamalContextT* ECContext);
    } Key;

    ErrnoT (*Encrypt)(MemoryBufferT **M1X,
                      MemoryBufferT **M1Y,
                      MemoryBufferT **M2,
                      ECGamalContextT *ECContext,
                      MemoryBufferT *PlainData);

    ErrnoT (*Decrypt)(MemoryBufferT **DecryptedBuffer,
                      ECGamalContextT* ECContext,
                      MemoryBufferT *M1X,
                      MemoryBufferT *M1Y,
                      MemoryBufferT *M2
                      );

    ErrnoT (*Stamp)(MemoryBufferT **R,
                    MemoryBufferT **S,
                    ECGamalContextT* ECContext,
                    MemoryBufferT *StampData);

    ErrnoT (*Verify)(bool *Verified,
                     ECGamalContextT* ECContext,
                     MemoryBufferT *R,
                     MemoryBufferT *S,
                     MemoryBufferT *VerifyData);
} ECGamalLib;

#endif
