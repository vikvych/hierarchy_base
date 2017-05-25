#ifndef HIERARCHY_MATH_MIN_H
#define HIERARCHY_MATH_MIN_H

#include <math.h>
#include <stdbool.h>
#include <stdint.h>

#include "../Memory/MemoryLib.h"

DWordT MathMinUInt32(DWordT Number1, DWordT Number2);
QWordT MathMinUInt64(QWordT Number1, QWordT Number2);
SizeT MathMinSize(SizeT Number1, SizeT Number2);

#endif
