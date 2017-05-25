#ifndef HIERARCHY_NETWORK_SOCKETS_H
#define HIERARCHY_NETWORK_SOCKETS_H

#include "../Debug/DebugLib.h"

#if SYSTEM_FAMILY_WINDOWS
#   include <WinSock2.h>
#else
#   define SOCKET int
#endif

ErrnoT NetworkSocketsInit(void);
void NetworkSocketsDestroy(void);

#endif
