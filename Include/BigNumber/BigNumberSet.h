#ifndef HIERARCHY_BIG_NUMBER_SET_H
#define HIERARCHY_BIG_NUMBER_SET_H

#include "BigNumberT.h"

ErrnoT BigNumberSetFromInt(BigNumberT *BigNumber, QWordT Int);
ErrnoT BigNumberSetFromHexString(BigNumberT *BigNumber, char *HexString);

#endif
