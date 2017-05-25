#ifndef HIERARCHY_EON_OBJECT_DEBUG_H
#define HIERARCHY_EON_OBJECT_DEBUG_H

#include "../EON.h"
#include "../NumberT.h"

void ObjectDebugInner(ObjectT *Object, SizeT Level);
void ObjectDebug(const char *Prefix, ObjectT *Object);

#endif
