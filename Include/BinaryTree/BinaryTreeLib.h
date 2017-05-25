#ifndef HIERARCHY_BINARYTREE_LIB_H
#define HIERARCHY_BINARYTREE_LIB_H

#include "BinaryTreeT.h"
#include "BinaryTreeGet.h"
#include "BinaryTreeSet.h"
#include "BinaryTreeDelete.h"
#include "BinaryTreeDebug.h"
#include "BinaryTreeEach.h"
#include "BinaryTreeIsExists.h"
#include "BinaryTreeValue.h"
#include "BinaryTreeClear.h"
#include "BinaryTreeSize.h"

extern const struct BinaryTreeLibrary {
    void (*Destroy)(void *BinaryTreeV);
    BinaryTreeT *(*Init)();
    BinaryNodeT *(*Get)(BinaryTreeT *Tree, MemoryBlockT *Key);
    ErrnoT (*Set)(BinaryTreeT *Tree, MemoryBlockT *Key, void *Value);
    bool (*IsExists)(BinaryTreeT *Tree, MemoryBlockT *Key);
    void (*Delete)(BinaryTreeT *Tree, MemoryBlockT *Key);
    void (*Debug)(char *Prefix, BinaryTreeT *Tree);
    BinaryNodeT *(*Each)(BinaryTreeT *Tree,
                         BinaryTreeEachCb *EachCb,
                         void *Argument);
    void *(*Value)(BinaryTreeT *Tree, MemoryBlockT *Key);
    void (*Clear)(BinaryTreeT *Tree);
    SizeT (*Size)(BinaryTreeT *Tree);
} BinaryTreeLib;

#endif
