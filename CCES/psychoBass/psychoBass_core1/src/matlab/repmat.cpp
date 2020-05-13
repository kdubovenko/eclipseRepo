//
// File: repmat.cpp
//
// MATLAB Coder version            : 3.1
// C/C++ source code generated on  : 13-May-2020 13:38:55
//

// Include Files
#include "rt_nonfinite.h"
#include "PsychoBass.h"
#include "repmat.h"
#include <stdio.h>

// Function Definitions

//
// Arguments    : double b[12]
// Return Type  : void
//
void b_repmat(double b[12])
{
  int jtilecol;
  int ibtile;
  int k;
  static const int a[3] = { 1, 0, 0 };

  for (jtilecol = 0; jtilecol < 4; jtilecol++) {
    ibtile = jtilecol * 3;
    for (k = 0; k < 3; k++) {
      b[ibtile + k] = a[k];
    }
  }
}

//
// Arguments    : const double a_data[]
//                const int a_size[2]
//                double b_data[]
//                int b_size[2]
// Return Type  : void
//
void repmat(const double a_data[], const int a_size[2], double b_data[], int
            b_size[2])
{
  int jcol;
  int ibmat;
  int itilerow;
  b_size[0] = 3;
  b_size[1] = a_size[1];
  if (!(a_size[1] == 0)) {
    for (jcol = 0; jcol + 1 <= a_size[1]; jcol++) {
      ibmat = jcol * 3;
      for (itilerow = 0; itilerow < 3; itilerow++) {
        b_data[ibmat + itilerow] = a_data[jcol];
      }
    }
  }
}

//
// File trailer for repmat.cpp
//
// [EOF]
//
