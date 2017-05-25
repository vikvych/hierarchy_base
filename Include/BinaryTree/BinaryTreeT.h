#ifndef HIERARCHY_BINARYTREE_H
#define HIERARCHY_BINARYTREE_H

#include "../Memory/MemoryLib.h"
#include "../Error/ErrorLib.h"
#include "../List/ListLib.h"

#define BINARY_TREE_MAX_KEY_SIZE 0xFFFF

typedef struct BinaryNode {
    ByteT Key;
    void *Value;

    struct BinaryNode *Next;
    struct BinaryNode *Prev;
    struct BinaryNode *Lower;
    struct BinaryNode *Higher;
} BinaryNodeT;

typedef struct BinaryTree {
    BinaryNodeT *Root;
} BinaryTreeT;

void BinaryNodeDestroy(void *BinaryNodeV);
BinaryNodeT *BinaryNodeInit(const ByteT Key,
                            BinaryNodeT *Next,
                            BinaryNodeT *Prev,
                            BinaryNodeT *Lower,
                            BinaryNodeT *Higher,
                            void *Value);
void BinaryTreeDestroy(void *BinaryTreeV);
BinaryTreeT *BinaryTreeInit();
BinaryTreeT *BinaryTreeFree(BinaryTreeT *BinaryTree);

#endif
