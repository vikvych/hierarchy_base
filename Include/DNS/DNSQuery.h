#ifndef HIERARCHY_DNS_QUERY_H
#define HIERARCHY_DNS_QUERY_H

#include "../List/ListLib.h"
#include "../MemoryBuffer/MemoryBufferLib.h"
#include "../System/SystemLib.h"

#include "DNSHeader.h"
#include "DNSResourceRecord.h"
#include "DNSClient.h"
#include "DNSTCPClient.h"

typedef void(DNSQueryCb)(ErrnoT Error,
                         const DNSHeaderT *Header,
                         ListT *AnswerList,
                         ListT *AuthList,
                         ListT *AdditionalList,
                         void *Argument);

typedef struct {
    ListNodeT ListNodeTCPClient;

    TimerT Timer;
    MemoryBufferT Data;
    ListT ResourceRecordLists[3];
    char *DNSName;
    const SocketAddressT *DNSNameservers;
    SizeT DNSNameserverCount;

    DNSTCPClientT *TCPClient;
    DNSClientT *DNSClient;

    DWordT SentCount;
    WordT Id;

    WordT RecourceRecordType;
    WordT DNSClass;
    ByteT OpCode;

    DNSQueryCb *QueryCallback;
    void *Argument;
} DNSQueryT;

typedef struct {
    DNSHeaderT Header;
    char *DNSName;
    WordT RecourceRecordType;
    WordT DNSClass;
} DNSReplyT;

void DNSQueryAbort(DNSQueryT *DNSQuery);

void DNSQueryDestroy(void *DNSQueryVoid);

DNSQueryT *DNSQuery(DNSClientT *DNSClient,
                    ByteT OpCode,
                    const char *DNSName,
                    WordT ResourceRecordType,
                    WordT DNSClass,
                    const DNSResourceRecordT *AnswerResourceRecord,
                    int Proto,
                    const SocketAddressT *DNSNameservers,
                    SizeT DNSNameserverCount,
                    bool FlagAuthAnswer,
                    bool RecursionDesired,
                    DNSQueryCb *QueryCallback,
                    void *Argument);

bool DNSQueryCloseCallback(ListNodeT  *ListNode,
                           void *Argument);

bool DNSQueryCompareCallback(char *ListNode,
                             void *Argument);

void DNSQueryCallback(DNSQueryT *DNSQuery,
                      ErrnoT Error,
                      const DNSHeaderT *Header,
                      ListT *AnswerList,
                      ListT *AuthList,
                      ListT *AdditionalList);

ErrnoT DNSQueryTCPSend(DNSQueryT *DNSQuery);

#endif
