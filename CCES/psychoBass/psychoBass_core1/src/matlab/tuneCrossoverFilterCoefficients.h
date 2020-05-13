//
// File: tuneCrossoverFilterCoefficients.h
//
// MATLAB Coder version            : 3.1
// C/C++ source code generated on  : 13-May-2020 13:38:55
//
#ifndef TUNECROSSOVERFILTERCOEFFICIENTS_H
#define TUNECROSSOVERFILTERCOEFFICIENTS_H

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
extern void tuneCrossoverFilterCoefficients(double freq, double order, double Fs,
  double BL[12], double AL[12], double BH[12], double AH[12], double *phaseMult);

#endif

//
// File trailer for tuneCrossoverFilterCoefficients.h
//
// [EOF]
//
