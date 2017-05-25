#ifndef HIERARCHY_DNS_RESOURCE_RECORD_LIST_H
#define HIERARCHY_DNS_RESOURCE_RECORD_LIST_H

#include "DNSResourceRecord.h"

#define DNS_RESOURCE_RECORD_CNAME_RECURSION_MAX 16

typedef bool(DNSResourceRecordListCb)(DNSResourceRecordT *RecourceRecord,
                                             void *Argument);

void DNSResourceRecordListSort(ListT *RecourceRecordList,
                               DNSResourceRecordTypeT ResourceRecordType,
                               DWordT SortKey);

void DNSResourceRecordListAddressesSort(ListT *RecourceRecordList,
                                        DWordT SortKey);

DNSResourceRecordT *DNSResourceRecordListApply(ListT *RecourceRecordList,
                                               const char *DomainNameFilter,
                                               DNSResourceRecordTypeT ResourceRecordType1,
                                               DNSResourceRecordTypeT ResourceRecordType2,
                                               WordT DNSClass,
                                               bool CNAMERecursionFlag,
                                               SizeT Depth,
                                               DNSResourceRecordListCb *ResourceRecordListCb,
                                               void *Argument);

DNSResourceRecordT *DNSResourceRecordListApplyByType(ListT *RecourceRecordList,
                                                     const char *DomainNameFilter,
                                                     DNSResourceRecordTypeT ResourceRecordType,
                                                     WordT DNSClass,
                                                     bool CNAMERecursionFlag,
                                                     DNSResourceRecordListCb *ResourceRecordListCb,
                                                     void *Argument);

DNSResourceRecordT *DNSResourceRecordListApplyByTwoTypeTypes(ListT *RecourceRecordList,
                                                             const char *DomainNameFilter,
                                                             DNSResourceRecordTypeT ResourceRecordType1,
                                                             DNSResourceRecordTypeT ResourceRecordType2,
                                                             WordT DNSClass,
                                                             bool CNAMERecursionFlag,
                                                             DNSResourceRecordListCb *ResourceRecordListCb,
                                                             void *Argument);

DNSResourceRecordT *DNSResourceRecordListSearch(ListT *RecourceRecordList,
                                                const char *DomainNameFilter,
                                                DNSResourceRecordTypeT ResourceRecordType,
                                                WordT DNSClass,
                                                bool CNAMERecursionFlag);

#endif
