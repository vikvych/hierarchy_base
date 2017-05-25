#ifndef HIERARCHY_LIST_EACH_H
#define HIERARCHY_LIST_EACH_H

#include "ListT.h"

typedef bool (ListEachCb)(ListNodeT *ListNode,
                                  void *Argument);

ListNodeT *ListEach(const ListT *List,
                    bool ForwardDirection,
                    ListEachCb *ApplyCallback,
                    void *Argument);
#endif
