//
// File: roots.cpp
//
// MATLAB Coder version            : 3.1
// C/C++ source code generated on  : 13-May-2020 13:38:55
//

// Include Files
#include "rt_nonfinite.h"
#include "PsychoBass.h"
#include "roots.h"
#include "eig.h"
#include <stdio.h>

// Function Definitions

//
// Arguments    : const double c[5]
//                creal_T r_data[]
//                int r_size[1]
// Return Type  : void
//
void b_roots(const double c[5], creal_T r_data[], int r_size[1])
{
  int k1;
  int k2;
  int companDim;
  double ctmp[5];
  boolean_T exitg1;
  int j;
  int a_size[2];
  boolean_T exitg2;
  creal_T a_data[16];
  creal_T eiga_data[4];
  int eiga_size[1];
  for (k1 = 0; k1 < 4; k1++) {
    r_data[k1].re = 0.0;
    r_data[k1].im = 0.0;
  }

  k1 = 1;
  while ((k1 <= 5) && (!(c[k1 - 1] != 0.0))) {
    k1++;
  }

  k2 = 5;
  while ((k2 >= k1) && (!(c[k2 - 1] != 0.0))) {
    k2--;
  }

  if (k1 < k2) {
    companDim = k2 - k1;
    exitg1 = false;
    while ((!exitg1) && (companDim > 0)) {
      j = 0;
      exitg2 = false;
      while ((!exitg2) && (j + 1 <= companDim)) {
        ctmp[j] = c[k1 + j] / c[k1 - 1];
        if (rtIsInf(fabs(ctmp[j]))) {
          exitg2 = true;
        } else {
          j++;
        }
      }

      if (j + 1 > companDim) {
        exitg1 = true;
      } else {
        k1++;
        companDim--;
      }
    }

    if (companDim < 1) {
      if (1 > 5 - k2) {
        r_size[0] = 0;
      } else {
        r_size[0] = 5 - k2;
      }
    } else {
      a_size[0] = companDim;
      a_size[1] = companDim;
      j = companDim * companDim;
      for (k1 = 0; k1 < j; k1++) {
        a_data[k1].re = 0.0;
        a_data[k1].im = 0.0;
      }

      for (k1 = 0; k1 + 1 < companDim; k1++) {
        a_data[companDim * k1].re = -ctmp[k1];
        a_data[companDim * k1].im = 0.0;
        a_data[(k1 + companDim * k1) + 1].re = 1.0;
        a_data[(k1 + companDim * k1) + 1].im = 0.0;
      }

      a_data[companDim * (companDim - 1)].re = -ctmp[companDim - 1];
      a_data[companDim * (companDim - 1)].im = 0.0;
      for (k1 = 1; k1 <= 5 - k2; k1++) {
        r_data[k1 - 1].re = 0.0;
        r_data[k1 - 1].im = 0.0;
      }

      eig(a_data, a_size, eiga_data, eiga_size);
      for (k1 = 1; k1 <= companDim; k1++) {
        r_data[(k1 - k2) + 4] = eiga_data[k1 - 1];
      }

      r_size[0] = (companDim - k2) + 5;
    }
  } else if (1 > 5 - k2) {
    r_size[0] = 0;
  } else {
    r_size[0] = 5 - k2;
  }
}

//
// Arguments    : const double c[3]
//                creal_T r_data[]
//                int r_size[1]
// Return Type  : void
//
void roots(const double c[3], creal_T r_data[], int r_size[1])
{
  int k1;
  int k2;
  int companDim;
  double ctmp[3];
  boolean_T exitg1;
  int j;
  int a_size[2];
  boolean_T exitg2;
  creal_T a_data[4];
  creal_T tmp_data[4];
  int tmp_size[1];
  creal_T eiga_data[2];
  for (k1 = 0; k1 < 2; k1++) {
    r_data[k1].re = 0.0;
    r_data[k1].im = 0.0;
  }

  k1 = 1;
  while ((k1 <= 3) && (!(c[k1 - 1] != 0.0))) {
    k1++;
  }

  k2 = 3;
  while ((k2 >= k1) && (!(c[k2 - 1] != 0.0))) {
    k2--;
  }

  if (k1 < k2) {
    companDim = k2 - k1;
    exitg1 = false;
    while ((!exitg1) && (companDim > 0)) {
      j = 0;
      exitg2 = false;
      while ((!exitg2) && (j + 1 <= companDim)) {
        ctmp[j] = c[k1 + j] / c[k1 - 1];
        if (rtIsInf(fabs(ctmp[j]))) {
          exitg2 = true;
        } else {
          j++;
        }
      }

      if (j + 1 > companDim) {
        exitg1 = true;
      } else {
        k1++;
        companDim--;
      }
    }

    if (companDim < 1) {
      r_size[0] = !(1 > 3 - k2);
    } else {
      a_size[0] = companDim;
      a_size[1] = companDim;
      j = companDim * companDim;
      for (k1 = 0; k1 < j; k1++) {
        a_data[k1].re = 0.0;
        a_data[k1].im = 0.0;
      }

      k1 = 1;
      while (k1 <= companDim - 1) {
        a_data[0].re = -ctmp[0];
        a_data[0].im = 0.0;
        a_data[1].re = 1.0;
        a_data[1].im = 0.0;
        k1 = 2;
      }

      a_data[companDim * (companDim - 1)].re = -ctmp[companDim - 1];
      a_data[companDim * (companDim - 1)].im = 0.0;
      k1 = 1;
      while (k1 <= 3 - k2) {
        r_data[0].re = 0.0;
        r_data[0].im = 0.0;
        k1 = 2;
      }

      eig(a_data, a_size, tmp_data, tmp_size);
      j = tmp_size[0];
      for (k1 = 0; k1 < j; k1++) {
        eiga_data[k1] = tmp_data[k1];
      }

      for (k1 = 1; k1 <= companDim; k1++) {
        r_data[(k1 - k2) + 2] = eiga_data[k1 - 1];
      }

      r_size[0] = (companDim - k2) + 3;
    }
  } else if (1 > 3 - k2) {
    r_size[0] = 0;
  } else {
    r_size[0] = 3 - k2;
  }
}

//
// File trailer for roots.cpp
//
// [EOF]
//
