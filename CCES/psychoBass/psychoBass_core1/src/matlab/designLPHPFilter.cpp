//
// File: designLPHPFilter.cpp
//
// MATLAB Coder version            : 3.1
// C/C++ source code generated on  : 13-May-2020 13:38:55
//

// Include Files
#include "rt_nonfinite.h"
#include "PsychoBass.h"
#include "designLPHPFilter.h"
#include "designParamEQ.h"
#include "PsychoBass_rtwutil.h"
#include <stdio.h>

// Type Definitions
#ifndef struct_emxArray_real_T_4
#define struct_emxArray_real_T_4

struct emxArray_real_T_4
{
  double data[4];
  int size[1];
};

#endif                                 //struct_emxArray_real_T_4

#ifndef struct_sZzyh3NKmXdiXyIVDlIDX3C
#define struct_sZzyh3NKmXdiXyIVDlIDX3C

struct sZzyh3NKmXdiXyIVDlIDX3C
{
  emxArray_real_T_4 f1;
};

#endif                                 //struct_sZzyh3NKmXdiXyIVDlIDX3C

typedef sZzyh3NKmXdiXyIVDlIDX3C cell_wrap_11;

// Function Declarations
static void c_blt(const double Ba_data[], const int Ba_size[2], const double
                  Aa_data[], const int Aa_size[2], double B_data[], int B_size[2],
                  double A_data[], int A_size[2]);
static void c_hpeq(double N, double BW, double B_data[], int B_size[2], double
                   A_data[], int A_size[2]);
static void d_blt(const double Ba_data[], const int Ba_size[2], const double
                  Aa_data[], const int Aa_size[2], double B_data[], int B_size[2],
                  double A_data[], int A_size[2]);
static void d_hpeq(double N, double BW, double B_data[], int B_size[2], double
                   A_data[], int A_size[2]);

// Function Definitions

