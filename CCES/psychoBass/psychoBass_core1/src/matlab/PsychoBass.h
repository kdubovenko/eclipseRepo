//
// File: PsychoBass.h
//
// MATLAB Coder version            : 3.1
// C/C++ source code generated on  : 13-May-2020 13:38:55
//
#ifndef PSYCHOBASS_H
#define PSYCHOBASS_H

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
extern void PsychoBass(PsychoBassStackData *SD, const double x[64], double
  Fcutoff, double G, double z[64]);
extern void bassEnhancer_not_empty_init(PsychoBassStackData *SD);

#endif

//
// File trailer for PsychoBass.h
//
// [EOF]
//
