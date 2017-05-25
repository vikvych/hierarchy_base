#ifndef HIERARCHY_TCP_SOCKET_H
#define HIERARCHY_TCP_SOCKET_H

#include <stdlib.h>
#include <string.h>

#ifdef HAVE_IO_H
#include <io.h>
#endif

#if !defined(WIN32)
#   define __USE_POSIX 1
#   define __USE_XOPEN2K 1
#   define __USE_MISC 1
#   include <netdb.h>
#endif

#ifdef __APPLE__
#   include "TargetConditionals.h"
#endif

#include "../Memory/MemoryLib.h"
#include "../MemoryBuffer/MemoryBufferLib.h"
#include "../List/ListLib.h"
#include "../Polling/PollingLib.h"
#include "../SocketAddress/SocketAddressLib.h"
#include "../Network/NetworkLib.h"

#include "../Debug/DebugLib.h"

typedef void (TCPConnectionCb)(const SocketAddressT *RemoteAddress,
                                      void *Argument);

typedef struct {
    SOCKET Socket;
    SOCKET ConnectionFD;
    TCPConnectionCb *ConnectionCb;
    void *Argument;
} TCPSocketT;

void TCPSocketDestroy(void *TCPSocketVoid);

TCPSocketT *TCPSocketInit(const SocketAddressT *ListenAddress,
                          TCPConnectionCb *ConnectionCallback,
                          void *Argument);

ErrnoT TCPSocketBind(TCPSocketT *TCPSocket,
                      const SocketAddressT *BindAddress);

ErrnoT TCPSocketListen(TCPSocketT *TCPSocket,
                     int BackLog);

ErrnoT TCPSocketLocalAddressGet(SocketAddressT *SocketAddress,
                                const TCPSocketT *TCPSocket);

void TCPSocketLingerOptionSet(SOCKET Socket);

void TCPSocketConnectionCb(PollingSocketFlagsT FDFlags, void *TCPSocketVoid);

void TCPSocketReject(TCPSocketT *TCPSocket);

#endif
