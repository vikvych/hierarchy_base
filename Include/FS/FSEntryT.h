#ifndef HIERARCHY_FS_ENTRY_T_H
#define HIERARCHY_FS_ENTRY_T_H

#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <errno.h>

#include "../System/SystemLib.h"

#ifdef __APPLE__
        #include <sys/uio.h>
#else
#   if SYSTEM_OS == SYSTEM_OS_LINUX
        #include <sys/io.h>
#   else
        //#include <io.h>
#   endif
#endif

#include <sys/stat.h>
#ifdef WIN32
#include <direct.h>
#include <WinSock2.h>

#ifndef S_ISDIR
#define S_ISDIR(Mode)  (((Mode) & S_IFMT) == S_IFDIR)
#endif

#ifndef S_ISREG
#define S_ISREG(Mode)  (((Mode) & S_IFMT) == S_IFREG)
#endif

#else
#include <unistd.h>
#endif

#include "../Error/ErrorLib.h"
#include "../Memory/MemoryLib.h"
#include "../List/ListLib.h"

typedef struct {
    char *Name;
    char *RelativeName;
    char *AbsoluteName;
    ListNodeT Node;
} FSEntryT;

void FSEntryDestroy(void *FSEntryV);
FSEntryT *FSEntryInit(char *Dir, char *Name);
void FSEntryDebug(char *Prefix, FSEntryT *FSEntry);
void FSEntryListDebug(char *Prefix, ListT *FSEntryList);

#endif
