#ifndef HIERARCHY_NETWORK_INCLUDES_H
#define HIERARCHY_NETWORK_INCLUDES_H

#include <fcntl.h>
#include "../System/SystemLib.h"
#include "../Memory/MemoryLib.h"

extern void *NONULLIOS7;

#if SYSTEM_FAMILY != SYSTEM_FAMILY_WINDOWS
#   include <sys/socket.h>
#   if SYSTEM_OS != SYSTEM_OS_ANDROID
#       define __USE_MISC 1
#       include <net/if.h>
#       include <ifaddrs.h>
#   endif
#endif

#if SYSTEM_FAMILY != SYSTEM_FAMILY_WINDOWS
#   if SYSTEM_TYPE == SYSTEM_TYPE_MOBILE
#       if SYSTEM_OS != SYSTEM_OS_WINDOWSPHONE
            #include <netdb.h>
#       endif

#       if 0
static struct {
    int code;
    const char *msg;
} values[] = {
    { EAI_ADDRFAMILY, "Address family for hostname not supported" },
    { EAI_AGAIN, "Temporary failure in name resolution" },
    { EAI_BADFLAGS, "Bad value for ai_flags" },
    { EAI_FAIL, "Non-recoverable failure in name resolution" },
    { EAI_FAMILY, "ai_family not supported" },
    { EAI_MEMORY, "Memory allocation failure" },
    { EAI_NODATA, "No address associated with hostname" },
    { EAI_NONAME, "Name or service not known" },
    { EAI_SERVICE, "Servname not supported for ai_socktype" },
    { EAI_SOCKTYPE, "ai_socktype not supported" },
    { EAI_SYSTEM, "System error" },
    { EAI_OVERFLOW, "Argument buffer too small" },
#       ifdef EAI_INPROGRESS
    { EAI_INPROGRESS, N_("Processing request in progress") },
    { EAI_CANCELED, N_("Request canceled") },
    { EAI_NOTCANCELED, N_("Request not canceled") },
    { EAI_ALLDONE, N_("All requests done") },
    { EAI_INTR, N_("Interrupted by a signal") },
    { EAI_IDN_ENCODE, N_("Parameter string not correctly encoded") }
#       endif
  };

const char * gai_strerror (int code) {
    SizeT i = 0;
    for(i = 0; i < sizeof (values) / sizeof (values[0]); ++i){
        if(values[i].code == code){
            return values[i].msg;
        }
    }

    return "Unknown error";
}
#       endif
#   endif
#endif

#define NET_ADDRSTRLEN INET6_ADDRSTRLEN

#ifdef WIN32
#include <winsock2.h>
#include <ws2tcpip.h>
#ifdef OS_TYPE_DESKTOP
#include <iphlpapi.h>
#endif
#else
#include <sys/types.h>
#ifndef _BSD_SOCKLEN_T_
#define _BSD_SOCKLEN_T_ int
#endif
#include <sys/socket.h>
#include <netinet/in.h>
#include <net/if.h>
#include <arpa/inet.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <netdb.h>

#define __USE_POSIX 1
#define __USE_XOPEN2K 1
#define __USE_MISC 1

#ifdef __APPLE__
#include <sys/sysctl.h>
#ifndef TARGET_OS_IPHONE
#include <net/route.h>
#endif
#else
#define _BSD_SOURCE 1
#define _DEFAULT_SOURCE 1
#endif

#endif

#endif
