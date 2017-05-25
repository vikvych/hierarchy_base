#ifndef HIERARCHY_BINARY_TREE_DEBUG_H
#define HIERARCHY_BINARY_TREE_DEBUG_H

#include "../Error/ErrorLib.h"
#include "../Memory/MemoryLib.h"
#include "../MemoryBlock/MemoryBlockLib.h"

#include "BinaryTreeT.h"
#include "BinaryTreeLevelGet.h"
#include "BinaryTreeEach.h"

void BinaryTreeDebug(char *Prefix, BinaryTreeT *Tree);

#endif
