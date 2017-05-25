#ifndef HIERARCHY_NETWORK_SOCKET_OPTIONS_H
#define HIERARCHY_NETWORK_SOCKET_OPTIONS_H

#include "NetworkIncludes.h"
#include "NetworkSockets.h"
#include "../Debug/DebugLib.h"

ErrnoT NetworkSocketOptionsBlockingSet(SOCKET FD,
                                       bool Blocking);

ErrnoT NetworkSocketOptionsReusableSet(SOCKET FD,
                                       bool Reusable);

#endif
