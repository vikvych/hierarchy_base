#ifndef HIERARCHY_SYSTEM_H
#define HIERARCHY_SYSTEM_H

#include <sys/types.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <ctype.h>
#include <stdlib.h>

#define SYSTEM_FAMILY_WINDOWS 0
#define SYSTEM_FAMILY_UNIX 1
#define SYSTEM_FAMILY_DARWIN 2

#define SYSTEM_TYPE_DESKTOP 0
#define SYSTEM_TYPE_MOBILE 1

#define SYSTEM_ARCH_X86 0
#define SYSTEM_ARCH_X64 1

#define SYSTEM_OS_WINDOWS 0
#define SYSTEM_OS_LINUX 1
#define SYSTEM_OS_MACOSX 2
#define SYSTEM_OS_WINDOWSPHONE 3
#define SYSTEM_OS_ANDROID 4
#define SYSTEM_OS_IOS 5

#if defined(_WIN32) || defined( _WIN64)
#   include <WinSock2.h>
#   define __BYTE_ORDER 0
#   define __BIG_ENDIAN 1
#   define __LITTLE_ENDIAN 0
#   define SYSTEM_FAMILY SYSTEM_FAMILY_WINDOWS

#   if defined(WINAPI_FAMILY) && (WINAPI_FAMILY == WINAPI_FAMILY_DESKTOP_APP)
#       include <shlobj.h>
#       include <lmaccess.h>
#       define SYSTEM_TYPE SYSTEM_TYPE_DESKTOP
#       define SYSTEM_OS SYSTEM_OS_WINDOWS
#   else
#       define SYSTEM_TYPE SYSTEM_TYPE_MOBILE
#       define SYSTEM_OS SYSTEM_OS_WINDOWSPHONE
#   endif

#   ifdef _WIN64
#       define SYSTEM_ARCH SYSTEM_ARCH_X64
#   else
#       define SYSTEM_ARCH SYSTEM_ARCH_X86
#   endif

#elif defined(__APPLE__)
#   include <pwd.h>
#   include <sys/utsname.h>
#   include <sys/time.h>
#   include "TargetConditionals.h"
#   include <libkern/OSByteOrder.h>
#   define __BYTE_ORDER BYTE_ORDER
#   define __BIG_ENDIAN BIG_ENDIAN
#   define __LITTLE_ENDIAN LITTLE_ENDIAN
#   define SYSTEM_FAMILY SYSTEM_FAMILY_DARWIN
#   if TARGET_OS_IPHONE
#       define SYSTEM_TYPE SYSTEM_TYPE_MOBILE
#       define SYSTEM_OS SYSTEM_OS_IOS
#   else
#       define SYSTEM_TYPE SYSTEM_TYPE_DESKTOP
#       define SYSTEM_OS SYSTEM_OS_MACOSX
#   endif

#   if defined(__x86_64__) || defined(__ppc64__)
#       define SYSTEM_ARCH SYSTEM_ARCH_X64
#   else
#       define SYSTEM_ARCH SYSTEM_ARCH_X32
#   endif
#elif defined(__linux__)
#   include <pwd.h>
#   include <sys/utsname.h>
#   include <sys/time.h>
#   include <endian.h>
#   define SYSTEM_FAMILY SYSTEM_FAMILY_UNIX

#   if !defined(__ANDROID__)
#       define SYSTEM_TYPE SYSTEM_TYPE_DESKTOP
#       define SYSTEM_OS SYSTEM_OS_LINUX
#   else
#       define SYSTEM_TYPE SYSTEM_TYPE_MOBILE
#       define SYSTEM_OS SYSTEM_OS_ANDROID
#   endif

#   if defined(__x86_64__) || defined(__ppc64__)
#       define SYSTEM_ARCH SYSTEM_ARCH_X64
#   else
#       define SYSTEM_ARCH SYSTEM_ARCH_X32
#   endif
#endif







#define ENDIAN_LITTLE 0
#define ENDIAN_BIG 1
#define ENDIAN_UNKNOWN 2

#if (__BYTE_ORDER == __LITTLE_ENDIAN)
#    define ENDIAN ENDIAN_LITTLE
#elif((__BYTE_ORDER == __BIG_ENDIAN))
#    define ENDIAN ENDIAN_BIG
#else
#error "Invalid endian"
#endif










#define OS_FAMILY_WIN 0
#define OS_FAMILY_UNIX 1
#define OS_FAMILY_DARWIN 2

#ifdef WIN32
   #if defined(WINAPI_FAMILY) && (WINAPI_FAMILY == WINAPI_FAMILY_DESKTOP_APP)
        #define OS_TYPE_DESKTOP 1
   #else
        #define OS_TYPE_MOBILE 1
   #endif
#elif defined(__APPLE__)
    #if TARGET_OS_IPHONE || TARGET_IPHONE_SIMULATOR
        #define OS_TYPE_MOBILE 1
    #else
        #define OS_TYPE_DESKTOP 1
    #endif
#elif defined(__linux__)
    #if !defined(__ANDROID__)
        #define OS_TYPE_DESKTOP 1
    #else
        #define OS_TYPE_MOBILE 1
    #endif
#endif


#if defined(_WIN32) || defined( _WIN64)
#   ifdef _WIN64
#       define ARCHITECTURE "x64"
#   else
#       define ARCHITECTURE "x32"
#   endif
#else
#   if defined(__x86_64__) || defined(__ppc64__)
#       define ARCHITECTURE "x64"
#   else
#       define ARCHITECTURE "x32"
#   endif
#endif

#if defined(_WIN32) || defined(_WIN64)
#   define OS_FAMILY OS_FAMILY_WIN
#   ifdef OS_TYPE_DESKTOP
#       define PLATFORM "Windows"
#   else
#       define PLATFORM "Windows Phone"
#   endif
#elif __APPLE__
#   define OS_FAMILY OS_FAMILY_DARWIN
#   include "TargetConditionals.h"
#   if TARGET_OS_IPHONE || TARGET_IPHONE_SIMULATOR
#        define PLATFORM "IOS IPhone"
#   else
#        define PLATFORM "MAC OS X"
#   endif
#elif defined(ANDROID) || defined(__ANDROID__)
#   define OS_FAMILY OS_FAMILY_UNIX
#   define PLATFORM "Android"
#elif defined(__linux) || defined(_unix) || defined(__posix)
#   define OS_FAMILY OS_FAMILY_UNIX
#   define PLATFORM "Linux"
#endif

#if defined(_WIN32) || defined(_WIN64)
#   ifdef OS_TYPE_DESKTOP
#       define PLATFORM_SHORT "WIN"
#   else
#       define PLATFORM_SHORT "WPH"
#   endif
#elif __APPLE__
#   if TARGET_OS_IPHONE || TARGET_IPHONE_SIMULATOR
#        define PLATFORM_SHORT "IOS"
#   else
#        define PLATFORM_SHORT "MAC"
#   endif
#elif defined(ANDROID) || defined(__ANDROID__)
#   define PLATFORM_SHORT "AND"
#elif defined(__linux) || defined(_unix) || defined(__posix)
#   define PLATFORM_SHORT "LIN"
#endif

const char *SystemInfoArchitecture(void);
const char *SystemInfoPlatform(void);
const char *SystemInfoPlatformShort(void);
const char *SystemInfoUsername(void);


#endif
