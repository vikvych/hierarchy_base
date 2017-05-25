#ifndef HIERARCHY_TCP_H
#define HIERARCHY_TCP_H

#include "TCPConnection.h"

#define TCP_LISTEN_BACKLOG 10

TCPSocketT *TCPListen(const SocketAddressT *Address,
                      TCPConnectionCb *ConnectionCb,
                      void *Argument);

TCPConnectionT *TCPConnect(SocketAddressT *Address,
                           TCPOpenCb *OpenCb,
                           TCPDataCb *DataCb,
                           TCPCloseCb *CloseCb,
                           void *Argument);

ErrnoT TCPLocalAddressGet(TCPSocketT *TCPSocket,
                          SocketAddressT *LocalAddress);



#endif
