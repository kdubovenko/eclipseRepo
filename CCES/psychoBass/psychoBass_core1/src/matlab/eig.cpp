//
// File: eig.cpp
//
// MATLAB Coder version            : 3.1
// C/C++ source code generated on  : 13-May-2020 13:38:55
//

// Include Files
#include "rt_nonfinite.h"
#include "PsychoBass.h"
#include "eig.h"
#include "xzgeev.h"
#include <stdio.h>

// Function Definitions

//
// Arguments    : const creal_T A_data[]
//                const int A_size[2]
//                creal_T V_data[]
//                int V_size[1]
// Return Type  : void
//
void eig(const creal_T A_data[], const int A_size[2], creal_T V_data[], int
         V_size[1])
{
  int info;
  creal_T beta1_data[4];
  int beta1_size[1];
  int i7;
  double V_data_re;
  double brm;
  double bim;
  double d;
  xzgeev(A_data, A_size, &info, V_data, V_size, beta1_data, beta1_size);
  info = V_size[0];
  for (i7 = 0; i7 < info; i7++) {
    V_data_re = V_data[i7].re;
    if (beta1_data[i7].im == 0.0) {
      if (V_data[i7].im == 0.0) {
        V_data[i7].re /= beta1_data[i7].re;
        V_data[i7].im = 0.0;
      } else if (V_data[i7].re == 0.0) {
        V_data[i7].re = 0.0;
        V_data[i7].im /= beta1_data[i7].re;
      } else {
        V_data[i7].re /= beta1_data[i7].re;
        V_data[i7].im /= beta1_data[i7].re;
      }
    } else if (beta1_data[i7].re == 0.0) {
      if (V_data[i7].re == 0.0) {
        V_data[i7].re = V_data[i7].im / beta1_data[i7].im;
        V_data[i7].im = 0.0;
      } else if (V_data[i7].im == 0.0) {
        V_data[i7].re = 0.0;
        V_data[i7].im = -(V_data_re / beta1_data[i7].im);
      } else {
        V_data[i7].re = V_data[i7].im / beta1_data[i7].im;
        V_data[i7].im = -(V_data_re / beta1_data[i7].im);
      }
    } else {
      brm = fabs(beta1_data[i7].re);
      bim = fabs(beta1_data[i7].im);
      if (brm > bim) {
        bim = beta1_data[i7].im / beta1_data[i7].re;
        d = beta1_data[i7].re + bim * beta1_data[i7].im;
        V_data[i7].re = (V_data[i7].re + bim * V_data[i7].im) / d;
        V_data[i7].im = (V_data[i7].im - bim * V_data_re) / d;
      } else if (bim == brm) {
        if (beta1_data[i7].re > 0.0) {
          bim = 0.5;
        } else {
          bim = -0.5;
        }

        if (beta1_data[i7].im > 0.0) {
          d = 0.5;
        } else {
          d = -0.5;
        }

        V_data[i7].re = (V_data[i7].re * bim + V_data[i7].im * d) / brm;
        V_data[i7].im = (V_data[i7].im * bim - V_data_re * d) / brm;
      } else {
        bim = beta1_data[i7].re / beta1_data[i7].im;
        d = beta1_data[i7].im + bim * beta1_data[i7].re;
        V_data[i7].re = (bim * V_data[i7].re + V_data[i7].im) / d;
        V_data[i7].im = (bim * V_data[i7].im - V_data_re) / d;
      }
    }
  }
}

//
// File trailer for eig.cpp
//
// [EOF]
//
