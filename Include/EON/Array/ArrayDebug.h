#ifndef HIERARCHY_EON_ARRAY_DEBUG_H
#define HIERARCHY_EON_ARRAY_DEBUG_H

#include "../EON.h"
#include "../NumberT.h"

void ArrayDebug(const char *Prefix, ArrayT *Array);
void ArrayDebugInner(ArrayT *Array, SizeT Level);

#endif
