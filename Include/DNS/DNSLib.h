#ifndef HIERARCHY_DNS_LIB_H
#define HIERARCHY_DNS_LIB_H

#include "DNSClient.h"
#include "DNSClientQuery.h"
#include "DNSResourceRecordList.h"

extern const struct DNSLibrary {
    struct {
        DNSClientT *(*Init)(DWordT ConnectionTimeout,
                            DWordT IdleTimeout,
                            SocketAddressT *DNSServers,
                            SizeT DNSServerCount);

        ErrnoT (*ServersSet)(DNSClientT *DNSClient,
                              SocketAddressT *NameServers,
                              SizeT NameServerCount);
    } Client;

    struct {
        DNSQueryT *(*Query)(DNSClientT *DNSClient,
                            const char *DNSName,
                            WordT ResourceRecordType,
                            WordT DNSClass,
                            bool RecursionDesired,
                            DNSQueryCb *QueryCallback,
                            void *Argument);

        DNSQueryT *(*QuerySRV)(DNSClientT *DNSClient,
                               const char *DNSName,
                               WordT ResourceRecordType,
                               WordT DNSClass,
                               int Proto,
                               const SocketAddressT *DNSNameservers,
                               const SizeT DNSNameserverCount,
                               bool RecursionDesired,
                               DNSQueryCb *QueryCallback,
                               void *Argument);

        DNSQueryT *(*QueryNotify)(DNSClientT *DNSClient,
                                  const char *DNSName,
                                  WordT ResourceRecordType,
                                  WordT DNSClass,
                                  const DNSResourceRecordT *RecourceRecordAnswer,
                                  int Proto,
                                  const SocketAddressT *DNSNameservers,
                                  const SizeT DNSNameserverCount,
                                  DNSQueryCb *QueryCallback,
                                  void *Argument);
    } ClientQuery;

    struct {
        void (*Sort)(ListT *RecourceRecordList,
                     DNSResourceRecordTypeT ResourceRecordType,
                     DWordT SortKey);

        void (*AddressesSort)(ListT *RecourceRecordList,
                              DWordT SortKey);

        DNSResourceRecordT *(*Apply)(ListT *RecourceRecordList,
                                     const char *DomainNameFilter,
                                     DNSResourceRecordTypeT ResourceRecordType1,
                                     DNSResourceRecordTypeT ResourceRecordType2,
                                     WordT DNSClass,
                                     bool CNAMERecursionFlag,
                                     SizeT Depth,
                                     DNSResourceRecordListCb *ResourceRecordListCallback,
                                     void *Argument);

        DNSResourceRecordT *(*ApplyByType)(ListT *RecourceRecordList,
                                           const char *DomainNameFilter,
                                           DNSResourceRecordTypeT ResourceRecordType,
                                           WordT DNSClass,
                                           bool CNAMERecursionFlag,
                                           DNSResourceRecordListCb *ResourceRecordListCallback,
                                           void *Argument);

        DNSResourceRecordT *(*ApplyByTwoTypeTypes)(ListT *RecourceRecordList,
                                                   const char *DomainNameFilter,
                                                   DNSResourceRecordTypeT ResourceRecordType1,
                                                   DNSResourceRecordTypeT ResourceRecordType2,
                                                   WordT DNSClass,
                                                   bool CNAMERecursionFlag,
                                                   DNSResourceRecordListCb *ResourceRecordListCallback,
                                                   void *Argument);

        DNSResourceRecordT *(*Search)(ListT *RecourceRecordList,
                                                        const char *DomainNameFilter,
                                                        DNSResourceRecordTypeT ResourceRecordType,
                                                        WordT DNSClass,
                                                        bool CNAMERecursionFlag);
    } RRList;
} DNSLib;

#endif
