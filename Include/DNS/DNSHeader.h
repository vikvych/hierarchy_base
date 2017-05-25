#ifndef HIERARCHY_DNS_HEADER_H
#define HIERARCHY_DNS_HEADER_H

#include "../MemoryBuffer/MemoryBufferLib.h"

#define DNS_HEADER_SIZE 12

typedef enum {
    DNS_OPCODE_QUERY = 0,
    DNS_OPCODE_IQUERY = 1,
    DNS_OPCODE_STATUS = 2,
    DNS_OPCODE_NOTIFY = 4
} DNSHeaderOpCodeT;

typedef enum {
    DNS_RESPONSECODE_OK = 0,
    DNS_RESPONSECODE_FMT_ERR = 1,
    DNS_RESPONSECODE_SRV_FAIL = 2,
    DNS_RESPONSECODE_NAME_ERR = 3,
    DNS_RESPONSECODE_NOT_IMPL = 4,
    DNS_RESPONSECODE_REFUSED = 5,
    DNS_RESPONSECODE_NOT_AUTH = 9
} DNSHeaderResposeCodeT;

typedef enum {
    DNS_FLAG_QUERY_RESPONSE = 15,
    DNS_FLAG_OPCODE = 11,
    DNS_FLAG_AUTH_ANSWER = 10,
    DNS_FLAG_TRUNCATED = 9,
    DNS_FLAG_RECURSION_DESIRED = 8,
    DNS_FLAG_RECURSION_AVAILABLE = 7,
    DNS_FLAG_ZERO = 4
} DNSHeaderFlagsT;

typedef struct {
    WordT Id;
    bool QueryResponse;
    ByteT OpCode;
    bool FlagAuthAnswer;
    bool FlagTruncated;
    bool FlagRecursionDesired;
    bool FlagRecursionAvailable;
    ByteT FlagZero;
    ByteT ResponseCode;
    WordT TotalQuestions;
    WordT TotalAnswers;
    WordT TotalAuthResourceRecords;
    WordT TotalAdditionalResourceRecords;
} DNSHeaderT;

ErrnoT DNSHeaderSerialize(MemoryBufferT *EncodedHeader,
                          const DNSHeaderT *Header);

ErrnoT DNSHeaderParse(DNSHeaderT *Header,
                      MemoryBufferT *EncodedHeader);

const char *DNSHeaderOpCodeStringNameGet(ByteT OpCode);

const char *DNSHeaderResponseCodeStringNameGet(ByteT ResponseCode);

#endif
