#ifndef HIERARCHY_SOCKETADDRESS_LIB_H
#define HIERARCHY_SOCKETADDRESS_LIB_H

#include "SocketAddress.h"
#include "NToP.h"
#include "PToN.h"

extern const struct SocketAddressLibrary {
    void (*Init)(SocketAddressT *SocketAddress,
                 int AddressFamily);

    ErrnoT (*SetMemoryBlock)(SocketAddressT *SocketAddress,
                             const MemoryBlockT *Address,
                             WordT Port);

    ErrnoT (*SetString)(SocketAddressT *SocketAddress,
                        const char *Address,
                        WordT Port);

    void (*SetIn4)(SocketAddressT *SocketAddress,
                   DWordT Address,
                   WordT Port);

    void (*SetIn6)(SocketAddressT *SocketAddress,
                   const ByteT *Address,
                   WordT Port);

    ErrnoT (*SetSockAddr)(SocketAddressT *SocketAddress,
                           const struct sockaddr *SockAddr);

    void (*SetPort)(SocketAddressT *SocketAddress,
                    WordT Port);

    ErrnoT (*Parse)(SocketAddressT *SocketAddress,
                    const char *String,
                    SizeT StringLength);

    int (*Family)(const SocketAddressT *SocketAddress);

    DWordT (*GetIn4)(const SocketAddressT *SocketAddress);

    void (*GetIn6)(const SocketAddressT *SocketAddress,
                   ByteT *In6Addr);

    ErrnoT (*NToP)(const SocketAddressT *N,
                   char *P,
                   SizeT PSize);

    WordT (*GetPort)(const SocketAddressT *SocketAddress);

    bool (*IsSet)(const SocketAddressT *SocketAddress,
                  SocketAddressFlagsT Flags);

    void (*Copy)(SocketAddressT *Destination,
                 SocketAddressT *Source);

    bool (*Compare)(const SocketAddressT *SocketAddress1,
                    const SocketAddressT *SocketAddress2,
                    SocketAddressFlagsT Flags);

    bool (*IsLinkLocalAddress)(const SocketAddressT *SocketAddress);
    bool (*IsLoopback)(const SocketAddressT *SocketAddress);
    bool (*IsAny)(const SocketAddressT *SocketAddress);

    ErrnoT (*PrintAddress)(PrintT *Print,
                           const SocketAddressT *SocketAddress);

    ErrnoT (*PrintAddressPort)(PrintT *Print,
                               const SocketAddressT *SocketAddress);

} SocketAddressLib;

#endif
