#ifndef HIERARCHY_STRING_H
#define HIERARCHY_STRING_H

#include <stdint.h>
#include <stdbool.h>

#include "../Error/ErrorLib.h"
#include "../Memory/MemoryLib.h"

ByteT CCharHexToBin(char CChar);

ErrnoT CStringHexToBin(ByteT *BinaryData,
                        SizeT BinaryDataLength,
                        const char *CString);

void CStringZCopyMaxCharCount(char *Dest,
                              const char *Source,
                              SizeT MaxCharCount);

char *CStringDup(const char *Source);

ErrnoT CStringCompare(const char *String1,
                       const char *String2);

ErrnoT CStringCompareI(const char *String1,
                        const char *String2);

SizeT CStringLength(const char *CString);
bool CStringIsSet(const char *CString);

SizeT CStringFromInt(char *CharPtr,
                        QWordT IntNumber,
                        uint8_t Base,
                        bool UpperCase);

SizeT CStringFromDouble(char *CharPtr,
                           double DoubleNumber,
                           SizeT Precision);

SizeT UTF8CharToUnicodeChar(DWordT *UnicodeString,
                            ByteT *CharacterUTF8);

SizeT UTF8CharSize(ByteT *CharacterUTF8);

bool CStringIsUTF8(const char *CString);
SizeT CStringUTF8CharCount(char *CString);

char *CStringDupSized(const char *Source, SDWordT Length);

#endif
