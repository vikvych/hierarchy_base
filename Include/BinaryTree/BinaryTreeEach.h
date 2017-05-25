#ifndef HIERARCHY_BINARY_TREE_EACH_H
#define HIERARCHY_BINARY_TREE_EACH_H

#include "../Error/ErrorLib.h"
#include "../Memory/MemoryLib.h"
#include "../MemoryBlock/MemoryBlockLib.h"

#include "BinaryTreeT.h"
#include "BinaryTreeLevelGet.h"

typedef bool (BinaryTreeEachCb)(BinaryTreeT *Tree,
                                BinaryNodeT *Node,
                                MemoryBlockT *Key,
                                void *Argument);

BinaryNodeT *BinaryTreeEachStepBack(BinaryNodeT *CurrentNode,
                                    ByteT *KeyBuffer,
                                    SizeT *KeySize);

BinaryNodeT *BinaryTreeEach(BinaryTreeT *Tree,
                           BinaryTreeEachCb *EachCb,
                           void *Argument);

BinaryNodeT *BinaryTreeEachInner(BinaryTreeT *Tree,
                                 ByteT *KeyBuffer,
                                 SizeT *KeySize,
                                 BinaryTreeEachCb *EachCb,
                                 void *Argument);

#endif
