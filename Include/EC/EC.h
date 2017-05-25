#ifndef HIERARCHY_EC_H
#define HIERARCHY_EC_H

#include "../MemoryBuffer/MemoryBufferLib.h"
#include "../Debug/DebugLib.h"
#include "../BigNumber/BigNumberLib.h"

#define EC_P_CURVE_192BIT_p "FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEFFFFFFFFFFFFFFFF"
#define EC_P_CURVE_192BIT_a "FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEFFFFFFFFFFFFFFFC"
#define EC_P_CURVE_192BIT_b "64210519E59C80E70FA7E9AB72243049FEB8DEECC146B9B1"
#define EC_P_CURVE_192BIT_N "FFFFFFFFFFFFFFFFFFFFFFFF99DEF836146BC9B1B4D22831"
#define EC_P_CURVE_192BIT_GX "188DA80EB03090F67CBF20EB43A18800F4FF0AFD82FF1012"
#define EC_P_CURVE_192BIT_GY "07192B95FFC8DA78631011ED6B24CDD573F977A11E794811"

#define EC_P_CURVE_192BIT_SIZE 24
#define EC_P_CURVE_224BIT_SIZE 28
#define EC_P_CURVE_256BIT_SIZE 32
#define EC_P_CURVE_384BIT_SIZE 48
#define EC_P_CURVE_521BIT_SIZE 66

/*
 *
     CipherSuite TLS_ECDH_ECDSA_WITH_NULL_SHA           = { 0xC0, 0x01 }
     CipherSuite TLS_ECDH_ECDSA_WITH_RC4_128_SHA        = { 0xC0, 0x02 }
     CipherSuite TLS_ECDH_ECDSA_WITH_3DES_EDE_CBC_SHA   = { 0xC0, 0x03 }
     CipherSuite TLS_ECDH_ECDSA_WITH_AES_128_CBC_SHA    = { 0xC0, 0x04 }
     CipherSuite TLS_ECDH_ECDSA_WITH_AES_256_CBC_SHA    = { 0xC0, 0x05 }

     CipherSuite TLS_ECDHE_ECDSA_WITH_NULL_SHA          = { 0xC0, 0x06 }
     CipherSuite TLS_ECDHE_ECDSA_WITH_RC4_128_SHA       = { 0xC0, 0x07 }
     CipherSuite TLS_ECDHE_ECDSA_WITH_3DES_EDE_CBC_SHA  = { 0xC0, 0x08 }
     CipherSuite TLS_ECDHE_ECDSA_WITH_AES_128_CBC_SHA   = { 0xC0, 0x09 }
     CipherSuite TLS_ECDHE_ECDSA_WITH_AES_256_CBC_SHA   = { 0xC0, 0x0A }

     CipherSuite TLS_ECDH_RSA_WITH_NULL_SHA             = { 0xC0, 0x0B }
     CipherSuite TLS_ECDH_RSA_WITH_RC4_128_SHA          = { 0xC0, 0x0C }
     CipherSuite TLS_ECDH_RSA_WITH_3DES_EDE_CBC_SHA     = { 0xC0, 0x0D }
     CipherSuite TLS_ECDH_RSA_WITH_AES_128_CBC_SHA      = { 0xC0, 0x0E }
     CipherSuite TLS_ECDH_RSA_WITH_AES_256_CBC_SHA      = { 0xC0, 0x0F }

     CipherSuite TLS_ECDHE_RSA_WITH_NULL_SHA            = { 0xC0, 0x10 }
     CipherSuite TLS_ECDHE_RSA_WITH_RC4_128_SHA         = { 0xC0, 0x11 }
     CipherSuite TLS_ECDHE_RSA_WITH_3DES_EDE_CBC_SHA    = { 0xC0, 0x12 }
     CipherSuite TLS_ECDHE_RSA_WITH_AES_128_CBC_SHA     = { 0xC0, 0x13 }
     CipherSuite TLS_ECDHE_RSA_WITH_AES_256_CBC_SHA     = { 0xC0, 0x14 }

     CipherSuite TLS_ECDH_anon_WITH_NULL_SHA            = { 0xC0, 0x15 }
     CipherSuite TLS_ECDH_anon_WITH_RC4_128_SHA         = { 0xC0, 0x16 }
     CipherSuite TLS_ECDH_anon_WITH_3DES_EDE_CBC_SHA    = { 0xC0, 0x17 }
     CipherSuite TLS_ECDH_anon_WITH_AES_128_CBC_SHA     = { 0xC0, 0x18 }
     CipherSuite TLS_ECDH_anon_WITH_AES_256_CBC_SHA     = { 0xC0, 0x19 }
     */

//sect163k1   |               |   NIST K-163
//sect163r2   |               |   NIST B-163
//sect233k1   |               |   NIST K-233
//sect233r1   |               |   NIST B-233
//sect283k1   |               |   NIST K-283
//sect283r1   |               |   NIST B-283
//sect409k1   |               |   NIST K-409
//sect409r1   |               |   NIST B-409
//sect571k1   |               |   NIST K-571
//sect571r1   |               |   NIST B-571

//secp192r1   |  prime192v1   |   NIST P-192
//secp224r1   |               |   NIST P-224
//secp256r1   |  prime256v1   |   NIST P-256
//secp384r1   |               |   NIST P-384
//secp521r1   |               |   NIST P-521

typedef enum {
    EC_P_CURVE_192BIT,
    EC_P_CURVE_224BIT,
    EC_P_CURVE_256BIT,
    EC_P_CURVE_384BIT,
    EC_P_CURVE_521BIT
} ECPCurveTypeT;

typedef struct {
    BigNumberT *X;
    BigNumberT *Y;
} ECPointT;

typedef struct {
    BigNumberT *p;
    BigNumberT *a;	// mon
    BigNumberT *b;	// mon
    BigNumberT *N; // + 1 to length
    ECPointT *G;	// mon
    ECPointT *Q;	// mon
    BigNumberT *k; // +1 to length

    SizeT ByteSize;
} ECCurveT;

ECCurveT *ECCurveInit(ECPCurveTypeT PCurveType);
void ECCurveDestroy(void *ECCurveV);

/*uint32_t ECGetByteSizeByType(ECCryptoModeT ECCryptoMode);
uint32_t ECGetByteSizeStampVerifyByType(ECCryptoModeT ECCryptoMode);
uint32_t ECGetByteSizeSHANOnceType(ECCryptoModeT ECCryptoMode);

BIGNUM *ECMemoryBufferToBigNum(MemoryBufferT *MemoryBuffer, ECCryptoModeT Mode);
BIGNUM *ECHexStringToBigNum(char *HexString, ECCryptoModeT Mode);
MemoryBufferT *ECBigNumToMemoryBuffer(BIGNUM *BigNum, ECCryptoModeT Mode);
char *ECBigNumToHexString(BIGNUM *BigNum, ECCryptoModeT Mode);*/

#endif
