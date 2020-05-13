//
// File: mod.cpp
//
// MATLAB Coder version            : 3.1
// C/C++ source code generated on  : 13-May-2020 13:38:55
//

// Include Files
#include "rt_nonfinite.h"
#include "PsychoBass.h"
#include "mod.h"
#include <stdio.h>

// Function Definitions

//
// Arguments    : double x
// Return Type  : double
//
double b_mod(double x)
{
  return x - floor(x / 2.0) * 2.0;
}

//
// File trailer for mod.cpp
//
// [EOF]
//
