#ifndef HIERARCHY_LIST_SORT_H
#define HIERARCHY_LIST_SORT_H

#include "ListT.h"

typedef bool (ListSortCallbackT)(ListNodeT *CurrentListNode,
                                 ListNodeT *NextListNode,
                                 void *Argument);


void ListSort(ListT *List,
              ListSortCallbackT *SortCallback,
              void *Argument);

#endif
