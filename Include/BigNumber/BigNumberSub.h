#ifndef HIERARCHY_BIG_NUMBER_SUB_H
#define HIERARCHY_BIG_NUMBER_SUB_H

#include "BigNumberT.h"

ByteT BigNumberSub(BigNumberT *NumberResult,
                   BigNumberT *Number1,
                   BigNumberT *Number2);

void BigNumberSubMod(BigNumberT *NumberResult,
                     BigNumberT *Number1,
                     BigNumberT *Number2,
                     BigNumberT *Mod);

#endif
