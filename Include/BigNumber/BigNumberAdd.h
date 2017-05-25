#ifndef HIERARCHY_BIG_NUMBER_ADD_H
#define HIERARCHY_BIG_NUMBER_ADD_H

#include "BigNumberT.h"

ByteT BigNumberAdd(BigNumberT *NumberResult,
                   BigNumberT *Number1,
                   BigNumberT *Number2);

void BigNumberAddMod(BigNumberT *NumberResult,
                     BigNumberT *Number1,
                     BigNumberT *Number2,
                     BigNumberT *Mod);

#endif
