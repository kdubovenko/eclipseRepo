//
// File: designVarSlopeFilter.cpp
//
// MATLAB Coder version            : 3.1
// C/C++ source code generated on  : 13-May-2020 13:38:55
//

// Include Files
#include "rt_nonfinite.h"
#include "PsychoBass.h"
#include "designVarSlopeFilter.h"
#include "designParamEQ.h"
#include "PsychoBass_rtwutil.h"
#include <stdio.h>

// Function Definitions

//
// Arguments    : double Slope
//                double Fc
//                double B[12]
//                double A[8]
// Return Type  : void
//
void b_designVarSlopeFilter(double Slope, double Fc, double B[12], double A[8])
{
  int i;
  int N;
  double unnamed_idx_0;
  double Num_data[24];
  int Num_size[2];
  double Den_data[16];
  int Den_size[2];
  int loop_ub;
  int i9;
  if (Fc <= 1.0) {
  } else {
    Fc = 1.0;
  }

  Slope = 6.0 * rt_roundd_snf(Slope / 6.0);
  for (i = 0; i < 12; i++) {
    B[i] = 0.0;
  }

  for (i = 0; i < 4; i++) {
    B[3 * i] = 1.0;
  }

  for (i = 0; i < 8; i++) {
    A[i] = 0.0;
  }

  if (Slope != 0.0) {
    N = 2;
    if (Slope == 12.0) {
      N = 4;
    } else if (Slope == 18.0) {
      N = 6;
    } else if (Slope == 24.0) {
      N = 8;
    } else if (Slope == 30.0) {
      N = 10;
    } else if (Slope == 36.0) {
      N = 12;
    } else if (Slope == 42.0) {
      N = 14;
    } else {
      if (Slope == 48.0) {
        N = 16;
      }
    }

    unnamed_idx_0 = 1.0 - Fc;
    for (i = 0; i < 1; i++) {
      if (1.0 - Fc > 1.0) {
        unnamed_idx_0 = 1.0;
      }
    }

    b_designEachParamEQ((double)N, unnamed_idx_0, Num_data, Num_size, Den_data,
                        Den_size);
    loop_ub = (int)ceil((double)N / 4.0) - 1;
    for (i = 0; i <= loop_ub; i++) {
      for (i9 = 0; i9 < 3; i9++) {
        B[i9 + 3 * i] = Num_data[i9 + Num_size[0] * i];
      }
    }

    loop_ub = (int)ceil((double)N / 4.0) - 1;
    for (i = 0; i <= loop_ub; i++) {
      for (i9 = 0; i9 < 2; i9++) {
        A[i9 + (i << 1U)] = Den_data[i9 + Den_size[0] * i];
      }
    }
  }
}

//
// Arguments    : double Slope
//                double Fc
//                double B[12]
//                double A[8]
// Return Type  : void
//
void designVarSlopeFilter(double Slope, double Fc, double B[12], double A[8])
{
  int i;
  int N;
  double unnamed_idx_0;
  double Num_data[24];
  int Num_size[2];
  double Den_data[16];
  int Den_size[2];
  int loop_ub;
  int i3;
  if (Fc <= 1.0) {
  } else {
    Fc = 1.0;
  }

  Slope = 6.0 * rt_roundd_snf(Slope / 6.0);
  for (i = 0; i < 12; i++) {
    B[i] = 0.0;
  }

  for (i = 0; i < 4; i++) {
    B[3 * i] = 1.0;
  }

  for (i = 0; i < 8; i++) {
    A[i] = 0.0;
  }

  if (Slope != 0.0) {
    N = 2;
    if (Slope == 12.0) {
      N = 4;
    } else if (Slope == 18.0) {
      N = 6;
    } else if (Slope == 24.0) {
      N = 8;
    } else if (Slope == 30.0) {
      N = 10;
    } else if (Slope == 36.0) {
      N = 12;
    } else if (Slope == 42.0) {
      N = 14;
    } else {
      if (Slope == 48.0) {
        N = 16;
      }
    }

    unnamed_idx_0 = Fc;
    for (i = 0; i < 1; i++) {
      if (Fc < 0.0) {
        unnamed_idx_0 = 0.0;
      }
    }

    designEachParamEQ((double)N, unnamed_idx_0, Num_data, Num_size, Den_data,
                      Den_size);
    loop_ub = (int)ceil((double)N / 4.0) - 1;
    for (i = 0; i <= loop_ub; i++) {
      for (i3 = 0; i3 < 3; i3++) {
        B[i3 + 3 * i] = Num_data[i3 + Num_size[0] * i];
      }
    }

    loop_ub = (int)ceil((double)N / 4.0) - 1;
    for (i = 0; i <= loop_ub; i++) {
      for (i3 = 0; i3 < 2; i3++) {
        A[i3 + (i << 1U)] = Den_data[i3 + Den_size[0] * i];
      }
    }
  }
}

//
// File trailer for designVarSlopeFilter.cpp
//
// [EOF]
//
