#ifndef HIERARCHY_DNS_TCPCLIENT_H
#define HIERARCHY_DNS_TCPCLIENT_H

#include "../List/ListLib.h"
#include "../TCP/TCPLib.h"
#include "../Timer/TimerLib.h"

#include "DNSClient.h"

typedef struct {
    ListT QueryList;
    TimerT Timer;
    SocketAddressT ServerAddress;
    TCPConnectionT *Connection;
    MemoryBufferT *Data;
    bool FlagConnected;
    WordT FrameLength;
    DNSClientT *DNSClient;
} DNSTCPClientT;

DNSTCPClientT *DNSTCPClientInit(DNSClientT *DNSClient,
                         const SocketAddressT *ServerAddress);

void DNSTCPClientDestroy(void *DNSTCPClientVoid);
void DNSTCPClientOnTimeout(void *DNSTCPClientVoid);
void DNSTCPClientCloseConnection(DNSTCPClientT *TCPClient, ErrnoT Error);
void DNSTCPClientTimeoutCb(void *Argument);

#endif
