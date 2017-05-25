#ifndef HIERARCHY_EON_STRING_SIZE_H
#define HIERARCHY_EON_STRING_SIZE_H

#include "../StringT.h"

ErrnoT StringCharSizeSimple(SizeT *Size,
                            ObjectT *Object,
                            char *Key);

ErrnoT StringByteSizeSimple(SizeT *Size,
                            ObjectT *Object,
                            char *Key);

ErrnoT StringCharSize(SizeT *Size,
                      ObjectT *Object,
                      char *Key[],
                      SizeT KeyCount);

ErrnoT StringByteSize(SizeT *Size,
                      ObjectT *Object,
                      char *Key[],
                      SizeT KeyCount);

#endif
