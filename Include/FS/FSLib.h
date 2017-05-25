#ifndef HIERARCHY_FS_LIB_H
#define HIERARCHY_FS_LIB_H

#include "FSDirAlloc.h"
#include "FSDirList.h"
#include "FSDirUnref.h"
#include "FSFileAlloc.h"
#include "FSFileAppendData.h"
#include "FSFileReadData.h"
#include "FSFileReadFile.h"
#include "FSFileRealloc.h"
#include "FSFileSize.h"
#include "FSFileUnref.h"
#include "FSFileWriteData.h"
#include "FSFileWriteFile.h"
#include "FSIsDir.h"
#include "FSIsExists.h"
#include "FSIsFile.h"
#include "FSEntryT.h"

extern const struct FSLibrary {
    ErrnoT (*IsExists)(char* Path);
    ErrnoT (*IsDir)(char* Path);
    ErrnoT (*IsFile)(char *Path);

    struct {
        void (*Destroy)(void *FSEntryV);
        FSEntryT *(*Init)(char *Dir, char *Name);
        void (*Debug)(char *Prefix, FSEntryT *FSEntry);
        void (*ListDebug)(char *Prefix, ListT *FSEntryList);
    } Entry;

    struct {
        ErrnoT (*Create)(char *Dir);
        ErrnoT (*List)(ListT *Files, char *Dir);
        ErrnoT (*Delete)(char *Dir);
    } Dir;

    struct {
        ErrnoT (*Create)(char *File, SQWordT Size);
        ErrnoT (*AppendData)(char *File, ByteT *Data, SQWordT Size);
        ByteT *(*ReadData)(char *File, QWordT Offset, SQWordT Length);
        ErrnoT (*ReadFile)(ByteT **Data, SQWordT *Size, char *File);
        ErrnoT (*Resize)(char *File, SQWordT Size);
        SQWordT (*Size)(char *File);
        ErrnoT (*Remove)(char *File);
        ErrnoT (*WriteData)(char *File, ByteT *Data, SQWordT Size, QWordT Offset);
        ErrnoT (*WriteFile)(char *File, ByteT *Data, SQWordT Size);
    } File;
} FSLib;

#endif

