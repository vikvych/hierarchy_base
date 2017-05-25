#ifndef HIERARCHY_EON_OBJECT_EACH_H
#define HIERARCHY_EON_OBJECT_EACH_H

#include "../ObjectT.h"

typedef bool (ObjectEachCb)(ObjectT *Object,
                            char *Key,
                            void *Argument);

ErrnoT ObjectEach(ObjectT *Object,
                  ObjectEachCb *EachCb,
                  void *Argument);

#endif
