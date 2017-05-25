#ifndef HIERARCHY_HTTP_INCLUDES_H
#define HIERARCHY_HTTP_INCLUDES_H

#include "../SSL/SSLLib.h"
#include "../DNS/DNSLib.h"

typedef struct {
    MemoryBlockT Type;
    MemoryBlockT SubType;
    MemoryBlockT Parameters;
} HTTPMessageContentTypeT;

typedef struct {
    MemoryBlockT HTTPVersion;
    MemoryBlockT Method;
    MemoryBlockT Path;
    MemoryBlockT Parameters;
    WordT StatusCode;
    MemoryBlockT StatusReason;
    ListT HeaderList;
    HTTPMessageContentTypeT ContentType;
    MemoryBufferT *HTTPMessageBuffer;
    SizeT ContentLength;
} HTTPMessageT;

typedef struct HTTPSocketStruct HTTPSocketT;

typedef struct {
    ListNodeT ListNode;
    TimerT Timer;
    SocketAddressT PeerAddress;
    HTTPSocketT *HTTPSocket;
    TCPConnectionT *TCPConnection;
    TLSConnectionT *TLSConnection;
    MemoryBufferT *Data;
} HTTPConnectionT;

typedef void (HTTPRequestCallbackT)(HTTPConnectionT *HTTPConnection,
                                    const HTTPMessageT *HTTPMessage,
                                    void *Argument);

typedef void (HTTPDataCallbackT)(MemoryBufferT *Data,
                                 void *Argument);

typedef void (HTTPResponseCallbackT)(ErrnoT Error,
                                     const HTTPMessageT *HTTPMessage,
                                     void *Argument);

struct HTTPSocketStruct {
    ListT ConnectionList;
    TCPSocketT *TCPSocket;
    SSLContextT *SSLContext;
    HTTPRequestCallbackT *RequestCallback;
    void *Argument;
};

typedef struct HTTPRequestStruct {
    struct HTTPRequestStruct **SelfPtr;

    char *Host;
    WordT Port;

    DNSQueryT *DNSQuery;
    SocketAddressT ServerAddressArray[16];
    SizeT ServerAddressCount;

    bool IsSSL;
    SSLContextT *SSLContext;

    TLSConnectionT *TLSConnection;
    TCPConnectionT *TCPConnection;

    TimerT Timer;

    bool HasData;
    MemoryBufferT *RequestBuffer;
    MemoryBufferT *ResponseBuffer;

    HTTPResponseCallbackT *ResponseCallback;
    HTTPDataCallbackT *DataCallback;

    void *Argument;

    QWordT ConnectionTimeout;
    QWordT ResponseTimeout;
} HTTPRequestT;

typedef struct {
    DNSClientT *DNSClient;
    SSLContextT *SSLContext;
} HTTPClientT;

#endif
