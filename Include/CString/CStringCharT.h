#ifndef HIERARCHY_STRING_H
#define HIERARCHY_STRING_H

#include <stdint.h>
#include <stdbool.h>

#include "../Error/ErrorLib.h"
#include "../Memory/MemoryLib.h"

ByteT CCharHexToBin(char CChar);

SizeT UTF8CharToUnicodeChar(DWordT *UnicodeString,
                            ByteT *CharacterUTF8);

SizeT UTF8CharSize(ByteT *CharacterUTF8);

#endif
