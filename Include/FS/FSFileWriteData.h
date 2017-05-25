#ifndef HIERARCHY_FS_FILE_WRITEDATA_H
#define HIERARCHY_FS_FILE_WRITEDATA_H

#include "FSEntryT.h"

ErrnoT FSFileWriteData(char *File, ByteT *Data, SQWordT Size, QWordT Offset);

#endif
