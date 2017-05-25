#ifndef HIERARCHY_BIG_NUMBER_MUL_H
#define HIERARCHY_BIG_NUMBER_MUL_H

#include "BigNumberT.h"

void bn_mon_muladd_dig(BigNumberT *NumberResult,
                       BigNumberT *Number1,
                       ByteT Number2,
                       BigNumberT *Mod);

void BigNumberMontMulMod(BigNumberT *NumberResult,
                         BigNumberT *Number1,
                         BigNumberT *Number2,
                         BigNumberT *Mod);

#endif
