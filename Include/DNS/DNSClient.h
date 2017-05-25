#ifndef HIERARCHY_DNS_CLIENT_H
#define HIERARCHY_DNS_CLIENT_H

#include "../BinaryTree/BinaryTreeLib.h"
#include "../UDP/UDPLib.h"

#define DNS_CLIENT_SERVER_COUNT_MAX 32
#define DNS_CLIENT_CONNECTION_TIMEOUT 5000
#define DNS_CLIENT_IDLE_TIMEOUT 5000

typedef struct {
    BinaryTreeT *Queries;
    BinaryTreeT *TCPConnections;
    UDPSocketT *UDPSocket;
    SocketAddressT Servers[DNS_CLIENT_SERVER_COUNT_MAX];
    SizeT ServerCount;
    DWordT ConnectionTimeout;
    DWordT IdleTimeout;

    DWordT Id;
} DNSClientT;

void DNSClientDestroy(void *DNSClientVoid);

ErrnoT DNSClientReplyRecv(DNSClientT *DNSClient,
                           MemoryBufferT *ReplyData);

DNSClientT *DNSClientInit(DWordT ConnectionTimeout,
                          DWordT IdleTimeout,
                          SocketAddressT *DNSServers,
                          SizeT DNSServerCount);

ErrnoT DNSClientServersSet(DNSClientT *DNSClient,
                  SocketAddressT *NameServers,
                  SizeT NameServerCount);

#endif
