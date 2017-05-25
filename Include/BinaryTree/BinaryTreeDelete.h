#ifndef HIERARCHY_BINARY_TREE_DELETE_H
#define HIERARCHY_BINARY_TREE_DELETE_H

#include "../Error/ErrorLib.h"
#include "../Memory/MemoryLib.h"
#include "../MemoryBlock/MemoryBlockLib.h"

#include "BinaryTreeT.h"
#include "BinaryTreeGet.h"
#include "BinaryTreeEach.h"

void BinaryTreeDelete(BinaryTreeT *Tree, MemoryBlockT *Key);

#endif
