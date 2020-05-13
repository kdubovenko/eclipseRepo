//
// File: all.cpp
//
// MATLAB Coder version            : 3.1
// C/C++ source code generated on  : 13-May-2020 13:38:55
//

// Include Files
#include "rt_nonfinite.h"
#include "PsychoBass.h"
#include "all.h"
#include <stdio.h>

// Function Definitions

//
// Arguments    : const boolean_T x_data[]
//                const int x_size[2]
//                boolean_T y[2]
// Return Type  : void
//
void all(const boolean_T x_data[], const int x_size[2], boolean_T y[2])
{
  int i2;
  int iy;
  int i;
  int i1;
  boolean_T exitg1;
  for (i2 = 0; i2 < 2; i2++) {
    y[i2] = true;
  }

  i2 = 0;
  iy = -1;
  for (i = 0; i < 2; i++) {
    i1 = i2 + 1;
    i2 += x_size[0];
    iy++;
    exitg1 = false;
    while ((!exitg1) && (i1 <= i2)) {
      if (!x_data[i1 - 1]) {
        y[iy] = false;
        exitg1 = true;
      } else {
        i1++;
      }
    }
  }
}

//
// File trailer for all.cpp
//
// [EOF]
//
