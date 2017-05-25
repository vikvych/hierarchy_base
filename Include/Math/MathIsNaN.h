#ifndef HIERARCHY_MATH_IS_NAN_H
#define HIERARCHY_MATH_IS_NAN_H

#include <math.h>
#include <stdbool.h>

#ifdef WIN32
#include <float.h>
#endif

bool MathIsNaN(double Number);

#endif
