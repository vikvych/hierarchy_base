#ifndef HIERARCHY_ECDSA_LIB_H
#define HIERARCHY_ECDSA_LIB_H

#include "../EC/ECLib.h"
#include "ECDSAContext.h"

/*extern const struct ECLibrary {
    struct {
        ECContextT *(*Init)(ECCryptoModeT ECCryptoType);
        void (*Destroy)(ECContextT *ECContext);
    } Context;

    struct {
        ErrnoT (*SetPrivate)(ECContextT* ECContext,
                             MemoryBufferT *PrivateKey);

        ErrnoT (*SetPrivateHex)(ECContextT* ECContext,
                                char *PrivateKeyHex);

        ErrnoT (*GetPrivate)(MemoryBufferT **PrivateKey,
                             ECContextT* ECContext);

        ErrnoT (*GetPrivateHex)(char **PrivateKey,
                                ECContextT* ECContext);

        ErrnoT (*SetPublic)(ECContextT* ECContext,
                            MemoryBufferT *X,
                            MemoryBufferT *Y);

        ErrnoT (*SetPublicHex)(ECContextT* ECContext,
                               char *X,
                               char *Y);

        ErrnoT (*GetPublic)(MemoryBufferT **X,
                            MemoryBufferT **Y,
                            ECContextT* ECContext);

        ErrnoT (*GetPublicHex)(char **X,
                               char **Y,
                               ECContextT* ECContext);

        MemoryBufferT *(*GeneratePrivate)(ECCryptoModeT CryptoMode);

        ErrnoT (*СalculatePublic)(ECContextT* ECContext);
    } Key;

    ErrnoT (*Encrypt)(MemoryBufferT **M1X,
                      MemoryBufferT **M1Y,
                      MemoryBufferT **M2,
                      ECContextT *ECContext,
                      MemoryBufferT *PlainData);

    ErrnoT (*Decrypt)(MemoryBufferT **DecryptedBuffer,
                      ECContextT* ECContext,
                      MemoryBufferT *M1X,
                      MemoryBufferT *M1Y,
                      MemoryBufferT *M2
                      );

    ErrnoT (*Stamp)(MemoryBufferT **R,
                    MemoryBufferT **S,
                    ECContextT* ECContext,
                    MemoryBufferT *StampData);

    ErrnoT (*Verify)(bool *Verified,
                     ECContextT* ECContext,
                     MemoryBufferT *R,
                     MemoryBufferT *S,
                     MemoryBufferT *VerifyData);
} ECLib;*/

#endif
