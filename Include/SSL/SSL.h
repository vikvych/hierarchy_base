#ifndef HIERARCHYBASE_SSL_SSL_H
#define HIERARCHYBASE_SSL_SSL_H

#ifdef WIN32
#include "WinSock2.h"
#endif

#include <string.h>

#ifndef OPENSSL_NO_KRB5
#define OPENSSL_NO_KRB5 1
#endif

#include <openssl/ssl.h>
#include <openssl/err.h>
#include <openssl/rsa.h>
#include <openssl/bn.h>

#include "../Debug/DebugLib.h"
#include "../Memory/MemoryLib.h"
#include "../MemoryBuffer/MemoryBufferLib.h"
#include "../Polling/PollingLib.h"
#include "../SocketAddress/SocketAddressLib.h"
#include "../Network/NetworkLib.h"
#include "../Random/RandomLib.h"
#include "../TCP/TCPLib.h"
#include "../UDP/UDPLib.h"
#include "../System/SystemLib.h"

typedef struct {
    SSL_CTX *SSLContext;
    X509 *Certificate;
    char *PrivateKeyPassword;
} SSLContextT;

typedef enum {
    SSL_METHOD_SSLV23,
    SSL_METHOD_DTLSV1,
    SSL_METHOD_DTLS,
    SSL_METHOD_DTLSV12,
    SSL_METHOD_TLSV1,
    SSL_METHOD_TLSV11,
    SSL_METHOD_TLSV12
} SSLMethodT;

typedef enum {
    SRTP_AES128_HMAC_SHA1_32,
    SRTP_AES128_HMAC_SHA1_80,
    SRTP_AES256_HMAC_SHA1_32,
    SRTP_AES256_HMAC_SHA1_80,
} SRTPSuiteT;

typedef enum SSLContextFingerPrintGet {
    SSL_FINGERPRINT_SHA1,
    SSL_FINGERPRINT_SHA256,
} SSLFingerPrintT;

typedef struct {
    SSL *SSL;
} SSLConnectionT;

void SSLContextDestroy(void *SSLContextVoid);

SSLContextT *SSLContextInit(SSLMethodT Method,
                            const char *PrivateKeyFile,
                            const char *PrivateKeyPassword);

int32_t SSLContextAddCA(SSLContextT *SSLContext,
                        const char *CAPath);

int32_t SSLContextSetCertificatePEM(SSLContextT *SSLContext,
                                    const char *CertificatePEM,
                                    uint32_t CertificatePEMLength);

void SSLContextSetClientVerification(SSLContextT *SSLContext);

int32_t SSLContextSetSRTPSuites(SSLContextT *SSLContext,
                                const char *SRTPSuites);

int32_t SSLContextFingerPrintGet(const SSLContextT *SSLContext,
                                 SSLFingerPrintT FingerPrint,
                                 uint8_t *FingerPrintDigestBuffer,
                                 uint32_t FingerPrintDigestBufferLength);

int32_t SSLConnectionPeerFingerPrintGet(const SSLConnectionT *SSLConnection,
                                        SSLFingerPrintT FingerPrint,
                                        uint8_t *FingerPrintDigestBuffer,
                                        uint32_t FingerPrintDigestBufferLength);

int32_t SSLConnectionPeerCommonNameGet(const SSLConnectionT *SSLConnection,
                                       char *CommonNameBuffer,
                                       uint32_t CommonNameBufferLength);

int32_t SSLConnectionPeerCertificateVerification(const SSLConnectionT *SSLConnection);

int32_t SSLConnectionSRTPSuiteAndKeyInfoGet(const SSLConnectionT *SSLConnection,
                                            SRTPSuiteT *SRTPSuite,
                                            uint8_t *ClientKey,
                                            uint32_t ClientKeyLength,
                                            uint8_t *ServerKey,
                                            uint32_t ServerKeyLength);

const char *SSLConnectionCipherNameGet(const SSLConnectionT *SSLConnection);

int32_t SSLConnectionSetCiphers(SSLContextT *SSLConnection,
                                const char *OrderedCiphers[],
                                uint32_t CipherCount);

int32_t SSLConnectionServerNameSet(SSLConnectionT *SSLConnection, const char *ServerName);

#endif
