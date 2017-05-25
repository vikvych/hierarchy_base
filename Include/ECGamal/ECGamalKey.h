#ifndef HIERARCHY_ECGAMAL_KEY_H
#define HIERARCHY_ECGAMAL_KEY_H

#include "ECGamal.h"
#include "ECGamalContext.h"

ErrnoT ECKeysSetPrivate(ECGamalContextT* ECContext,
                        MemoryBufferT *PrivateKey);

ErrnoT ECKeysSetPrivateHex(ECGamalContextT* ECContext,
                           char *PrivateKeyHex);

ErrnoT ECKeysGetPrivate(MemoryBufferT **PrivateKey,
                        ECGamalContextT* ECContext);

ErrnoT ECKeysGetPrivateHex(char **PrivateKey,
                           ECGamalContextT* ECContext);

ErrnoT ECKeysSetPublic(ECGamalContextT* ECContext,
                       MemoryBufferT *X,
                       MemoryBufferT *Y);

ErrnoT ECKeysSetPublicHex(ECGamalContextT* ECContext,
                          char *X,
                          char *Y);

ErrnoT ECKeysGetPublic(MemoryBufferT **X,
                       MemoryBufferT **Y,
                       ECGamalContextT* ECContext);

ErrnoT ECKeysGetPublicHex(char **X,
                          char **Y,
                          ECGamalContextT* ECContext);

MemoryBufferT *ECGeneratePrivate(ECCryptoModeT CryptoMode);

ErrnoT ECKeysCalculatePublic(ECGamalContextT* ECContext);

#endif
