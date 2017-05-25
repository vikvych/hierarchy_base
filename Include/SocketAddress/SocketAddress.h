#ifndef HIERARCHY_SOCKETADDRESS_H
#define HIERARCHY_SOCKETADDRESS_H

#include <string.h>

#include "../Endian/EndianLib.h"

#if defined(WIN32)
#include <winsock2.h>
#include <ws2tcpip.h>
#ifdef _MSC_VER
#pragma warning (disable: 4090)
#endif
#include <windows.h>
#else
#define _BSD_SOURCE 1
#define _DEFAULT_SOURCE 1
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#define __USE_BSD 1
#include <arpa/inet.h>
#define __USE_POSIX 1
#include <netdb.h>
#define __USE_MISC 1
#include <net/if.h>
#endif

#include "../MemoryBuffer/MemoryBufferLib.h"
#include "../Debug/DebugLib.h"

#if (SYSTEM_FAMILY != SYSTEM_FAMILY_WINDOWS)
#   if (SYSTEM_FAMILY != SYSTEM_FAMILY_UNIX)
typedef DWordT socklen_t;
#   else
#       if (SYSTEM_TYPE == SYSTEM_TYPE_DESKTOP)
typedef DWordT socklen_t;
#       endif
#   endif
#endif

#define INET_INADDR_SIZE 4
#define INET_IN6ADDR_SIZE 16

typedef struct {
    union {
        struct sockaddr SockAddr;
        struct sockaddr_in SockAddrIn4;
        struct sockaddr_in6 SockAddrIn6;
        ByteT padding[28];
    } Address;

    socklen_t Size;
} SocketAddressT;

typedef enum {
    SOCKETADDRESS_FLAG_ADDRESS = 1<<0,
    SOCKETADDRESS_FLAG_PORT = 1<<1,
    SOCKETADDRESS_FLAG_BOTH = SOCKETADDRESS_FLAG_ADDRESS | SOCKETADDRESS_FLAG_PORT
} SocketAddressFlagsT;

void SocketAddressInit(SocketAddressT *SocketAddress,
                       int AddressFamily);

ErrnoT SocketAddressSetMemoryBlock(SocketAddressT *SocketAddress,
                                   const MemoryBlockT *Address,
                                   WordT Port);

ErrnoT SocketAddressSetString(SocketAddressT *SocketAddress,
                              const char *Address,
                              WordT Port);

void SocketAddressSetIn4(SocketAddressT *SocketAddress,
                         DWordT Address,
                         WordT Port);

void SocketAddressSetIn6(SocketAddressT *SocketAddress,
                         const ByteT *Address,
                         WordT Port);

ErrnoT SocketAddressSetSockAddr(SocketAddressT *SocketAddress,
                                 const struct sockaddr *SockAddr);

void SocketAddressSetPort(SocketAddressT *SocketAddress,
                          WordT Port);

ErrnoT SocketAddressParse(SocketAddressT *SocketAddress,
                           const char *String,
                           SizeT StringLength);

int SocketAddressFamily(const SocketAddressT *SocketAddress);

DWordT SocketAddressGetIn4(const SocketAddressT *SocketAddress);

void SocketAddressGetIn6(const SocketAddressT *SocketAddress,
                         ByteT *In6Addr);

ErrnoT SocketAddressNToP(const SocketAddressT *N,
                         char *P,
                         SizeT PSize);

WordT SocketAddressGetPort(const SocketAddressT *SocketAddress);

bool SocketAddressIsSet(const SocketAddressT *SocketAddress,
                        SocketAddressFlagsT Flags);

void SocketAddressCopy(SocketAddressT *Destination,
                       SocketAddressT *Source);

bool SocketAddressCompare(const SocketAddressT *SocketAddress1,
                          const SocketAddressT *SocketAddress2,
                          SocketAddressFlagsT Flags);

bool SocketAddressIsLinkLocalAddress(const SocketAddressT *SocketAddress);
bool SocketAddressIsLoopback(const SocketAddressT *SocketAddress);
bool SocketAddressIsAny(const SocketAddressT *SocketAddress);

ErrnoT SocketAddressPrintAddress(PrintT *Print,
                                 const SocketAddressT *SocketAddress);

ErrnoT SocketAddressPrintAddressPort(PrintT *Print,
                                     const SocketAddressT *SocketAddress);

#endif
