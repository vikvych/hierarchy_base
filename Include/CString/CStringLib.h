#ifndef HIERARCHY_STRING_LIB_H
#define HIERARCHY_STRING_LIB_H

#include "CStringT.h"
#include "../Error/ErrorLib.h"
#include "../Memory/MemoryLib.h"

extern const struct CStringLibrary {
    struct {
        ByteT (*HexToBin)(char CChar);
        SizeT (*UTF8ToUnicode)(DWordT *UnicodeString,
                               ByteT *CharacterUTF8);
        SizeT (*UTF8Size)(ByteT *CharacterUTF8);
    } CChar;

    struct {
        ErrnoT (*HexToBin)(ByteT *BinaryData,
                            SizeT BinaryDataLength,
                            const char *CString);

        void (*ZCopyMaxCharCount)(char *Dest,
                                  const char *Source,
                                  SizeT MaxCharCount);

        char *(*Dup)(const char *Source);
        char *(*DupSized)(const char *Source, SDWordT Length);
        ErrnoT (*Compare)(const char *String1,
                           const char *String2);

        ErrnoT (*CompareI)(const char *String1,
                            const char *String2);

        SizeT (*Size)(const char *CString);
        bool (*IsSet)(const char *CString);


        bool (*IsUTF8)(const char *CString);
        SizeT (*UTF8CharCount)(char *CString);
    } CString;
} CStringLib;

#endif
