#ifndef HIERARCHY_EON_ABSTRACT_CLONE_H
#define HIERARCHY_EON_ABSTRACT_CLONE_H

#include "../Undefined/UndefinedClone.h"
#include "../Null/NullClone.h"
#include "../Boolean/BooleanClone.h"
#include "../Number/NumberClone.h"
#include "../String/StringClone.h"
#include "../ByteString/ByteStringClone.h"
#include "../Array/ArrayClone.h"
#include "../Object/ObjectClone.h"

AbstractT *AbstractClone(AbstractT *AbstractOld);

#endif
