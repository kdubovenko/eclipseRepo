//
// File: crossoverFilter.h
//
// MATLAB Coder version            : 3.1
// C/C++ source code generated on  : 13-May-2020 13:38:55
//
#ifndef CROSSOVERFILTER_H
#define CROSSOVERFILTER_H

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
extern void crossoverFilter_resetImpl(crossoverFilter *obj);
extern void crossoverFilter_stepImpl(crossoverFilter *obj, const double x[64],
  double varargout_1[64], double varargout_2[64]);

#endif

//
// File trailer for crossoverFilter.h
//
// [EOF]
//
