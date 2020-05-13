//
// File: filter.cpp
//
// MATLAB Coder version            : 3.1
// C/C++ source code generated on  : 13-May-2020 13:38:55
//

// Include Files
#include "rt_nonfinite.h"
#include "PsychoBass.h"
#include "filter.h"
#include <stdio.h>

// Function Definitions

//
// Arguments    : double b[3]
//                double a[3]
//                const double x[64]
//                const double zi[4]
//                double y[64]
//                double zf[4]
// Return Type  : void
//
void filter(double b[3], double a[3], const double x[64], const double zi[4],
            double y[64], double zf[4])
{
  double a1;
  int k;
  int c;
  int offset;
  double dbuffer[3];
  int j;
  int jp;
  a1 = a[0];
  if ((!((!rtIsInf(a[0])) && (!rtIsNaN(a[0])))) || (a[0] == 0.0) || (!(a[0] !=
        1.0))) {
  } else {
    for (k = 0; k < 3; k++) {
      b[k] /= a1;
    }

    for (k = 0; k < 2; k++) {
      a[k + 1] /= a1;
    }

    a[0] = 1.0;
  }

  for (c = 0; c < 2; c++) {
    offset = c << 5U;
    for (k = 0; k < 2; k++) {
      dbuffer[k + 1] = zi[k + (c << 1U)];
    }

    for (j = 0; j < 32; j++) {
      jp = offset + j;
      for (k = 0; k < 2; k++) {
        dbuffer[k] = dbuffer[k + 1];
      }

      dbuffer[2] = 0.0;
      for (k = 0; k < 3; k++) {
        dbuffer[k] += x[jp] * b[k];
      }

      for (k = 0; k < 2; k++) {
        dbuffer[k + 1] -= dbuffer[0] * a[k + 1];
      }

      y[jp] = dbuffer[0];
    }

    for (k = 0; k < 2; k++) {
      zf[k + (c << 1U)] = dbuffer[k + 1];
    }
  }
}

//
// File trailer for filter.cpp
//
// [EOF]
//
