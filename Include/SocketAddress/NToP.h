#ifndef HIERARCHY_SOCKETADDRESS_NTOP_H
#define HIERARCHY_SOCKETADDRESS_NTOP_H

#include "SocketAddress.h"

const char *InetNToPv4(ByteT *N,
                       char *P,
                       SizeT PSize);

const char *InetNToPv6(ByteT *N,
                       char *P,
                       SizeT PSize);

const char* InetNToP(int AddressFamily,
                     void *N,
                     char *P,
                     SizeT PSize);

ErrnoT SocketAddressInetNToP(const SocketAddressT *N,
                             char *P,
                             SizeT PSize);

#endif
