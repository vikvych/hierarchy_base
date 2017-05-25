#ifndef HIERARCHY_BIGNUMBER_LIB_H
#define HIERARCHY_BIGNUMBER_LIB_H

#include "BigNumberT.h"
#include "BigNumberAdd.h"
#include "BigNumberClone.h"
#include "BigNumberCompare.h"
#include "BigNumberCopy.h"
#include "BigNumberDebug.h"
#include "BigNumberDiv.h"
#include "BigNumberMul.h"
#include "BigNumberRealloc.h"
#include "BigNumberReduce.h"
#include "BigNumberSet.h"
#include "BigNumberSub.h"
#include "BigNumberToMont.h"

extern const struct BigNumberLibrary {
    BigNumberT *(*Init)(SizeT Size);
    BigNumberT *(*InitFromInt)(QWordT Int);
    BigNumberT *(*InitFromHexString)(char *HexString);
    ErrnoT (*SetFromInt)(BigNumberT *BigNumber, QWordT Int);
    ErrnoT (*SetFromHexString)(BigNumberT *BigNumber, char *HexString);
    ErrnoT (*Realloc)(BigNumberT *BigNumber, SizeT Size);
    void (*Debug)(char *Prefix, BigNumberT *BigNumber);
} BigNumberLib;

#endif
