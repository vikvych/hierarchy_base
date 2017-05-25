#ifndef HIERARCHY_LIST_T_H
#define HIERARCHY_LIST_T_H

#include <stdbool.h>
#include "../Memory/MemoryLib.h"

typedef struct ListNode {
    struct ListNode *Prev;
    struct ListNode *Next;
    struct List *Parent;
    void *Data;
} ListNodeT;

typedef struct List {
    ListNodeT *First;
    ListNodeT *Last;
} ListT;

void ListInit(ListT *List);

#endif
