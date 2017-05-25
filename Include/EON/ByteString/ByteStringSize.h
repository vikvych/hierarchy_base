#ifndef HIERARCHY_EON_BINARYSTRING_SIZE_H
#define HIERARCHY_EON_BINARYSTRING_SIZE_H

#include "../ByteStringT.h"

ErrnoT ByteStringSizeSimple(SizeT *Size,
                            ObjectT *Object,
                            char *Key);

ErrnoT ByteStringSize(SizeT *Size,
                      ObjectT *Object,
                      char *Key[],
                      SizeT KeyCount);

#endif
