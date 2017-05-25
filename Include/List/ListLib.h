#ifndef HIERARCHY_LIST_LIB_H
#define HIERARCHY_LIST_LIB_H

#include "ListT.h"
#include "ListAlloc.h"
#include "ListAppend.h"
#include "ListClear.h"
#include "ListDebug.h"
#include "ListEach.h"
#include "ListFirst.h"
#include "ListFlush.h"
#include "ListInsert.h"
#include "ListUpsert.h"
#include "ListIsEmpty.h"
#include "ListIsExists.h"
#include "ListLast.h"
#include "ListPrepend.h"
#include "ListRemove.h"
#include "ListSize.h"
#include "ListSort.h"
#include "ListValue.h"

extern const struct ListLibrary {
    void (*Init)(ListT *List);
    ListNodeT *(*NodeAlloc)();
    ListT *(*Alloc)();
    void (*Flush)(ListT *List);
    void (*Clear)(ListT *List);
    void (*Append)(ListT *List, ListNodeT *ListNode, void *Data);
    void (*Prepend)(ListT *List, ListNodeT *ListNode, void *Data);

    void (*Upsert)(ListT *List,
                   ListNodeT *SearchNode,
                   ListNodeT *InsertNode,
                   void *Data);

    void (*Insert)(ListT *List,
                   ListNodeT *SearchNode,
                   ListNodeT *InsertNode,
                   void *Data);

    void (*Sort)(ListT *List,
                 ListSortCallbackT *SortCallback,
                 void *Argument);

    ListNodeT *(*Each)(const ListT *List,
                                bool ForwardDirection,
                                ListEachCb *ApplyCallback,
                                void *Argument);

    ListNodeT *(*First)(const ListT *List);
    ListNodeT *(*Last)(const ListT *List);
    SizeT (*Size)(const ListT *List);
    bool (*IsEmpty)(const ListT *List);

    void *(*Value)(const ListNodeT *ListNode);
    bool (*IsExists)(const ListT *List, const ListNodeT *ListNode);
    void (*Remove)(ListNodeT *ListNode);
} ListLib;

#endif
