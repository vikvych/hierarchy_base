#ifndef HIERARCHY_NETWORK_TEXTFORMAT_H
#define HIERARCHY_NETWORK_TEXTFORMAT_H

#include "NetworkIncludes.h"

#define IPPROTO_UDP_TYPE "IPPROTO_UDP"
#define IPPROTO_TCP_TYPE "IPPROTO_TCP"
#define IPPROTO_SCTP_TYPE "IPPROTO_SCTP"
#define IPPROTO_UNKNOWN_TYPE "IPPROTO_UNKNOWN"

#define AF_INET_TYPE "AF_INET"
#define AF_INET6_TYPE "AF_INET6"
#define AF_UNSPEC_TYPE "AF_UNSPEC"
#define AF_UNKNOWN_TYPE "AF_UNKNOWN"

const char *NetworkProtocolName(int Protocol);
const char *NetworkAddressFamilyName(int AddressFamily);

#endif
