#ifndef HIERARCHY_DNS_CLIENT_QUERY_H
#define HIERARCHY_DNS_CLIENT_QUERY_H

#include "DNSQuery.h"

DNSQueryT *DNSClientQuery(DNSClientT *DNSClient,
                          const char *DNSName,
                          WordT ResourceRecordType,
                          WordT DNSClass,
                          bool RecursionDesired,
                          DNSQueryCb *QueryCallback,
                          void *Argument);

DNSQueryT *DNSClientQuerySRV(DNSClientT *DNSClient,
                             const char *DNSName,
                             WordT ResourceRecordType,
                             WordT DNSClass,
                             int Proto,
                             const SocketAddressT *DNSNameservers,
                             const SizeT DNSNameserverCount,
                             bool RecursionDesired,
                             DNSQueryCb *QueryCallback,
                             void *Argument);

DNSQueryT *DNSClientQueryNotify(DNSClientT *DNSClient,
                                const char *DNSName,
                                WordT ResourceRecordType,
                                WordT DNSClass,
                                const DNSResourceRecordT *RecourceRecordAnswer,
                                int Proto,
                                const SocketAddressT *DNSNameservers,
                                const SizeT DNSNameserverCount,
                                DNSQueryCb *QueryCallback,
                                void *Argument);

#endif
