#ifndef HIERARCHY_EON_H
#define HIERARCHY_EON_H

#include "../BinaryTree/BinaryTreeLib.h"
#include "../Memory/MemoryLib.h"
#include "../MemoryBuffer/MemoryBufferLib.h"
#include "../CString/CStringLib.h"
#include "../Debug/DebugLib.h"

typedef enum {
    EONInvalid = -1,
    EONUndefined = 0,
    EONNull,
    EONBoolean,
    EONNumber,
    EONString,
    EONByteString,
    EONArray,
    EONObject
} EONTypeT;

typedef struct {
    EONTypeT Type;
    void *Data;
} AbstractT;

typedef AbstractT UndefT;
typedef AbstractT NullT;
typedef AbstractT BoolT;

typedef struct {
    bool Dotted;
    union {
         int64_t Integer;
         double Double;
    } Number;
} NumberDataT;

typedef struct {
     EONTypeT Type;
     NumberDataT *Data;
} NumberT;

typedef AbstractT StringT;
typedef AbstractT ByteStringT;
typedef AbstractT ArrayT;
typedef AbstractT ObjectT;

ObjectT *EONObjectParse(MemoryBufferT *ThisBuffer);
ArrayT *EONArrayParse(MemoryBufferT *ThisBuffer);

#endif
