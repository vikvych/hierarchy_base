#ifndef HIERARCHY_MATH_LIB_H
#define HIERARCHY_MATH_LIB_H

#include "MathIsInfinite.h"
#include "MathIsNaN.h"
#include "MathMax.h"
#include "MathMin.h"

extern const struct MathLibrary {
    bool (*IsInfinite)(double Number);
    bool (*IsNaN)(double Number);
    struct {
        DWordT (*DWord)(DWordT Number1, DWordT Number2);
        SDWordT (*SDWord)(SDWordT Number1, SDWordT Number2);
        QWordT (*QWord)(QWordT Number1, QWordT Number2);
        SQWordT (*SQWord)(SQWordT Number1, SQWordT Number2);
        SizeT (*Size)(SizeT Number1, SizeT Number2);
    } Max;

    struct {
        DWordT (*DWord)(DWordT Number1, DWordT Number2);
        QWordT (*QWord)(QWordT Number1, QWordT Number2);
        SizeT (*Size)(SizeT Number1, SizeT Number2);
    } Min;
} MathLib;


#endif
