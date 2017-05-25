#ifndef HIERARCHY_LIST_UPSERT_H
#define HIERARCHY_LIST_UPSERT_H

#include "ListT.h"

void ListUpsert(ListT *List,
                ListNodeT *SearchNode,
                ListNodeT *InsertNode,
                void *Data);

#endif
