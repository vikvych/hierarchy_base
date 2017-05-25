#ifndef HIERARCHY_DNS_RESOURCE_RECORD_H
#define HIERARCHY_DNS_RESOURCE_RECORD_H

#include "../List/ListLib.h"
#include "../MemoryBuffer/MemoryBufferLib.h"

#define DNS_CLASS_IN 0x0001
#define DNS_QCLASS_ANY 0x00FF

typedef struct {
    ListNodeT he;
    SizeT pos;
    char *name;
} DNSDNAMET;

typedef enum {
    DNS_RECOURCE_RECORD_TYPE_A = 0x0001,
    DNS_RECOURCE_RECORD_TYPE_NS = 0x0002,
    DNS_RECOURCE_RECORD_TYPE_CNAME = 0x0005,
    DNS_RECOURCE_RECORD_TYPE_SOA = 0x0006,
    DNS_RECOURCE_RECORD_TYPE_PTR = 0x000C,
    DNS_RECOURCE_RECORD_TYPE_MX = 0x000F,
    DNS_RECOURCE_RECORD_TYPE_AAAA = 0x001C,
    DNS_RECOURCE_RECORD_TYPE_SRV = 0x0021,
    DNS_RECOURCE_RECORD_TYPE_NAPTR = 0x0023,
    DNS_RECOURCE_RECORD_QTYPE_IXFR = 0x00FB,
    DNS_RECOURCE_RECORD_QTYPE_AXFR = 0x00FC,
    DNS_RECOURCE_RECORD_QTYPE_ANY = 0x00FF
} DNSResourceRecordTypeT;

typedef struct {
    ListNodeT Node;
    ListNodeT NodePriv;

    char *Name;
    WordT Type;
    WordT DNSClass;

    DWordT TTL;
    WordT ResourceDataLength;

    union {
        struct {
            DWordT Address;
        } A;

        struct {
            char *DNAME;
        } NS;

        struct {
            char *CNAME;
        } CNAME;

        struct {
            char *PrimaryNameServer;
            char *HostMaster;
            DWordT SerialNumber;
            DWordT Refresh;
            DWordT Retry;
            DWordT Expire;
            DWordT MinTTL;
        } SOA;

        struct {
            char *DNAME;
        } PTR;

        struct {
            WordT RelativePreference;
            char *Exchange;
        } MX;

        struct {
            ByteT Address[16];
        } AAAA;

        struct {
            WordT Priority;
            WordT Weight;
            WordT Port;
            char *Target;
        } SRV;

        struct {
            WordT Order;
            WordT Preference;
            char *Flags;
            char *Services;
            char *Regexp;
            char *Replacement;
        } NAPTR;

    } RecordData;
} DNSResourceRecordT;

ErrnoT DNSDNAMESerialize(MemoryBufferT *EncodedBuffer,
                         const char *DomainName);

char *DNSDNAMEParse(MemoryBufferT *EncodedBuffer,
                    SizeT StartPosition);

ErrnoT DNSCharStringEncode(MemoryBufferT *EncodedBuffer,
                            const char *CharString);

char *DNSCharStringParse(MemoryBufferT *EncodedBuffer);

void DNSResourceRecordDestroy(void *RecourceRecordVoid);
DNSResourceRecordT *DNSResourceRecordInit(void);

ErrnoT DNSResourceRecordSerialize(MemoryBufferT *EncodedBuffer,
                                  const DNSResourceRecordT *RecourceRecord,
                                  DWordT TTLOffset);

DNSResourceRecordT *DNSResourceRecordParse(MemoryBufferT *EncodedBuffer,
                                           SizeT StartPosition);

bool DNSResourceRecordCompare(const DNSResourceRecordT *RecourceRecord1,
                              const DNSResourceRecordT *RecourceRecord2,
                              bool ComapareDataFlag);

const char *DNSResourceRecordTypeStringGet(DNSResourceRecordTypeT ResourceRecordType);

const char *DNSResourceRecordClassStringGet(WordT DNSClass);

ErrnoT DNSResourceRecordPrint(PrintT *Print,
                              const DNSResourceRecordT *DNSRecourceRecord);

bool DNSResourceRecordDeleteCallback(ListNodeT *ListNode, void *Argument);

#endif
