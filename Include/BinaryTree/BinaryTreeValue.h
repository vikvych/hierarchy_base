#ifndef HIERARCHY_BINARY_TREE_VALUE_H
#define HIERARCHY_BINARY_TREE_VALUE_H

#include "../Error/ErrorLib.h"
#include "../Memory/MemoryLib.h"
#include "../MemoryBlock/MemoryBlockLib.h"

#include "BinaryTreeT.h"
#include "BinaryTreeGet.h"

void *BinaryTreeValue(BinaryTreeT *Tree, MemoryBlockT *Key);

#endif
