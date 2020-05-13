//
// File: poly.cpp
//
// MATLAB Coder version            : 3.1
// C/C++ source code generated on  : 13-May-2020 13:38:55
//

// Include Files
#include "rt_nonfinite.h"
#include "PsychoBass.h"
#include "poly.h"
#include <stdio.h>

// Function Definitions

//
// Arguments    : const creal_T x[2]
//                creal_T c[3]
// Return Type  : void
//
void poly(const creal_T x[2], creal_T c[3])
{
  int j;
  double c_re;
  int k;
  c[0].re = 1.0;
  c[0].im = 0.0;
  for (j = 0; j < 2; j++) {
    c_re = c[j].re;
    c[j + 1].re = -x[j].re * c[j].re - -x[j].im * c[j].im;
    c[j + 1].im = -x[j].re * c[j].im + -x[j].im * c_re;
    k = j;
    while (k + 1 > 1) {
      c[1].re -= x[j].re * c[0].re - x[j].im * c[0].im;
      c[1].im -= x[j].re * c[0].im + x[j].im * c[0].re;
      k = 0;
    }
  }
}

//
// File trailer for poly.cpp
//
// [EOF]
//
