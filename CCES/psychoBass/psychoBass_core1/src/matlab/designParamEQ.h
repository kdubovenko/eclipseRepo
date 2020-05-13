//
// File: designParamEQ.h
//
// MATLAB Coder version            : 3.1
// C/C++ source code generated on  : 13-May-2020 13:38:55
//
#ifndef DESIGNPARAMEQ_H
#define DESIGNPARAMEQ_H

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
extern void b_designEachParamEQ(double N, double BW, double B_data[], int
  B_size[2], double A_data[], int A_size[2]);
extern void designEachParamEQ(double N, double BW, double B_data[], int B_size[2],
  double A_data[], int A_size[2]);

#endif

//
// File trailer for designParamEQ.h
//
// [EOF]
//
