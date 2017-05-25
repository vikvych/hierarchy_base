#ifndef HIERARCHY_BINARY_TREE_GET_H
#define HIERARCHY_BINARY_TREE_GET_H

#include "../Error/ErrorLib.h"
#include "../Memory/MemoryLib.h"
#include "../MemoryBlock/MemoryBlockLib.h"

#include "BinaryTreeT.h"
#include "BinaryTreeLevelGet.h"

BinaryNodeT *BinaryTreeGet(BinaryTreeT *Tree, MemoryBlockT *Key);

#endif
