#ifndef HIERARCHY_MATH_MAX_H
#define HIERARCHY_MATH_MAX_H

#include <math.h>
#include <stdbool.h>
#include <stdint.h>

#include "../Memory/MemoryLib.h"

DWordT MathMaxUInt32(DWordT Number1, DWordT Number2);
SDWordT MathMaxInt32(SDWordT Number1, SDWordT Number2);
QWordT MathMaxUInt64(QWordT Number1, QWordT Number2);
SQWordT MathMaxInt64(SQWordT Number1, SQWordT Number2);
SizeT MathMaxSize(SizeT Number1, SizeT Number2);

#endif
