#ifndef HIERARCHY_ECGAMAL_H
#define HIERARCHY_ECGAMAL_H

#include <stdbool.h>
#include <stdint.h>

#ifdef WIN32
#include <WinSock2.h>
#include <Windows.h>
#else
#include <unistd.h>
#include <pthread.h>
#endif

#include <openssl/ec.h>
#ifndef OPENSSL_NO_ENGINE
#include <openssl/engine.h>
#endif
#include <openssl/err.h>

#include "../MemoryBuffer/MemoryBufferLib.h"
#include "../Debug/DebugLib.h"

#define EC_CRYPTO_256BIT_LENGTH 32
#define EC_CRYPTO_384BIT_LENGTH 48
#define EC_CRYPTO_521BIT_LENGTH 66

typedef enum {
    EC_CRYPTO_256BIT,
    EC_CRYPTO_384BIT,
    EC_CRYPTO_521BIT
} ECCryptoModeT;

uint32_t ECGetByteSizeByType(ECCryptoModeT ECCryptoMode);
uint32_t ECGetByteSizeStampVerifyByType(ECCryptoModeT ECCryptoMode);
uint32_t ECGetByteSizeSHANOnceType(ECCryptoModeT ECCryptoMode);

BIGNUM *ECMemoryBufferToBigNum(MemoryBufferT *MemoryBuffer, ECCryptoModeT Mode);
BIGNUM *ECHexStringToBigNum(char *HexString, ECCryptoModeT Mode);
MemoryBufferT *ECBigNumToMemoryBuffer(BIGNUM *BigNum, ECCryptoModeT Mode);
char *ECBigNumToHexString(BIGNUM *BigNum, ECCryptoModeT Mode);

#endif
