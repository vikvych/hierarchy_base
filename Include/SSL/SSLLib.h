#ifndef HIERARCHYBASE_SSL_LIB_H
#define HIERARCHYBASE_SSL_LIB_H

#include "SSL.h"
#include "DTLS.h"
#include "TLS.h"

extern const struct SSLLibrary {
    struct {
        void (*Destroy)(void *TLSConnectionVoid);
        int32_t (*Init)(TLSConnectionT **TLSConnectionPtr,
                                   SSLContextT *SSLContext,
                                   TCPConnectionT *TCPConnection,
                                   int32_t Priority);
    } TLS;

    struct {
        DTLSSocketT *(*Listen)(const SocketAddressT *ListenAddress,
                               UDPSocketT *UDPSocket,
                               int32_t Priority,
                               DTLSConnectionCallbackT *ConnectionCallback,
                               void *Argument);

        UDPSocketT *(*UDPSocketGet)(DTLSSocketT *DTLSSocket);

        void (*SocketMTUSet)(DTLSSocketT *DTLSSocket, uint32_t MTU);

        int32_t (*ConnectionConnect)(DTLSConnectionT **DTLSConnectionPtr,
                                      SSLContextT *SSLContext,
                                      DTLSSocketT *DTLSSocket,
                                      const SocketAddressT *peer,
                                      DTLSOpenCallbackT *OpenCallback,
                                      DTLSDataCallbackT *DataCallback,
                                      DTLSCloseCallbackT *CloseCallback,
                                      void *Argument);

        int32_t (*ConnectionAccept)(DTLSConnectionT **DTLSConnectionPtr,
                                     SSLContextT *SSLContext,
                                     DTLSSocketT *DTLSSocket,
                                     DTLSOpenCallbackT *OpenCallback,
                                     DTLSDataCallbackT *DataCallback,
                                     DTLSCloseCallbackT *CloseCallback,
                                     void *Argument);

        int32_t (*ConnectionSend)(DTLSConnectionT *DTLSConnection,
                                   MemoryBufferT *Data);

        void (*ConnectionSetCallbacks)(DTLSConnectionT *DTLSConnection,
                                       DTLSOpenCallbackT *OpenCallback,
                                       DTLSDataCallbackT *DataCallback,
                                       DTLSCloseCallbackT *CloseCallback,
                                       void *Argument);
    } DTLS;

    struct {
        struct {
            void (*Destroy)(void *SSLContextVoid);

            SSLContextT *(*Init)(SSLMethodT Method,
                                 const char *PrivateKeyFile,
                                 const char *PrivateKeyPassword);

            int32_t (*AddCA)(SSLContextT *SSLContext,
                                    const char *CAPath);

            int32_t (*SetCertificatePEM)(SSLContextT *SSLContext,
                                                const char *CertificatePEM,
                                                uint32_t CertificatePEMLength);

            void (*SetClientVerification)(SSLContextT *SSLContext);

            int32_t (*SetSRTPSuites)(SSLContextT *SSLContext,
                                            const char *SRTPSuites);

            int32_t (*FingerPrintGet)(const SSLContextT *SSLContext,
                                             SSLFingerPrintT FingerPrint,
                                             uint8_t *FingerPrintDigestBuffer,
                                             uint32_t FingerPrintDigestBufferLength);
        } Context;

        struct {
            int32_t (*PeerFingerPrintGet)(const SSLConnectionT *SSLConnection,
                                                    SSLFingerPrintT FingerPrint,
                                                    uint8_t *FingerPrintDigestBuffer,
                                                    uint32_t FingerPrintDigestBufferLength);

            int32_t (*PeerCommonNameGet)(const SSLConnectionT *SSLConnection,
                                                   char *CommonNameBuffer,
                                                   uint32_t CommonNameBufferLength);

            int32_t (*PeerCertificateVerification)(const SSLConnectionT *SSLConnection);

            int32_t (*SRTPSuiteAndKeyInfoGet)(const SSLConnectionT *SSLConnection,
                                                        SRTPSuiteT *SRTPSuite,
                                                        uint8_t *ClientKey,
                                                        uint32_t ClientKeyLength,
                                                        uint8_t *ServerKey,
                                                        uint32_t ServerKeyLength);

            const char *(*CipherNameGet)(const SSLConnectionT *SSLConnection);

            int32_t (*SetCiphers)(SSLContextT *SSLConnection,
                                            const char *OrderedCiphers[],
                                            uint32_t CipherCount);

            int32_t (*ServerNameSet)(SSLConnectionT *SSLConnection, const char *ServerName);
        } Connection;
    } SSL;
} SSLLib;

#endif
