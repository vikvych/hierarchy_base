#ifndef HIERARCHY_FS_DIR_LIST_H
#define HIERARCHY_FS_DIR_LIST_H

#include "FSEntryT.h"
#ifdef __APPLE__
#include <dirent.h>
#endif

#ifdef __linux__
#include <dirent.h>
#endif

ErrnoT FSDirList(ListT *Files, char *Dir);

#endif
