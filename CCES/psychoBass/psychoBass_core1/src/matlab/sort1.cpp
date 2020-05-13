//
// File: sort1.cpp
//
// MATLAB Coder version            : 3.1
// C/C++ source code generated on  : 13-May-2020 13:38:55
//

// Include Files
#include "rt_nonfinite.h"
#include "PsychoBass.h"
#include "sort1.h"
#include "relop.h"
#include <stdio.h>

// Function Definitions

//
// Arguments    : creal_T x_data[]
//                int x_size[1]
// Return Type  : void
//
void sort(creal_T x_data[], int x_size[1])
{
  int dim;
  int loop_ub;
  creal_T vwork_data[4];
  int vstride;
  int k;
  int j;
  int iwork_data[4];
  int idx_data[4];
  boolean_T p;
  creal_T xwork_data[4];
  int i2;
  int b_j;
  int pEnd;
  int b_p;
  int q;
  int qEnd;
  int kEnd;
  dim = 2;
  if (x_size[0] != 1) {
    dim = 1;
  }

  if (dim <= 1) {
    loop_ub = x_size[0];
  } else {
    loop_ub = 1;
  }

  vstride = 1;
  k = 1;
  while (k <= dim - 1) {
    vstride *= x_size[0];
    k = 2;
  }

  for (j = 0; j + 1 <= vstride; j++) {
    for (k = 0; k + 1 <= loop_ub; k++) {
      vwork_data[k] = x_data[j + k * vstride];
    }

    if (loop_ub == 0) {
    } else {
      for (dim = 0; dim < loop_ub; dim++) {
        idx_data[dim] = 0;
      }

      for (k = 1; k <= loop_ub - 1; k += 2) {
        if (relop(vwork_data[k - 1], vwork_data[k]) || (rtIsNaN(vwork_data[k].re)
             || rtIsNaN(vwork_data[k].im))) {
          p = true;
        } else {
          p = false;
        }

        if (p) {
          idx_data[k - 1] = k;
          idx_data[k] = k + 1;
        } else {
          idx_data[k - 1] = k + 1;
          idx_data[k] = k;
        }
      }

      if ((loop_ub & 1) != 0) {
        idx_data[loop_ub - 1] = loop_ub;
      }

      dim = 2;
      while (dim < loop_ub) {
        i2 = dim << 1U;
        b_j = 1;
        for (pEnd = 1 + dim; pEnd < loop_ub + 1; pEnd = qEnd + dim) {
          b_p = b_j;
          q = pEnd - 1;
          qEnd = b_j + i2;
          if (qEnd > loop_ub + 1) {
            qEnd = loop_ub + 1;
          }

          k = 0;
          kEnd = qEnd - b_j;
          while (k + 1 <= kEnd) {
            if (relop(vwork_data[idx_data[b_p - 1] - 1], vwork_data[idx_data[q]
                      - 1]) || (rtIsNaN(vwork_data[idx_data[q] - 1].re) ||
                                rtIsNaN(vwork_data[idx_data[q] - 1].im))) {
              p = true;
            } else {
              p = false;
            }

            if (p) {
              iwork_data[k] = idx_data[b_p - 1];
              b_p++;
              if (b_p == pEnd) {
                while (q + 1 < qEnd) {
                  k++;
                  iwork_data[k] = idx_data[q];
                  q++;
                }
              }
            } else {
              iwork_data[k] = idx_data[q];
              q++;
              if (q + 1 == qEnd) {
                while (b_p < pEnd) {
                  k++;
                  iwork_data[k] = idx_data[b_p - 1];
                  b_p++;
                }
              }
            }

            k++;
          }

          for (k = 0; k + 1 <= kEnd; k++) {
            idx_data[(b_j + k) - 1] = iwork_data[k];
          }

          b_j = qEnd;
        }

        dim = i2;
      }

      for (k = 0; k + 1 <= loop_ub; k++) {
        xwork_data[k] = vwork_data[k];
      }

      for (k = 0; k + 1 <= loop_ub; k++) {
        vwork_data[k] = xwork_data[idx_data[k] - 1];
      }
    }

    for (k = 0; k + 1 <= loop_ub; k++) {
      x_data[j + k * vstride] = vwork_data[k];
    }
  }
}

//
// File trailer for sort1.cpp
//
// [EOF]
//
