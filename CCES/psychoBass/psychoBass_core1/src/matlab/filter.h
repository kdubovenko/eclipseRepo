//
// File: filter.h
//
// MATLAB Coder version            : 3.1
// C/C++ source code generated on  : 13-May-2020 13:38:55
//
#ifndef FILTER_H
#define FILTER_H

// Include Files
#include <float.h>
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rt_defines.h"
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "PsychoBass_types.h"

// Function Declarations
extern void filter(double b[3], double a[3], const double x[64], const double
                   zi[4], double y[64], double zf[4]);

#endif

//
// File trailer for filter.h
//
// [EOF]
//
