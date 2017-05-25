#ifndef HIERARCHY_BINARY_TREE_ISEXISTS_H
#define HIERARCHY_BINARY_TREE_ISEXISTS_H

#include "../Error/ErrorLib.h"
#include "../Memory/MemoryLib.h"
#include "../MemoryBlock/MemoryBlockLib.h"

#include "BinaryTreeT.h"
#include "BinaryTreeGet.h"
#include "BinaryTreeEach.h"

bool BinaryTreeIsExists(BinaryTreeT *Tree, MemoryBlockT *Key);

#endif
