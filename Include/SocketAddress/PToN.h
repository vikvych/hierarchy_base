#ifndef HIERARCHY_SOCKETADDRESS_PTON_H
#define HIERARCHY_SOCKETADDRESS_PTON_H

#include "SocketAddress.h"

static const char DecDigits[] = "0123456789";
static const char HexSymbolsLowerCase[] = "0123456789abcdef";
static const char HexSymbolsUpperCase[] = "0123456789ABCDEF";

bool InetPToNv4(ByteT *N, const char *P);
bool InetPToNv6(ByteT *N, const char *P);

ErrnoT InetPToN(void *N, const char *P, int AddressFamily);

ErrnoT SocketAddressInetPToN(const char *P, SocketAddressT *N);

#endif
