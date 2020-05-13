//
// File: designParamEQ.cpp
//
// MATLAB Coder version            : 3.1
// C/C++ source code generated on  : 13-May-2020 13:38:55
//

// Include Files
#include "rt_nonfinite.h"
#include "PsychoBass.h"
#include "designParamEQ.h"
#include "sqrt1.h"
#include "sort1.h"
#include "roots.h"
#include "poly.h"
#include "all.h"
#include "repmat.h"
#include "PsychoBass_rtwutil.h"
#include <stdio.h>

// Function Declarations
static void b_blt(const double Ba_data[], const int Ba_size[2], const double
                  Aa_data[], const int Aa_size[2], double B_data[], int B_size[2],
                  double A_data[], int A_size[2]);
static void b_hpeq(double N, double BW, double B_data[], int B_size[2], double
                   A_data[], int A_size[2]);
static void blt(const double Ba_data[], const int Ba_size[2], const double
                Aa_data[], const int Aa_size[2], double B_data[], int B_size[2],
                double A_data[], int A_size[2]);
static void hpeq(double N, double BW, double B_data[], int B_size[2], double
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
static void b_blt(const double Ba_data[], const int Ba_size[2], const double
                  Aa_data[], const int Aa_size[2], double B_data[], int B_size[2],
                  double A_data[], int A_size[2])
{
  int nx;
  int idx;
  int Bhat_size_idx_0;
  int Ahat_size_idx_0;
  double Bhat_data[15];
  double Ahat_data[15];
  double B2_data[5];
  double A2_data[5];
  boolean_T x_data[5];
  int ii_data[5];
  int ii_size_idx_0;
  int ii;
  boolean_T exitg2;
  boolean_T guard2 = false;
  int i1idx_data[5];
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
static void b_hpeq(double N, double BW, double B_data[], int B_size[2], double
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
  double Ba_data[15];
  double Aa_data[15];
  int n;
  double ndbl;
  double apnd;
  double cdiff;
  double y_data[4];
  double i_data[4];
  double b_y_data[4];
  double si_data[4];
  int tmp_data[4];
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
      Ba_data[tmp_data[k]] = r;
    }

    for (k = 0; k < n; k++) {
      Ba_data[tmp_data[k] + Ba_size[0]] = 0.0 * si_data[k] * WB;
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
      Aa_data[tmp_data[k]] = r;
    }

    for (k = 0; k < n; k++) {
      Aa_data[tmp_data[k] + Aa_size[0]] = 2.0 * si_data[k] * WB;
    }

    nm1d2 = (int)L;
    for (k = 0; k < nm1d2; k++) {
      Aa_data[tmp_data[k] + (Aa_size[0] << 1U)] = 1.0;
    }
  }

  b_blt(Ba_data, Ba_size, Aa_data, Aa_size, B_data, B_size, A_data, A_size);
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
static void blt(const double Ba_data[], const int Ba_size[2], const double
                Aa_data[], const int Aa_size[2], double B_data[], int B_size[2],
                double A_data[], int A_size[2])
{
  int nx;
  int idx;
  int Bhat_size_idx_0;
  int Ahat_size_idx_0;
  double Bhat_data[15];
  double Ahat_data[15];
  double B2_data[5];
  double A2_data[5];
  boolean_T x_data[5];
  int ii_data[5];
  int ii_size_idx_0;
  int ii;
  boolean_T exitg2;
  boolean_T guard2 = false;
  int i1idx_data[5];
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
static void hpeq(double N, double BW, double B_data[], int B_size[2], double
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
  double Ba_data[15];
  double Aa_data[15];
  int n;
  double ndbl;
  double apnd;
  double cdiff;
  double y_data[4];
  double i_data[4];
  double b_y_data[4];
  double si_data[4];
  int tmp_data[4];
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
      Ba_data[tmp_data[k]] = r;
    }

    for (k = 0; k < n; k++) {
      Ba_data[tmp_data[k] + Ba_size[0]] = 0.0 * si_data[k] * WB;
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
      Aa_data[tmp_data[k]] = r;
    }

    for (k = 0; k < n; k++) {
      Aa_data[tmp_data[k] + Aa_size[0]] = 2.0 * si_data[k] * WB;
    }

    nm1d2 = (int)L;
    for (k = 0; k < nm1d2; k++) {
      Aa_data[tmp_data[k] + (Aa_size[0] << 1U)] = 1.0;
    }
  }

  blt(Ba_data, Ba_size, Aa_data, Aa_size, B_data, B_size, A_data, A_size);
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
void b_designEachParamEQ(double N, double BW, double B_data[], int B_size[2],
  double A_data[], int A_size[2])
{
  double No2;
  int loop_ub;
  int i10;
  double Ar_data[25];
  int Ar_size[2];
  double Af_data[25];
  int Af_size[2];
  boolean_T b_Ar_data[10];
  int b_Ar_size[2];
  boolean_T x[2];
  int i11;
  boolean_T y;
  int k;
  boolean_T exitg4;
  boolean_T guard1 = false;
  int b_Af_size[2];
  int nextidx;
  int Br_size_idx_0;
  double Br_data[25];
  boolean_T exitg3;
  int i12;
  double G_data[24];
  int j;
  double b_Br_data[5];
  int Br_size[2];
  double tmp_data[15];
  int b_Br_size[2];
  boolean_T exitg2;
  boolean_T guard2 = false;
  int c_Ar_size[2];
  int b_k;
  boolean_T exitg1;
  creal_T r_data[4];
  int r_size[1];
  creal_T r2_data[4];
  int r2_size[1];
  double Br[3];
  creal_T p1[3];
  creal_T x_data[2];
  creal_T b_x[2];
  double p1_re;
  int x_size[1];
  creal_T b_x_data[4];
  creal_T p2[3];
  creal_T p3[3];
  creal_T p4[3];
  No2 = N / 2.0;
  B_size[0] = 3;
  B_size[1] = (int)No2;
  loop_ub = 3 * (int)No2;
  for (i10 = 0; i10 < loop_ub; i10++) {
    B_data[i10] = 0.0;
  }

  loop_ub = (int)No2;
  for (i10 = 0; i10 < loop_ub; i10++) {
    B_data[3 * i10] = 1.0;
  }

  A_size[0] = 2;
  A_size[1] = (int)No2;
  loop_ub = (int)No2 << 1U;
  for (i10 = 0; i10 < loop_ub; i10++) {
    A_data[i10] = 0.0;
  }

  b_hpeq(No2, BW, Ar_data, Ar_size, Af_data, Af_size);
  loop_ub = Ar_size[0];
  b_Ar_size[0] = Ar_size[0];
  b_Ar_size[1] = 2;
  for (i10 = 0; i10 < 2; i10++) {
    for (i11 = 0; i11 < loop_ub; i11++) {
      b_Ar_data[i11 + loop_ub * i10] = (Ar_data[i11 + Ar_size[0] * (3 + i10)] ==
        0.0);
    }
  }

  all(b_Ar_data, b_Ar_size, x);
  y = true;
  k = 0;
  exitg4 = false;
  while ((!exitg4) && (k < 2)) {
    if (!x[k]) {
      y = false;
      exitg4 = true;
    } else {
      k++;
    }
  }

  guard1 = false;
  if (y) {
    loop_ub = Af_size[0];
    b_Af_size[0] = Af_size[0];
    b_Af_size[1] = 2;
    for (i10 = 0; i10 < 2; i10++) {
      for (i11 = 0; i11 < loop_ub; i11++) {
        b_Ar_data[i11 + loop_ub * i10] = (Af_data[i11 + Af_size[0] * (3 + i10)] ==
          0.0);
      }
    }

    all(b_Ar_data, b_Af_size, x);
    y = true;
    k = 0;
    exitg3 = false;
    while ((!exitg3) && (k < 2)) {
      if (!x[k]) {
        y = false;
        exitg3 = true;
      } else {
        k++;
      }
    }

    if (y) {
      loop_ub = Ar_size[0] - 1;
      for (i10 = 0; i10 <= loop_ub; i10++) {
        for (i11 = 0; i11 < 3; i11++) {
          B_data[i11 + 3 * i10] = Ar_data[i10 + Ar_size[0] * i11];
        }
      }

      loop_ub = Af_size[0] - 1;
      for (i10 = 0; i10 <= loop_ub; i10++) {
        for (i11 = 0; i11 < 2; i11++) {
          A_data[i11 + (i10 << 1U)] = Af_data[i10 + Af_size[0] * (1 + i11)];
        }
      }
    } else {
      guard1 = true;
    }
  } else {
    guard1 = true;
  }

  if (guard1) {
    if (rt_remd_snf(No2, 2.0) != 0.0) {
      for (i10 = 0; i10 < 3; i10++) {
        B_data[i10] = Ar_data[Ar_size[0] * i10];
      }

      for (i10 = 0; i10 < 2; i10++) {
        A_data[i10] = Af_data[Af_size[0] * (1 + i10)];
      }

      nextidx = 2;
      if (2 > Ar_size[0]) {
        i10 = 0;
        i11 = 0;
      } else {
        i10 = 1;
        i11 = Ar_size[0];
      }

      Br_size_idx_0 = i11 - i10;
      for (i12 = 0; i12 < 5; i12++) {
        loop_ub = i11 - i10;
        for (j = 0; j < loop_ub; j++) {
          Br_data[j + Br_size_idx_0 * i12] = Ar_data[(i10 + j) + Ar_size[0] *
            i12];
        }
      }

      if (2 > Af_size[0]) {
        i10 = 0;
        i11 = 0;
      } else {
        i10 = 1;
        i11 = Af_size[0];
      }

      Ar_size[0] = i11 - i10;
      for (i12 = 0; i12 < 5; i12++) {
        loop_ub = i11 - i10;
        for (j = 0; j < loop_ub; j++) {
          Ar_data[j + Ar_size[0] * i12] = Af_data[(i10 + j) + Af_size[0] * i12];
        }
      }
    } else {
      nextidx = 1;
      Br_size_idx_0 = Ar_size[0];
      loop_ub = Ar_size[0] * Ar_size[1];
      for (i10 = 0; i10 < loop_ub; i10++) {
        Br_data[i10] = Ar_data[i10];
      }

      Ar_size[0] = Af_size[0];
      loop_ub = Af_size[0] * Af_size[1];
      for (i10 = 0; i10 < loop_ub; i10++) {
        Ar_data[i10] = Af_data[i10];
      }
    }

    loop_ub = 3 * (int)No2;
    for (i10 = 0; i10 < loop_ub; i10++) {
      G_data[i10] = 1.0;
    }

    if (nextidx > (int)No2) {
      i10 = 0;
      i11 = 1;
    } else {
      i10 = nextidx - 1;
      i11 = 2;
    }

    Br_size[0] = 1;
    Br_size[1] = Br_size_idx_0;
    for (i12 = 0; i12 < Br_size_idx_0; i12++) {
      b_Br_data[i12] = Br_data[i12];
    }

    repmat(b_Br_data, Br_size, tmp_data, Af_size);
    loop_ub = Af_size[1];
    for (i12 = 0; i12 < loop_ub; i12++) {
      for (j = 0; j < 3; j++) {
        G_data[j + 3 * (i10 + i11 * i12)] = tmp_data[j + Af_size[0] * i12];
      }
    }

    b_Br_size[0] = Br_size_idx_0;
    b_Br_size[1] = 2;
    for (i10 = 0; i10 < 2; i10++) {
      for (i11 = 0; i11 < Br_size_idx_0; i11++) {
        b_Ar_data[i11 + Br_size_idx_0 * i10] = (Br_data[i11 + Br_size_idx_0 * (1
          + (i10 << 1U))] == 0.0);
      }
    }

    all(b_Ar_data, b_Br_size, x);
    y = true;
    k = 0;
    exitg2 = false;
    while ((!exitg2) && (k < 2)) {
      if (!x[k]) {
        y = false;
        exitg2 = true;
      } else {
        k++;
      }
    }

    guard2 = false;
    if (y) {
      loop_ub = Ar_size[0];
      c_Ar_size[0] = Ar_size[0];
      c_Ar_size[1] = 2;
      for (i10 = 0; i10 < 2; i10++) {
        for (i11 = 0; i11 < loop_ub; i11++) {
          b_Ar_data[i11 + loop_ub * i10] = (Ar_data[i11 + Ar_size[0] * (1 + (i10
            << 1U))] == 0.0);
        }
      }

      all(b_Ar_data, c_Ar_size, x);
      y = true;
      k = 0;
      exitg1 = false;
      while ((!exitg1) && (k < 2)) {
        if (!x[k]) {
          y = false;
          exitg1 = true;
        } else {
          k++;
        }
      }

      if (y) {
        i10 = (int)(((No2 - 1.0) + (2.0 - (double)nextidx)) / 2.0);
        for (k = 0; k < i10; k++) {
          b_k = nextidx + (k << 1U);
          i11 = (int)ceil((double)b_k / 2.0);
          for (i12 = 0; i12 < 3; i12++) {
            Br[i12] = Br_data[(i11 + Br_size_idx_0 * (i12 << 1U)) - 1];
          }

          roots(Br, x_data, r2_size);
          r_size[0] = r2_size[0];
          loop_ub = r2_size[0];
          for (i11 = 0; i11 < loop_ub; i11++) {
            r_data[i11] = x_data[i11];
          }

          i11 = (int)ceil((double)b_k / 2.0);
          for (i12 = 0; i12 < 3; i12++) {
            Br[i12] = Ar_data[(i11 + Ar_size[0] * (i12 << 1U)) - 1];
          }

          roots(Br, x_data, r2_size);
          loop_ub = r2_size[0];
          for (i11 = 0; i11 < loop_ub; i11++) {
            r2_data[i11] = x_data[i11];
          }

          loop_ub = r_size[0];
          for (i11 = 0; i11 < loop_ub; i11++) {
            x_data[i11] = r_data[i11];
          }

          for (loop_ub = 1; loop_ub <= r_size[0]; loop_ub++) {
            b_sqrt(&x_data[loop_ub - 1]);
          }

          x_size[0] = r_size[0];
          loop_ub = r_size[0];
          for (i11 = 0; i11 < loop_ub; i11++) {
            b_x_data[i11] = x_data[i11];
          }

          sort(b_x_data, x_size);
          loop_ub = r2_size[0];
          for (i11 = 0; i11 < loop_ub; i11++) {
            x_data[i11] = r2_data[i11];
          }

          for (loop_ub = 1; loop_ub <= r2_size[0]; loop_ub++) {
            b_sqrt(&x_data[loop_ub - 1]);
          }

          r_size[0] = r2_size[0];
          loop_ub = r2_size[0];
          for (i11 = 0; i11 < loop_ub; i11++) {
            r_data[i11] = x_data[i11];
          }

          sort(r_data, r_size);
          b_x[0] = b_x_data[0];
          b_x[1].re = b_x_data[0].re;
          b_x[1].im = -b_x_data[0].im;
          p1[0].re = 1.0;
          p1[0].im = 0.0;
          for (j = 0; j < 2; j++) {
            p1_re = p1[j].re;
            p1[j + 1].re = -b_x[j].re * p1[j].re - -b_x[j].im * p1[j].im;
            p1[j + 1].im = -b_x[j].re * p1[j].im + -b_x[j].im * p1_re;
            loop_ub = j;
            while (loop_ub + 1 > 1) {
              p1[1].re -= b_x[j].re * p1[0].re - b_x[j].im * p1[0].im;
              p1[1].im -= b_x[j].re * p1[0].im + b_x[j].im * p1[0].re;
              loop_ub = 0;
            }
          }

          b_x[0].re = -b_x_data[1].re;
          b_x[0].im = -b_x_data[1].im;
          b_x[1].re = -b_x_data[1].re;
          b_x[1].im = -(-b_x_data[1].im);
          p2[0].re = 1.0;
          p2[0].im = 0.0;
          for (j = 0; j < 2; j++) {
            p1_re = p2[j].re;
            p2[j + 1].re = -b_x[j].re * p2[j].re - -b_x[j].im * p2[j].im;
            p2[j + 1].im = -b_x[j].re * p2[j].im + -b_x[j].im * p1_re;
            loop_ub = j;
            while (loop_ub + 1 > 1) {
              p2[1].re -= b_x[j].re * p2[0].re - b_x[j].im * p2[0].im;
              p2[1].im -= b_x[j].re * p2[0].im + b_x[j].im * p2[0].re;
              loop_ub = 0;
            }
          }

          b_x[0] = r_data[0];
          b_x[1].re = r_data[0].re;
          b_x[1].im = -r_data[0].im;
          p3[0].re = 1.0;
          p3[0].im = 0.0;
          for (j = 0; j < 2; j++) {
            p1_re = p3[j].re;
            p3[j + 1].re = -b_x[j].re * p3[j].re - -b_x[j].im * p3[j].im;
            p3[j + 1].im = -b_x[j].re * p3[j].im + -b_x[j].im * p1_re;
            loop_ub = j;
            while (loop_ub + 1 > 1) {
              p3[1].re -= b_x[j].re * p3[0].re - b_x[j].im * p3[0].im;
              p3[1].im -= b_x[j].re * p3[0].im + b_x[j].im * p3[0].re;
              loop_ub = 0;
            }
          }

          b_x[0].re = -r_data[1].re;
          b_x[0].im = -r_data[1].im;
          b_x[1].re = -r_data[1].re;
          b_x[1].im = -(-r_data[1].im);
          p4[0].re = 1.0;
          p4[0].im = 0.0;
          for (j = 0; j < 2; j++) {
            p1_re = p4[j].re;
            p4[j + 1].re = -b_x[j].re * p4[j].re - -b_x[j].im * p4[j].im;
            p4[j + 1].im = -b_x[j].re * p4[j].im + -b_x[j].im * p1_re;
            loop_ub = j;
            while (loop_ub + 1 > 1) {
              p4[1].re -= b_x[j].re * p4[0].re - b_x[j].im * p4[0].im;
              p4[1].im -= b_x[j].re * p4[0].im + b_x[j].im * p4[0].re;
              loop_ub = 0;
            }
          }

          for (i11 = 0; i11 < 3; i11++) {
            B_data[i11 + 3 * (b_k - 1)] = p1[i11].re;
          }

          for (i11 = 0; i11 < 2; i11++) {
            A_data[i11 + ((b_k - 1) << 1U)] = p3[1 + i11].re;
          }

          for (i11 = 0; i11 < 3; i11++) {
            B_data[i11 + 3 * b_k] = p2[i11].re;
          }

          for (i11 = 0; i11 < 2; i11++) {
            A_data[i11 + (b_k << 1U)] = p4[1 + i11].re;
          }
        }
      } else {
        guard2 = true;
      }
    } else {
      guard2 = true;
    }

    if (guard2) {
      i10 = (int)(((No2 - 1.0) + (2.0 - (double)nextidx)) / 2.0);
      for (k = 0; k < i10; k++) {
        b_k = nextidx + (k << 1U);
        i11 = (int)ceil((double)b_k / 2.0);
        for (i12 = 0; i12 < 5; i12++) {
          b_Br_data[i12] = Br_data[(i11 + Br_size_idx_0 * i12) - 1];
        }

        b_roots(b_Br_data, r_data, r_size);
        i11 = (int)ceil((double)b_k / 2.0);
        for (i12 = 0; i12 < 5; i12++) {
          b_Br_data[i12] = Ar_data[(i11 + Ar_size[0] * i12) - 1];
        }

        b_roots(b_Br_data, r2_data, r2_size);
        sort(r_data, r_size);
        sort(r2_data, r2_size);
        p1[0].re = 1.0;
        p1[0].im = 0.0;
        for (j = 0; j < 2; j++) {
          b_x[j] = r_data[j];
          p1_re = p1[j].re;
          p1[j + 1].re = -b_x[j].re * p1[j].re - -b_x[j].im * p1[j].im;
          p1[j + 1].im = -b_x[j].re * p1[j].im + -b_x[j].im * p1_re;
          loop_ub = j;
          while (loop_ub + 1 > 1) {
            p1[1].re -= b_x[j].re * p1[0].re - b_x[j].im * p1[0].im;
            p1[1].im -= b_x[j].re * p1[0].im + b_x[j].im * p1[0].re;
            loop_ub = 0;
          }
        }

        for (i11 = 0; i11 < 3; i11++) {
          B_data[i11 + 3 * (b_k - 1)] = p1[i11].re;
        }

        poly(*(creal_T (*)[2])&r2_data[0], p1);
        for (i11 = 0; i11 < 2; i11++) {
          A_data[i11 + ((b_k - 1) << 1U)] = p1[1 + i11].re;
        }

        poly(*(creal_T (*)[2])&r_data[2], p1);
        for (i11 = 0; i11 < 3; i11++) {
          B_data[i11 + 3 * b_k] = p1[i11].re;
        }

        poly(*(creal_T (*)[2])&r2_data[2], p1);
        for (i11 = 0; i11 < 2; i11++) {
          A_data[i11 + (b_k << 1U)] = p1[1 + i11].re;
        }
      }
    }

    B_size[0] = 3;
    loop_ub = 3 * (int)No2;
    for (i10 = 0; i10 < loop_ub; i10++) {
      B_data[i10] *= G_data[i10];
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
void designEachParamEQ(double N, double BW, double B_data[], int B_size[2],
  double A_data[], int A_size[2])
{
  double No2;
  int loop_ub;
  int i4;
  double Ar_data[25];
  int Ar_size[2];
  double Af_data[25];
  int Af_size[2];
  boolean_T b_Ar_data[10];
  int b_Ar_size[2];
  boolean_T x[2];
  int i5;
  boolean_T y;
  int k;
  boolean_T exitg4;
  boolean_T guard1 = false;
  int b_Af_size[2];
  int nextidx;
  int Br_size_idx_0;
  double Br_data[25];
  boolean_T exitg3;
  int i6;
  double G_data[24];
  int j;
  double b_Br_data[5];
  int Br_size[2];
  double tmp_data[15];
  int b_Br_size[2];
  boolean_T exitg2;
  boolean_T guard2 = false;
  int c_Ar_size[2];
  int b_k;
  boolean_T exitg1;
  creal_T r_data[4];
  int r_size[1];
  creal_T r2_data[4];
  int r2_size[1];
  double Br[3];
  creal_T p1[3];
  creal_T x_data[2];
  creal_T b_x[2];
  double p1_re;
  int x_size[1];
  creal_T b_x_data[4];
  creal_T p2[3];
  creal_T p3[3];
  creal_T p4[3];
  No2 = N / 2.0;
  B_size[0] = 3;
  B_size[1] = (int)No2;
  loop_ub = 3 * (int)No2;
  for (i4 = 0; i4 < loop_ub; i4++) {
    B_data[i4] = 0.0;
  }

  loop_ub = (int)No2;
  for (i4 = 0; i4 < loop_ub; i4++) {
    B_data[3 * i4] = 1.0;
  }

  A_size[0] = 2;
  A_size[1] = (int)No2;
  loop_ub = (int)No2 << 1U;
  for (i4 = 0; i4 < loop_ub; i4++) {
    A_data[i4] = 0.0;
  }

  hpeq(No2, BW, Ar_data, Ar_size, Af_data, Af_size);
  loop_ub = Ar_size[0];
  b_Ar_size[0] = Ar_size[0];
  b_Ar_size[1] = 2;
  for (i4 = 0; i4 < 2; i4++) {
    for (i5 = 0; i5 < loop_ub; i5++) {
      b_Ar_data[i5 + loop_ub * i4] = (Ar_data[i5 + Ar_size[0] * (3 + i4)] == 0.0);
    }
  }

  all(b_Ar_data, b_Ar_size, x);
  y = true;
  k = 0;
  exitg4 = false;
  while ((!exitg4) && (k < 2)) {
    if (!x[k]) {
      y = false;
      exitg4 = true;
    } else {
      k++;
    }
  }

  guard1 = false;
  if (y) {
    loop_ub = Af_size[0];
    b_Af_size[0] = Af_size[0];
    b_Af_size[1] = 2;
    for (i4 = 0; i4 < 2; i4++) {
      for (i5 = 0; i5 < loop_ub; i5++) {
        b_Ar_data[i5 + loop_ub * i4] = (Af_data[i5 + Af_size[0] * (3 + i4)] ==
          0.0);
      }
    }

    all(b_Ar_data, b_Af_size, x);
    y = true;
    k = 0;
    exitg3 = false;
    while ((!exitg3) && (k < 2)) {
      if (!x[k]) {
        y = false;
        exitg3 = true;
      } else {
        k++;
      }
    }

    if (y) {
      loop_ub = Ar_size[0] - 1;
      for (i4 = 0; i4 <= loop_ub; i4++) {
        for (i5 = 0; i5 < 3; i5++) {
          B_data[i5 + 3 * i4] = Ar_data[i4 + Ar_size[0] * i5];
        }
      }

      loop_ub = Af_size[0] - 1;
      for (i4 = 0; i4 <= loop_ub; i4++) {
        for (i5 = 0; i5 < 2; i5++) {
          A_data[i5 + (i4 << 1U)] = Af_data[i4 + Af_size[0] * (1 + i5)];
        }
      }
    } else {
      guard1 = true;
    }
  } else {
    guard1 = true;
  }

  if (guard1) {
    if (rt_remd_snf(No2, 2.0) != 0.0) {
      for (i4 = 0; i4 < 3; i4++) {
        B_data[i4] = Ar_data[Ar_size[0] * i4];
      }

      for (i4 = 0; i4 < 2; i4++) {
        A_data[i4] = Af_data[Af_size[0] * (1 + i4)];
      }

      nextidx = 2;
      if (2 > Ar_size[0]) {
        i4 = 0;
        i5 = 0;
      } else {
        i4 = 1;
        i5 = Ar_size[0];
      }

      Br_size_idx_0 = i5 - i4;
      for (i6 = 0; i6 < 5; i6++) {
        loop_ub = i5 - i4;
        for (j = 0; j < loop_ub; j++) {
          Br_data[j + Br_size_idx_0 * i6] = Ar_data[(i4 + j) + Ar_size[0] * i6];
        }
      }

      if (2 > Af_size[0]) {
        i4 = 0;
        i5 = 0;
      } else {
        i4 = 1;
        i5 = Af_size[0];
      }

      Ar_size[0] = i5 - i4;
      for (i6 = 0; i6 < 5; i6++) {
        loop_ub = i5 - i4;
        for (j = 0; j < loop_ub; j++) {
          Ar_data[j + Ar_size[0] * i6] = Af_data[(i4 + j) + Af_size[0] * i6];
        }
      }
    } else {
      nextidx = 1;
      Br_size_idx_0 = Ar_size[0];
      loop_ub = Ar_size[0] * Ar_size[1];
      for (i4 = 0; i4 < loop_ub; i4++) {
        Br_data[i4] = Ar_data[i4];
      }

      Ar_size[0] = Af_size[0];
      loop_ub = Af_size[0] * Af_size[1];
      for (i4 = 0; i4 < loop_ub; i4++) {
        Ar_data[i4] = Af_data[i4];
      }
    }

    loop_ub = 3 * (int)No2;
    for (i4 = 0; i4 < loop_ub; i4++) {
      G_data[i4] = 1.0;
    }

    if (nextidx > (int)No2) {
      i4 = 0;
      i5 = 1;
    } else {
      i4 = nextidx - 1;
      i5 = 2;
    }

    Br_size[0] = 1;
    Br_size[1] = Br_size_idx_0;
    for (i6 = 0; i6 < Br_size_idx_0; i6++) {
      b_Br_data[i6] = Br_data[i6];
    }

    repmat(b_Br_data, Br_size, tmp_data, Af_size);
    loop_ub = Af_size[1];
    for (i6 = 0; i6 < loop_ub; i6++) {
      for (j = 0; j < 3; j++) {
        G_data[j + 3 * (i4 + i5 * i6)] = tmp_data[j + Af_size[0] * i6];
      }
    }

    b_Br_size[0] = Br_size_idx_0;
    b_Br_size[1] = 2;
    for (i4 = 0; i4 < 2; i4++) {
      for (i5 = 0; i5 < Br_size_idx_0; i5++) {
        b_Ar_data[i5 + Br_size_idx_0 * i4] = (Br_data[i5 + Br_size_idx_0 * (1 +
          (i4 << 1U))] == 0.0);
      }
    }

    all(b_Ar_data, b_Br_size, x);
    y = true;
    k = 0;
    exitg2 = false;
    while ((!exitg2) && (k < 2)) {
      if (!x[k]) {
        y = false;
        exitg2 = true;
      } else {
        k++;
      }
    }

    guard2 = false;
    if (y) {
      loop_ub = Ar_size[0];
      c_Ar_size[0] = Ar_size[0];
      c_Ar_size[1] = 2;
      for (i4 = 0; i4 < 2; i4++) {
        for (i5 = 0; i5 < loop_ub; i5++) {
          b_Ar_data[i5 + loop_ub * i4] = (Ar_data[i5 + Ar_size[0] * (1 + (i4 <<
            1U))] == 0.0);
        }
      }

      all(b_Ar_data, c_Ar_size, x);
      y = true;
      k = 0;
      exitg1 = false;
      while ((!exitg1) && (k < 2)) {
        if (!x[k]) {
          y = false;
          exitg1 = true;
        } else {
          k++;
        }
      }

      if (y) {
        i4 = (int)(((No2 - 1.0) + (2.0 - (double)nextidx)) / 2.0);
        for (k = 0; k < i4; k++) {
          b_k = nextidx + (k << 1U);
          i5 = (int)ceil((double)b_k / 2.0);
          for (i6 = 0; i6 < 3; i6++) {
            Br[i6] = Br_data[(i5 + Br_size_idx_0 * (i6 << 1U)) - 1];
          }

          roots(Br, x_data, r2_size);
          r_size[0] = r2_size[0];
          loop_ub = r2_size[0];
          for (i5 = 0; i5 < loop_ub; i5++) {
            r_data[i5] = x_data[i5];
          }

          i5 = (int)ceil((double)b_k / 2.0);
          for (i6 = 0; i6 < 3; i6++) {
            Br[i6] = Ar_data[(i5 + Ar_size[0] * (i6 << 1U)) - 1];
          }

          roots(Br, x_data, r2_size);
          loop_ub = r2_size[0];
          for (i5 = 0; i5 < loop_ub; i5++) {
            r2_data[i5] = x_data[i5];
          }

          loop_ub = r_size[0];
          for (i5 = 0; i5 < loop_ub; i5++) {
            x_data[i5] = r_data[i5];
          }

          for (loop_ub = 1; loop_ub <= r_size[0]; loop_ub++) {
            b_sqrt(&x_data[loop_ub - 1]);
          }

          x_size[0] = r_size[0];
          loop_ub = r_size[0];
          for (i5 = 0; i5 < loop_ub; i5++) {
            b_x_data[i5] = x_data[i5];
          }

          sort(b_x_data, x_size);
          loop_ub = r2_size[0];
          for (i5 = 0; i5 < loop_ub; i5++) {
            x_data[i5] = r2_data[i5];
          }

          for (loop_ub = 1; loop_ub <= r2_size[0]; loop_ub++) {
            b_sqrt(&x_data[loop_ub - 1]);
          }

          r_size[0] = r2_size[0];
          loop_ub = r2_size[0];
          for (i5 = 0; i5 < loop_ub; i5++) {
            r_data[i5] = x_data[i5];
          }

          sort(r_data, r_size);
          b_x[0] = b_x_data[0];
          b_x[1].re = b_x_data[0].re;
          b_x[1].im = -b_x_data[0].im;
          p1[0].re = 1.0;
          p1[0].im = 0.0;
          for (j = 0; j < 2; j++) {
            p1_re = p1[j].re;
            p1[j + 1].re = -b_x[j].re * p1[j].re - -b_x[j].im * p1[j].im;
            p1[j + 1].im = -b_x[j].re * p1[j].im + -b_x[j].im * p1_re;
            loop_ub = j;
            while (loop_ub + 1 > 1) {
              p1[1].re -= b_x[j].re * p1[0].re - b_x[j].im * p1[0].im;
              p1[1].im -= b_x[j].re * p1[0].im + b_x[j].im * p1[0].re;
              loop_ub = 0;
            }
          }

          b_x[0].re = -b_x_data[1].re;
          b_x[0].im = -b_x_data[1].im;
          b_x[1].re = -b_x_data[1].re;
          b_x[1].im = -(-b_x_data[1].im);
          p2[0].re = 1.0;
          p2[0].im = 0.0;
          for (j = 0; j < 2; j++) {
            p1_re = p2[j].re;
            p2[j + 1].re = -b_x[j].re * p2[j].re - -b_x[j].im * p2[j].im;
            p2[j + 1].im = -b_x[j].re * p2[j].im + -b_x[j].im * p1_re;
            loop_ub = j;
            while (loop_ub + 1 > 1) {
              p2[1].re -= b_x[j].re * p2[0].re - b_x[j].im * p2[0].im;
              p2[1].im -= b_x[j].re * p2[0].im + b_x[j].im * p2[0].re;
              loop_ub = 0;
            }
          }

          b_x[0] = r_data[0];
          b_x[1].re = r_data[0].re;
          b_x[1].im = -r_data[0].im;
          p3[0].re = 1.0;
          p3[0].im = 0.0;
          for (j = 0; j < 2; j++) {
            p1_re = p3[j].re;
            p3[j + 1].re = -b_x[j].re * p3[j].re - -b_x[j].im * p3[j].im;
            p3[j + 1].im = -b_x[j].re * p3[j].im + -b_x[j].im * p1_re;
            loop_ub = j;
            while (loop_ub + 1 > 1) {
              p3[1].re -= b_x[j].re * p3[0].re - b_x[j].im * p3[0].im;
              p3[1].im -= b_x[j].re * p3[0].im + b_x[j].im * p3[0].re;
              loop_ub = 0;
            }
          }

          b_x[0].re = -r_data[1].re;
          b_x[0].im = -r_data[1].im;
          b_x[1].re = -r_data[1].re;
          b_x[1].im = -(-r_data[1].im);
          p4[0].re = 1.0;
          p4[0].im = 0.0;
          for (j = 0; j < 2; j++) {
            p1_re = p4[j].re;
            p4[j + 1].re = -b_x[j].re * p4[j].re - -b_x[j].im * p4[j].im;
            p4[j + 1].im = -b_x[j].re * p4[j].im + -b_x[j].im * p1_re;
            loop_ub = j;
            while (loop_ub + 1 > 1) {
              p4[1].re -= b_x[j].re * p4[0].re - b_x[j].im * p4[0].im;
              p4[1].im -= b_x[j].re * p4[0].im + b_x[j].im * p4[0].re;
              loop_ub = 0;
            }
          }

          for (i5 = 0; i5 < 3; i5++) {
            B_data[i5 + 3 * (b_k - 1)] = p1[i5].re;
          }

          for (i5 = 0; i5 < 2; i5++) {
            A_data[i5 + ((b_k - 1) << 1U)] = p3[1 + i5].re;
          }

          for (i5 = 0; i5 < 3; i5++) {
            B_data[i5 + 3 * b_k] = p2[i5].re;
          }

          for (i5 = 0; i5 < 2; i5++) {
            A_data[i5 + (b_k << 1U)] = p4[1 + i5].re;
          }
        }
      } else {
        guard2 = true;
      }
    } else {
      guard2 = true;
    }

    if (guard2) {
      i4 = (int)(((No2 - 1.0) + (2.0 - (double)nextidx)) / 2.0);
      for (k = 0; k < i4; k++) {
        b_k = nextidx + (k << 1U);
        i5 = (int)ceil((double)b_k / 2.0);
        for (i6 = 0; i6 < 5; i6++) {
          b_Br_data[i6] = Br_data[(i5 + Br_size_idx_0 * i6) - 1];
        }

        b_roots(b_Br_data, r_data, r_size);
        i5 = (int)ceil((double)b_k / 2.0);
        for (i6 = 0; i6 < 5; i6++) {
          b_Br_data[i6] = Ar_data[(i5 + Ar_size[0] * i6) - 1];
        }

        b_roots(b_Br_data, r2_data, r2_size);
        sort(r_data, r_size);
        sort(r2_data, r2_size);
        p1[0].re = 1.0;
        p1[0].im = 0.0;
        for (j = 0; j < 2; j++) {
          b_x[j] = r_data[j];
          p1_re = p1[j].re;
          p1[j + 1].re = -b_x[j].re * p1[j].re - -b_x[j].im * p1[j].im;
          p1[j + 1].im = -b_x[j].re * p1[j].im + -b_x[j].im * p1_re;
          loop_ub = j;
          while (loop_ub + 1 > 1) {
            p1[1].re -= b_x[j].re * p1[0].re - b_x[j].im * p1[0].im;
            p1[1].im -= b_x[j].re * p1[0].im + b_x[j].im * p1[0].re;
            loop_ub = 0;
          }
        }

        for (i5 = 0; i5 < 3; i5++) {
          B_data[i5 + 3 * (b_k - 1)] = p1[i5].re;
        }

        poly(*(creal_T (*)[2])&r2_data[0], p1);
        for (i5 = 0; i5 < 2; i5++) {
          A_data[i5 + ((b_k - 1) << 1U)] = p1[1 + i5].re;
        }

        poly(*(creal_T (*)[2])&r_data[2], p1);
        for (i5 = 0; i5 < 3; i5++) {
          B_data[i5 + 3 * b_k] = p1[i5].re;
        }

        poly(*(creal_T (*)[2])&r2_data[2], p1);
        for (i5 = 0; i5 < 2; i5++) {
          A_data[i5 + (b_k << 1U)] = p1[1 + i5].re;
        }
      }
    }

    B_size[0] = 3;
    loop_ub = 3 * (int)No2;
    for (i4 = 0; i4 < loop_ub; i4++) {
      B_data[i4] *= G_data[i4];
    }
  }
}

//
// File trailer for designParamEQ.cpp
//
// [EOF]
//
