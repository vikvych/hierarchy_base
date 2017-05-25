#ifndef HIERARCHY_BINARY_TREE_SET_H
#define HIERARCHY_BINARY_TREE_SET_H

#include "../Error/ErrorLib.h"
#include "../Memory/MemoryLib.h"
#include "../MemoryBlock/MemoryBlockLib.h"

#include "BinaryTreeT.h"
#include "BinaryTreeGet.h"
#include "BinaryTreeLevelSet.h"

ErrnoT BinaryTreeSet(BinaryTreeT *Tree, MemoryBlockT *Key, void *Value);

#endif
