#ifndef HIERARCHY_DNS_UDPCLIENT_H
#define HIERARCHY_DNS_UDPCLIENT_H

#include "../UDP/UDPLib.h"
#include "DNSQuery.h"

#define DNS_SENT_COUNT_MAX 32

void DNSUDPClientOnTimeout(void *Argument);

void DNSUDPClientOnData(SocketAddressT *SourceAddress,
                        MemoryBufferT *Data,
                        void *Argument);

ErrnoT DNSUDPClientSend(DNSQueryT *DNSQuery);

#endif
