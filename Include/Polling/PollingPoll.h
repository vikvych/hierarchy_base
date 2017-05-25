#ifndef HIERARCHY_POLLING_POLL_H
#define HIERARCHY_POLLING_POLL_H

#include <sys/types.h>
#undef _STRICT_ANSI
#include <string.h>
#include <signal.h>
#include <locale.h>
#include <stdlib.h>
#include <sys/types.h>
#include <time.h>
#include <assert.h>
#include <string.h>

#ifdef WIN32
#   ifndef FD_SETSIZE
#       define FD_SETSIZE 1024
#   endif
#else
#   include <sys/time.h>
#   include <sys/select.h>
#endif

#include <openssl/crypto.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#include "../Error/ErrorLib.h"
#include "../Thread/ThreadLib.h"
#include "../Debug/DebugLib.h"
#include "../Network/NetworkLib.h"
#include "../Lock/LockLib.h"
#include "../List/ListLib.h"
#include "../BinaryTree/BinaryTreeLib.h"
#include "../Time/TimeLib.h"
#include "../Math/MathLib.h"

#ifdef WIN32
#   ifndef POLLIN
#       define POLLIN 0x01
#   endif

#   ifndef POLLPRI
#       define POLLPRI 0x02
#   endif

#   ifndef POLLOUT
#       define POLLOUT 0x04
#   endif

#   ifndef POLLERR
#       define POLLERR 0x08
#   endif

#   ifndef POLLHUP
#       define POLLHUP 0x10
#   endif

#   ifndef POLLNVAL
#       define POLLNVAL	0x20
#   endif

#else
    #define SOCKET_ERROR -1
    #define INVALID_SOCKET -1
    #include <sys/poll.h>
#endif

typedef struct {
    SOCKET Socket;

    short Events;
    short ReturnEvents;
} PollSocketT;

SSizeT PollingPoll(PollSocketT *SocketList,
                   DWordT SocketCount,
                   DWordT TimeoutMS);

#endif