//
// Arguments    : const double Ba_data[]
//                const int Ba_size[2]
//                const double Aa_data[]
//                const int Aa_size[2]
//                double B_data[]
//                int B_size[2]
//                double A_data[]
//                int A_size[2]
// Return Type  : void
//
static void c_blt(const double Ba_data[], const int Ba_size[2], const double
                  Aa_data[], const int Aa_size[2], double B_data[], int B_size[2],
                  double A_data[], int A_size[2])
{
  int nx;
  int idx;
  int Bhat_size_idx_0;
  int Ahat_size_idx_0;
  double Bhat_data[12];
  double Ahat_data[12];
  double B2_data[4];
  double A2_data[4];
  boolean_T x_data[5];
  int ii_data[5];
  int ii_size_idx_0;
  int ii;
  boolean_T exitg2;
  boolean_T guard2 = false;
  int i1idx_data[4];
  double D;
  boolean_T exitg1;
  boolean_T guard1 = false;
  B_size[0] = Ba_size[0];
  B_size[1] = 5;
  nx = Ba_size[0] * 5;
  for (idx = 0; idx < nx; idx++) {
    B_data[idx] = 0.0;
  }

  A_size[0] = Ba_size[0];
  A_size[1] = 5;
  nx = Ba_size[0] * 5;
  for (idx = 0; idx < nx; idx++) {
    A_data[idx] = 0.0;
  }

  Bhat_size_idx_0 = Ba_size[0];
  nx = Ba_size[0] * 3;
  for (idx = 0; idx < nx; idx++) {
    Bhat_data[idx] = 0.0;
  }

  Ahat_size_idx_0 = Ba_size[0];
  nx = Ba_size[0] * 3;
  for (idx = 0; idx < nx; idx++) {
    Ahat_data[idx] = 0.0;
  }

  nx = Ba_size[0];
  for (idx = 0; idx < nx; idx++) {
    B2_data[idx] = Ba_data[idx + (Ba_size[0] << 1U)];
  }

  nx = Aa_size[0];
  for (idx = 0; idx < nx; idx++) {
    A2_data[idx] = Aa_data[idx + (Aa_size[0] << 1U)];
  }

  nx = Ba_size[0];
  for (idx = 0; idx < nx; idx++) {
    x_data[idx] = (((Ba_data[idx + Ba_size[0]] != 0.0) || (Aa_data[idx +
      Aa_size[0]] != 0.0)) && ((B2_data[idx] == 0.0) && (A2_data[idx] == 0.0)));
  }

  idx = 0;
  ii_size_idx_0 = Ba_size[0];
  ii = 1;
  exitg2 = false;
  while ((!exitg2) && (ii <= nx)) {
    guard2 = false;
    if (x_data[ii - 1]) {
      idx++;
      ii_data[idx - 1] = ii;
      if (idx >= nx) {
        exitg2 = true;
      } else {
        guard2 = true;
      }
    } else {
      guard2 = true;
    }

    if (guard2) {
      ii++;
    }
  }

  if (Ba_size[0] == 1) {
    if (idx == 0) {
      ii_size_idx_0 = 0;
    }
  } else if (1 > idx) {
    ii_size_idx_0 = 0;
  } else {
    ii_size_idx_0 = idx;
  }

  for (idx = 0; idx < ii_size_idx_0; idx++) {
    i1idx_data[idx] = ii_data[idx];
  }

  if (!(ii_size_idx_0 == 0)) {
    D = Aa_data[i1idx_data[0] - 1] + Aa_data[(i1idx_data[0] + Aa_size[0]) - 1];
    Bhat_data[i1idx_data[0] - 1] = (Ba_data[i1idx_data[0] - 1] + Ba_data
      [(i1idx_data[0] + Ba_size[0]) - 1]) / D;
    Bhat_data[(i1idx_data[0] + Ba_size[0]) - 1] = (Ba_data[i1idx_data[0] - 1] -
      Ba_data[(i1idx_data[0] + Ba_size[0]) - 1]) / D;
    Ahat_data[i1idx_data[0] - 1] = 1.0;
    Ahat_data[(i1idx_data[0] + Ba_size[0]) - 1] = (Aa_data[i1idx_data[0] - 1] -
      Aa_data[(i1idx_data[0] + Aa_size[0]) - 1]) / D;
  }

  nx = Ba_size[0];
  for (idx = 0; idx < nx; idx++) {
    x_data[idx] = ((B2_data[idx] != 0.0) || (A2_data[idx] != 0.0));
  }

  nx = Ba_size[0];
  idx = 0;
  ii_size_idx_0 = Ba_size[0];
  ii = 1;
  exitg1 = false;
  while ((!exitg1) && (ii <= nx)) {
    guard1 = false;
    if (x_data[ii - 1]) {
      idx++;
      ii_data[idx - 1] = ii;
      if (idx >= nx) {
        exitg1 = true;
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }

    if (guard1) {
      ii++;
    }
  }

  if (Ba_size[0] == 1) {
    if (idx == 0) {
      ii_size_idx_0 = 0;
    }
  } else if (1 > idx) {
    ii_size_idx_0 = 0;
  } else {
    ii_size_idx_0 = idx;
  }

  for (idx = 0; idx < ii_size_idx_0; idx++) {
    B2_data[idx] = ii_data[idx];
  }

  for (nx = 0; nx < ii_size_idx_0; nx++) {
    D = (Aa_data[(int)B2_data[nx] - 1] + Aa_data[((int)B2_data[nx] + Aa_size[0])
         - 1]) + Aa_data[((int)B2_data[nx] + (Aa_size[0] << 1U)) - 1];
    Bhat_data[(int)B2_data[nx] - 1] = ((Ba_data[(int)B2_data[nx] - 1] + Ba_data
      [((int)B2_data[nx] + Ba_size[0]) - 1]) + Ba_data[((int)B2_data[nx] +
      (Ba_size[0] << 1U)) - 1]) / D;
    Bhat_data[((int)B2_data[nx] + Bhat_size_idx_0) - 1] = 2.0 * (Ba_data[(int)
      B2_data[nx] - 1] - Ba_data[((int)B2_data[nx] + (Ba_size[0] << 1U)) - 1]) /
      D;
    Bhat_data[((int)B2_data[nx] + (Bhat_size_idx_0 << 1U)) - 1] = ((Ba_data[(int)
      B2_data[nx] - 1] - Ba_data[((int)B2_data[nx] + Ba_size[0]) - 1]) +
      Ba_data[((int)B2_data[nx] + (Ba_size[0] << 1U)) - 1]) / D;
    Ahat_data[(int)B2_data[nx] - 1] = 1.0;
    Ahat_data[((int)B2_data[nx] + Ahat_size_idx_0) - 1] = 2.0 * (Aa_data[(int)
      B2_data[nx] - 1] - Aa_data[((int)B2_data[nx] + (Aa_size[0] << 1U)) - 1]) /
      D;
    Ahat_data[((int)B2_data[nx] + (Ahat_size_idx_0 << 1U)) - 1] = ((Aa_data[(int)
      B2_data[nx] - 1] - Aa_data[((int)B2_data[nx] + Aa_size[0]) - 1]) +
      Aa_data[((int)B2_data[nx] + (Aa_size[0] << 1U)) - 1]) / D;
  }

  for (idx = 0; idx < 3; idx++) {
    for (nx = 0; nx < Bhat_size_idx_0; nx++) {
      B_data[nx + B_size[0] * idx] = Bhat_data[nx + Bhat_size_idx_0 * idx];
    }

    for (nx = 0; nx < Ahat_size_idx_0; nx++) {
      A_data[nx + A_size[0] * idx] = Ahat_data[nx + Ahat_size_idx_0 * idx];
    }
  }

  nx = Ba_size[0];
  for (idx = 0; idx < nx; idx++) {
    B2_data[idx] = -B_data[idx + B_size[0]];
  }

  nx = Ba_size[0];
  for (idx = 0; idx < nx; idx++) {
    B_data[idx + B_size[0]] = B2_data[idx];
  }

  nx = Ba_size[0];
  for (idx = 0; idx < nx; idx++) {
    B2_data[idx] = -A_data[idx + A_size[0]];
  }

  nx = Ba_size[0];
  for (idx = 0; idx < nx; idx++) {
    A_data[idx + A_size[0]] = B2_data[idx];
  }
}

//
// Arguments    : double N
//                double BW
//                double B_data[]
//                int B_size[2]
//                double A_data[]
//                int A_size[2]
// Return Type  : void
//
static void c_hpeq(double N, double BW, double B_data[], int B_size[2], double
                   A_data[], int A_size[2])
{
  double r;
  double L;
  double WB;
  int offset;
  int Ba_size[2];
  int nm1d2;
  int k;
  int Aa_size[2];
  double Ba_data[12];
  double Aa_data[12];
  int n;
  double ndbl;
  double apnd;
  double cdiff;
  double y_data[4];
  double i_data[4];
  double b_y_data[4];
  double si_data[4];
  int tmp_data[4];
  cell_wrap_11 reshapes[3];
  cell_wrap_11 b_reshapes[3];
  r = rt_remd_snf(N, 2.0);
  L = (N - r) / 2.0;
  WB = tan(3.1415926535897931 * BW / 2.0);
  offset = !(r == 0.0);
  Ba_size[0] = (int)(L + (double)offset);
  Ba_size[1] = 3;
  nm1d2 = (int)(L + (double)offset) * 3;
  for (k = 0; k < nm1d2; k++) {
    Ba_data[k] = 0.0;
  }

  Aa_size[0] = (int)(L + (double)offset);
  Aa_size[1] = 3;
  nm1d2 = (int)(L + (double)offset) * 3;
  for (k = 0; k < nm1d2; k++) {
    Aa_data[k] = 0.0;
  }

  if (r != 0.0) {
    Ba_data[0] = 0.0 * WB;
    Ba_data[Ba_size[0]] = 1.0;
    Ba_data[Ba_size[0] << 1U] = 0.0;
    Aa_data[0] = WB;
    Aa_data[Aa_size[0]] = 1.0;
    Aa_data[Aa_size[0] << 1U] = 0.0;
  }

  if (L > 0.0) {
    if (L < 1.0) {
      n = 0;
      r = 1.0;
      apnd = L;
    } else if (rtIsInf(L)) {
      n = 1;
      r = rtNaN;
      apnd = L;
    } else {
      r = 1.0;
      ndbl = floor((L - 1.0) + 0.5);
      apnd = 1.0 + ndbl;
      cdiff = (1.0 + ndbl) - L;
      if (fabs(cdiff) < 4.4408920985006262E-16 * L) {
        ndbl++;
        apnd = L;
      } else if (cdiff > 0.0) {
        apnd = 1.0 + (ndbl - 1.0);
      } else {
        ndbl++;
      }

      n = (int)ndbl;
    }

    if (n > 0) {
      y_data[0] = r;
      if (n > 1) {
        y_data[n - 1] = apnd;
        nm1d2 = (n - 1) / 2;
        k = 1;
        while (k <= nm1d2 - 1) {
          y_data[1] = r + 1.0;
          y_data[n - 2] = apnd - 1.0;
          k = 2;
        }

        if (nm1d2 << 1U == n - 1) {
          y_data[nm1d2] = (r + apnd) / 2.0;
        } else {
          y_data[nm1d2] = r + (double)nm1d2;
          y_data[nm1d2 + 1] = apnd - (double)nm1d2;
        }
      }
    }

    for (k = 0; k < n; k++) {
      i_data[k] = y_data[k];
    }

    for (k = 0; k < n; k++) {
      b_y_data[k] = 3.1415926535897931 * ((2.0 * i_data[k] - 1.0) / N) / 2.0;
    }

    for (k = 0; k < n; k++) {
      si_data[k] = b_y_data[k];
    }

    for (k = 0; k + 1 <= n; k++) {
      si_data[k] = sin(si_data[k]);
    }

    for (k = 0; k < n; k++) {
      tmp_data[k] = (int)((double)offset + i_data[k]) - 1;
    }

    r = 0.0 * (WB * WB);
    nm1d2 = (int)L;
    for (k = 0; k < nm1d2; k++) {
      reshapes[0].f1.data[k] = r;
    }

    for (k = 0; k < n; k++) {
      reshapes[1].f1.data[k] = 0.0 * si_data[k] * WB;
    }

    nm1d2 = (int)L;
    for (k = 0; k < nm1d2; k++) {
      Ba_data[tmp_data[k]] = reshapes[0].f1.data[k];
    }

    for (k = 0; k < n; k++) {
      Ba_data[tmp_data[k] + Ba_size[0]] = reshapes[1].f1.data[k];
    }

    nm1d2 = (int)L;
    for (k = 0; k < nm1d2; k++) {
      Ba_data[tmp_data[k] + (Ba_size[0] << 1U)] = 1.0;
    }

    for (k = 0; k < n; k++) {
      tmp_data[k] = (int)((double)offset + i_data[k]) - 1;
    }

    r = WB * WB;
    nm1d2 = (int)L;
    for (k = 0; k < nm1d2; k++) {
      b_reshapes[0].f1.data[k] = r;
    }

    for (k = 0; k < n; k++) {
      b_reshapes[1].f1.data[k] = 2.0 * si_data[k] * WB;
    }

    nm1d2 = (int)L;
    for (k = 0; k < nm1d2; k++) {
      Aa_data[tmp_data[k]] = b_reshapes[0].f1.data[k];
    }

    for (k = 0; k < n; k++) {
      Aa_data[tmp_data[k] + Aa_size[0]] = b_reshapes[1].f1.data[k];
    }

    nm1d2 = (int)L;
    for (k = 0; k < nm1d2; k++) {
      Aa_data[tmp_data[k] + (Aa_size[0] << 1U)] = 1.0;
    }
  }

  c_blt(Ba_data, Ba_size, Aa_data, Aa_size, B_data, B_size, A_data, A_size);
}

//
// Arguments    : const double Ba_data[]
//                const int Ba_size[2]
//                const double Aa_data[]
//                const int Aa_size[2]
//                double B_data[]
//                int B_size[2]
//                double A_data[]
//                int A_size[2]
// Return Type  : void
//
static void d_blt(const double Ba_data[], const int Ba_size[2], const double
                  Aa_data[], const int Aa_size[2], double B_data[], int B_size[2],
                  double A_data[], int A_size[2])
{
  int nx;
  int idx;
  int Bhat_size_idx_0;
  int Ahat_size_idx_0;
  double Bhat_data[12];
  double Ahat_data[12];
  double B2_data[4];
  double A2_data[4];
  boolean_T x_data[5];
  int ii_data[5];
  int ii_size_idx_0;
  int ii;
  boolean_T exitg2;
  boolean_T guard2 = false;
  int i1idx_data[4];
  double D;
  boolean_T exitg1;
  boolean_T guard1 = false;
  B_size[0] = Ba_size[0];
  B_size[1] = 5;
  nx = Ba_size[0] * 5;
  for (idx = 0; idx < nx; idx++) {
    B_data[idx] = 0.0;
  }

  A_size[0] = Ba_size[0];
  A_size[1] = 5;
  nx = Ba_size[0] * 5;
  for (idx = 0; idx < nx; idx++) {
    A_data[idx] = 0.0;
  }

  Bhat_size_idx_0 = Ba_size[0];
  nx = Ba_size[0] * 3;
  for (idx = 0; idx < nx; idx++) {
    Bhat_data[idx] = 0.0;
  }

  Ahat_size_idx_0 = Ba_size[0];
  nx = Ba_size[0] * 3;
  for (idx = 0; idx < nx; idx++) {
    Ahat_data[idx] = 0.0;
  }

  nx = Ba_size[0];
  for (idx = 0; idx < nx; idx++) {
    B2_data[idx] = Ba_data[idx + (Ba_size[0] << 1U)];
  }

  nx = Aa_size[0];
  for (idx = 0; idx < nx; idx++) {
    A2_data[idx] = Aa_data[idx + (Aa_size[0] << 1U)];
  }

  nx = Ba_size[0];
  for (idx = 0; idx < nx; idx++) {
    x_data[idx] = (((Ba_data[idx + Ba_size[0]] != 0.0) || (Aa_data[idx +
      Aa_size[0]] != 0.0)) && ((B2_data[idx] == 0.0) && (A2_data[idx] == 0.0)));
  }

  idx = 0;
  ii_size_idx_0 = Ba_size[0];
  ii = 1;
  exitg2 = false;
  while ((!exitg2) && (ii <= nx)) {
    guard2 = false;
    if (x_data[ii - 1]) {
      idx++;
      ii_data[idx - 1] = ii;
      if (idx >= nx) {
        exitg2 = true;
      } else {
        guard2 = true;
      }
    } else {
      guard2 = true;
    }

    if (guard2) {
      ii++;
    }
  }

  if (Ba_size[0] == 1) {
    if (idx == 0) {
      ii_size_idx_0 = 0;
    }
  } else if (1 > idx) {
    ii_size_idx_0 = 0;
  } else {
    ii_size_idx_0 = idx;
  }

  for (idx = 0; idx < ii_size_idx_0; idx++) {
    i1idx_data[idx] = ii_data[idx];
  }

  if (!(ii_size_idx_0 == 0)) {
    D = Aa_data[i1idx_data[0] - 1] + Aa_data[(i1idx_data[0] + Aa_size[0]) - 1];
    Bhat_data[i1idx_data[0] - 1] = (Ba_data[i1idx_data[0] - 1] + Ba_data
      [(i1idx_data[0] + Ba_size[0]) - 1]) / D;
    Bhat_data[(i1idx_data[0] + Ba_size[0]) - 1] = (Ba_data[i1idx_data[0] - 1] -
      Ba_data[(i1idx_data[0] + Ba_size[0]) - 1]) / D;
    Ahat_data[i1idx_data[0] - 1] = 1.0;
    Ahat_data[(i1idx_data[0] + Ba_size[0]) - 1] = (Aa_data[i1idx_data[0] - 1] -
      Aa_data[(i1idx_data[0] + Aa_size[0]) - 1]) / D;
  }

  nx = Ba_size[0];
  for (idx = 0; idx < nx; idx++) {
    x_data[idx] = ((B2_data[idx] != 0.0) || (A2_data[idx] != 0.0));
  }

  nx = Ba_size[0];
  idx = 0;
  ii_size_idx_0 = Ba_size[0];
  ii = 1;
  exitg1 = false;
  while ((!exitg1) && (ii <= nx)) {
    guard1 = false;
    if (x_data[ii - 1]) {
      idx++;
      ii_data[idx - 1] = ii;
      if (idx >= nx) {
        exitg1 = true;
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }

    if (guard1) {
      ii++;
    }
  }

  if (Ba_size[0] == 1) {
    if (idx == 0) {
      ii_size_idx_0 = 0;
    }
  } else if (1 > idx) {
    ii_size_idx_0 = 0;
  } else {
    ii_size_idx_0 = idx;
  }

  for (idx = 0; idx < ii_size_idx_0; idx++) {
    B2_data[idx] = ii_data[idx];
  }

  for (nx = 0; nx < ii_size_idx_0; nx++) {
    D = (Aa_data[(int)B2_data[nx] - 1] + Aa_data[((int)B2_data[nx] + Aa_size[0])
         - 1]) + Aa_data[((int)B2_data[nx] + (Aa_size[0] << 1U)) - 1];
    Bhat_data[(int)B2_data[nx] - 1] = ((Ba_data[(int)B2_data[nx] - 1] + Ba_data
      [((int)B2_data[nx] + Ba_size[0]) - 1]) + Ba_data[((int)B2_data[nx] +
      (Ba_size[0] << 1U)) - 1]) / D;
    Bhat_data[((int)B2_data[nx] + Bhat_size_idx_0) - 1] = 2.0 * (Ba_data[(int)
      B2_data[nx] - 1] - Ba_data[((int)B2_data[nx] + (Ba_size[0] << 1U)) - 1]) /
      D;
    Bhat_data[((int)B2_data[nx] + (Bhat_size_idx_0 << 1U)) - 1] = ((Ba_data[(int)
      B2_data[nx] - 1] - Ba_data[((int)B2_data[nx] + Ba_size[0]) - 1]) +
      Ba_data[((int)B2_data[nx] + (Ba_size[0] << 1U)) - 1]) / D;
    Ahat_data[(int)B2_data[nx] - 1] = 1.0;
    Ahat_data[((int)B2_data[nx] + Ahat_size_idx_0) - 1] = 2.0 * (Aa_data[(int)
      B2_data[nx] - 1] - Aa_data[((int)B2_data[nx] + (Aa_size[0] << 1U)) - 1]) /
      D;
    Ahat_data[((int)B2_data[nx] + (Ahat_size_idx_0 << 1U)) - 1] = ((Aa_data[(int)
      B2_data[nx] - 1] - Aa_data[((int)B2_data[nx] + Aa_size[0]) - 1]) +
      Aa_data[((int)B2_data[nx] + (Aa_size[0] << 1U)) - 1]) / D;
  }

  for (idx = 0; idx < 3; idx++) {
    for (nx = 0; nx < Bhat_size_idx_0; nx++) {
      B_data[nx + B_size[0] * idx] = Bhat_data[nx + Bhat_size_idx_0 * idx];
    }

    for (nx = 0; nx < Ahat_size_idx_0; nx++) {
      A_data[nx + A_size[0] * idx] = Ahat_data[nx + Ahat_size_idx_0 * idx];
    }
  }
}

//
// Arguments    : double N
//                double BW
//                double B_data[]
//                int B_size[2]
//                double A_data[]
//                int A_size[2]
// Return Type  : void
//
static void d_hpeq(double N, double BW, double B_data[], int B_size[2], double
                   A_data[], int A_size[2])
{
  double r;
  double L;
  double WB;
  int offset;
  int Ba_size[2];
  int nm1d2;
  int k;
  int Aa_size[2];
  double Ba_data[12];
  double Aa_data[12];
  int n;
  double ndbl;
  double apnd;
  double cdiff;
  double y_data[4];
  double i_data[4];
  double b_y_data[4];
  double si_data[4];
  int tmp_data[4];
  cell_wrap_11 reshapes[3];
  cell_wrap_11 b_reshapes[3];
  r = rt_remd_snf(N, 2.0);
  L = (N - r) / 2.0;
  WB = tan(3.1415926535897931 * BW / 2.0);
  offset = !(r == 0.0);
  Ba_size[0] = (int)(L + (double)offset);
  Ba_size[1] = 3;
  nm1d2 = (int)(L + (double)offset) * 3;
  for (k = 0; k < nm1d2; k++) {
    Ba_data[k] = 0.0;
  }

  Aa_size[0] = (int)(L + (double)offset);
  Aa_size[1] = 3;
  nm1d2 = (int)(L + (double)offset) * 3;
  for (k = 0; k < nm1d2; k++) {
    Aa_data[k] = 0.0;
  }

  if (r != 0.0) {
    Ba_data[0] = 0.0 * WB;
    Ba_data[Ba_size[0]] = 1.0;
    Ba_data[Ba_size[0] << 1U] = 0.0;
    Aa_data[0] = WB;
    Aa_data[Aa_size[0]] = 1.0;
    Aa_data[Aa_size[0] << 1U] = 0.0;
  }

  if (L > 0.0) {
    if (L < 1.0) {
      n = 0;
      r = 1.0;
      apnd = L;
    } else if (rtIsInf(L)) {
      n = 1;
      r = rtNaN;
      apnd = L;
    } else {
      r = 1.0;
      ndbl = floor((L - 1.0) + 0.5);
      apnd = 1.0 + ndbl;
      cdiff = (1.0 + ndbl) - L;
      if (fabs(cdiff) < 4.4408920985006262E-16 * L) {
        ndbl++;
        apnd = L;
      } else if (cdiff > 0.0) {
        apnd = 1.0 + (ndbl - 1.0);
      } else {
        ndbl++;
      }

      n = (int)ndbl;
    }

    if (n > 0) {
      y_data[0] = r;
      if (n > 1) {
        y_data[n - 1] = apnd;
        nm1d2 = (n - 1) / 2;
        k = 1;
        while (k <= nm1d2 - 1) {
          y_data[1] = r + 1.0;
          y_data[n - 2] = apnd - 1.0;
          k = 2;
        }

        if (nm1d2 << 1U == n - 1) {
          y_data[nm1d2] = (r + apnd) / 2.0;
        } else {
          y_data[nm1d2] = r + (double)nm1d2;
          y_data[nm1d2 + 1] = apnd - (double)nm1d2;
        }
      }
    }

    for (k = 0; k < n; k++) {
      i_data[k] = y_data[k];
    }

    for (k = 0; k < n; k++) {
      b_y_data[k] = 3.1415926535897931 * ((2.0 * i_data[k] - 1.0) / N) / 2.0;
    }

    for (k = 0; k < n; k++) {
      si_data[k] = b_y_data[k];
    }

    for (k = 0; k + 1 <= n; k++) {
      si_data[k] = sin(si_data[k]);
    }

    for (k = 0; k < n; k++) {
      tmp_data[k] = (int)((double)offset + i_data[k]) - 1;
    }

    r = 0.0 * (WB * WB);
    nm1d2 = (int)L;
    for (k = 0; k < nm1d2; k++) {
      reshapes[0].f1.data[k] = r;
    }

    for (k = 0; k < n; k++) {
      reshapes[1].f1.data[k] = 0.0 * si_data[k] * WB;
    }

    nm1d2 = (int)L;
    for (k = 0; k < nm1d2; k++) {
      Ba_data[tmp_data[k]] = reshapes[0].f1.data[k];
    }

    for (k = 0; k < n; k++) {
      Ba_data[tmp_data[k] + Ba_size[0]] = reshapes[1].f1.data[k];
    }

    nm1d2 = (int)L;
    for (k = 0; k < nm1d2; k++) {
      Ba_data[tmp_data[k] + (Ba_size[0] << 1U)] = 1.0;
    }

    for (k = 0; k < n; k++) {
      tmp_data[k] = (int)((double)offset + i_data[k]) - 1;
    }

    r = WB * WB;
    nm1d2 = (int)L;
    for (k = 0; k < nm1d2; k++) {
      b_reshapes[0].f1.data[k] = r;
    }

    for (k = 0; k < n; k++) {
      b_reshapes[1].f1.data[k] = 2.0 * si_data[k] * WB;
    }

    nm1d2 = (int)L;
    for (k = 0; k < nm1d2; k++) {
      Aa_data[tmp_data[k]] = b_reshapes[0].f1.data[k];
    }

    for (k = 0; k < n; k++) {
      Aa_data[tmp_data[k] + Aa_size[0]] = b_reshapes[1].f1.data[k];
    }

    nm1d2 = (int)L;
    for (k = 0; k < nm1d2; k++) {
      Aa_data[tmp_data[k] + (Aa_size[0] << 1U)] = 1.0;
    }
  }

  d_blt(Ba_data, Ba_size, Aa_data, Aa_size, B_data, B_size, A_data, A_size);
}

//
// Arguments    : double N
//                double BW
//                double B_data[]
//                int B_size[2]
//                double A_data[]
//                int A_size[2]
// Return Type  : void
//
void b_designLPHPFilter(double N, double BW, double B_data[], int B_size[2],
  double A_data[], int A_size[2])
{
  double No2;
  int loop_ub;
  int i19;
  double Bf_data[20];
  int Bf_size[2];
  double Af_data[20];
  int Af_size[2];
  int i20;
  No2 = N / 2.0;
  B_size[0] = 3;
  B_size[1] = (int)No2;
  loop_ub = 3 * (int)No2;
  for (i19 = 0; i19 < loop_ub; i19++) {
    B_data[i19] = 0.0;
  }

  loop_ub = (int)No2;
  for (i19 = 0; i19 < loop_ub; i19++) {
    B_data[3 * i19] = 1.0;
  }

  A_size[0] = 2;
  A_size[1] = (int)No2;
  loop_ub = (int)No2 << 1U;
  for (i19 = 0; i19 < loop_ub; i19++) {
    A_data[i19] = 0.0;
  }

  d_hpeq(No2, BW, Bf_data, Bf_size, Af_data, Af_size);
  loop_ub = Bf_size[0] - 1;
  for (i19 = 0; i19 <= loop_ub; i19++) {
    for (i20 = 0; i20 < 3; i20++) {
      B_data[i20 + 3 * i19] = Bf_data[i19 + Bf_size[0] * i20];
    }
  }

  loop_ub = Af_size[0] - 1;
  for (i19 = 0; i19 <= loop_ub; i19++) {
    for (i20 = 0; i20 < 2; i20++) {
      A_data[i20 + (i19 << 1U)] = Af_data[i19 + Af_size[0] * (1 + i20)];
    }
  }
}

//
// Arguments    : double N
//                double BW
//                double B_data[]
//                int B_size[2]
//                double A_data[]
//                int A_size[2]
// Return Type  : void
//
void designLPHPFilter(double N, double BW, double B_data[], int B_size[2],
                      double A_data[], int A_size[2])
{
  double No2;
  int loop_ub;
  int i17;
  double Bf_data[20];
  int Bf_size[2];
  double Af_data[20];
  int Af_size[2];
  int i18;
  No2 = N / 2.0;
  B_size[0] = 3;
  B_size[1] = (int)No2;
  loop_ub = 3 * (int)No2;
  for (i17 = 0; i17 < loop_ub; i17++) {
    B_data[i17] = 0.0;
  }

  loop_ub = (int)No2;
  for (i17 = 0; i17 < loop_ub; i17++) {
    B_data[3 * i17] = 1.0;
  }

  A_size[0] = 2;
  A_size[1] = (int)No2;
  loop_ub = (int)No2 << 1U;
  for (i17 = 0; i17 < loop_ub; i17++) {
    A_data[i17] = 0.0;
  }

  c_hpeq(No2, BW, Bf_data, Bf_size, Af_data, Af_size);
  loop_ub = Bf_size[0] - 1;
  for (i17 = 0; i17 <= loop_ub; i17++) {
    for (i18 = 0; i18 < 3; i18++) {
      B_data[i18 + 3 * i17] = Bf_data[i17 + Bf_size[0] * i18];
    }
  }

  loop_ub = Af_size[0] - 1;
  for (i17 = 0; i17 <= loop_ub; i17++) {
    for (i18 = 0; i18 < 2; i18++) {
      A_data[i18 + (i17 << 1U)] = Af_data[i17 + Af_size[0] * (1 + i18)];
    }
  }
}

//
// File trailer for designLPHPFilter.cpp
//
// [EOF]
//
