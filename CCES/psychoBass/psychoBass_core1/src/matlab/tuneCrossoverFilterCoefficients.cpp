//
// File: tuneCrossoverFilterCoefficients.cpp
//
// MATLAB Coder version            : 3.1
// C/C++ source code generated on  : 13-May-2020 13:38:55
//

// Include Files
#include "rt_nonfinite.h"
#include "PsychoBass.h"
#include "tuneCrossoverFilterCoefficients.h"
#include "repmat.h"
#include "designLPHPFilter.h"
#include "mod.h"
#include <stdio.h>

// Function Definitions

//
// Arguments    : double freq
//                double order
//                double Fs
//                double BL[12]
//                double AL[12]
//                double BH[12]
//                double AH[12]
//                double *phaseMult
// Return Type  : void
//
void tuneCrossoverFilterCoefficients(double freq, double order, double Fs,
  double BL[12], double AL[12], double BH[12], double AH[12], double *phaseMult)
{
  double FCast;
  double FsbyTwo;
  boolean_T isEven;
  int ord;
  double B0L_data[21];
  int B0L_size[2];
  double A0L_data[14];
  int A0L_size[2];
  double B0H_data[21];
  int B0H_size[2];
  double A0H_data[14];
  int A0H_size[2];
  int i14;
  int i15;
  int i16;
  FCast = freq;
  FsbyTwo = Fs / 2.0;
  if (freq >= FsbyTwo) {
    FCast = FsbyTwo - 1.0;
  }

  FCast /= FsbyTwo;
  FsbyTwo = order;
  if ((order == 2.0) || (order == 6.0)) {
    *phaseMult = -1.0;
  } else {
    *phaseMult = 1.0;
  }

  isEven = false;
  if (b_mod(order) == 0.0) {
    FsbyTwo = order / 2.0;
    isEven = true;
  }

  switch ((int)FsbyTwo) {
   case 1:
    ord = 2;
    break;

   case 2:
    ord = 4;
    break;

   case 3:
    ord = 6;
    break;

   case 4:
    ord = 8;
    break;

   case 5:
    ord = 10;
    break;

   case 6:
    ord = 12;
    break;

   case 7:
    ord = 14;
    break;

   default:
    ord = 2;
    break;
  }

  designLPHPFilter((double)ord, 1.0 - FCast, B0L_data, B0L_size, A0L_data,
                   A0L_size);
  b_designLPHPFilter((double)ord, FCast, B0H_data, B0H_size, A0H_data, A0H_size);
  b_repmat(BL);
  b_repmat(AL);
  b_repmat(BH);
  b_repmat(AH);
  if (isEven) {
    FCast = ceil(FsbyTwo / 2.0);
    if (1.0 > FCast) {
      ord = -1;
    } else {
      ord = (int)FCast - 1;
    }

    for (i14 = 0; i14 <= ord; i14++) {
      for (i15 = 0; i15 < 3; i15++) {
        BL[i15 + 3 * i14] = B0L_data[i15 + B0L_size[0] * i14];
      }
    }

    FCast = ceil(FsbyTwo / 2.0);
    if (1.0 > FCast) {
      ord = -1;
    } else {
      ord = (int)FCast - 1;
    }

    if (3.0 > (3.0 + ceil(FsbyTwo / 2.0)) - 1.0) {
      i14 = 0;
    } else {
      i14 = 2;
    }

    for (i15 = 0; i15 <= ord; i15++) {
      for (i16 = 0; i16 < 3; i16++) {
        BL[i16 + 3 * (i14 + i15)] = B0L_data[i16 + B0L_size[0] * i15];
      }
    }

    FCast = ceil(FsbyTwo / 2.0);
    if (1.0 > FCast) {
      ord = -1;
    } else {
      ord = (int)FCast - 1;
    }

    for (i14 = 0; i14 <= ord; i14++) {
      for (i15 = 0; i15 < 2; i15++) {
        AL[(i15 + 3 * i14) + 1] = A0L_data[i15 + A0L_size[0] * i14];
      }
    }

    FCast = ceil(FsbyTwo / 2.0);
    if (1.0 > FCast) {
      ord = -1;
    } else {
      ord = (int)FCast - 1;
    }

    if (3.0 > (3.0 + ceil(FsbyTwo / 2.0)) - 1.0) {
      i14 = 0;
    } else {
      i14 = 2;
    }

    for (i15 = 0; i15 <= ord; i15++) {
      for (i16 = 0; i16 < 2; i16++) {
        AL[(i16 + 3 * (i14 + i15)) + 1] = A0L_data[i16 + A0L_size[0] * i15];
      }
    }

    FCast = ceil(FsbyTwo / 2.0);
    if (1.0 > FCast) {
      ord = -1;
    } else {
      ord = (int)FCast - 1;
    }

    for (i14 = 0; i14 <= ord; i14++) {
      for (i15 = 0; i15 < 3; i15++) {
        BH[i15 + 3 * i14] = B0H_data[i15 + B0H_size[0] * i14];
      }
    }

    FCast = ceil(FsbyTwo / 2.0);
    if (1.0 > FCast) {
      ord = -1;
    } else {
      ord = (int)FCast - 1;
    }

    if (3.0 > (3.0 + ceil(FsbyTwo / 2.0)) - 1.0) {
      i14 = 0;
    } else {
      i14 = 2;
    }

    for (i15 = 0; i15 <= ord; i15++) {
      for (i16 = 0; i16 < 3; i16++) {
        BH[i16 + 3 * (i14 + i15)] = B0H_data[i16 + B0H_size[0] * i15];
      }
    }

    FCast = ceil(FsbyTwo / 2.0);
    if (1.0 > FCast) {
      ord = -1;
    } else {
      ord = (int)FCast - 1;
    }

    for (i14 = 0; i14 <= ord; i14++) {
      for (i15 = 0; i15 < 2; i15++) {
        AH[(i15 + 3 * i14) + 1] = A0H_data[i15 + A0H_size[0] * i14];
      }
    }

    FCast = ceil(FsbyTwo / 2.0);
    if (1.0 > FCast) {
      ord = -1;
    } else {
      ord = (int)FCast - 1;
    }

    if (3.0 > (3.0 + ceil(FsbyTwo / 2.0)) - 1.0) {
      i14 = 0;
    } else {
      i14 = 2;
    }

    for (i15 = 0; i15 <= ord; i15++) {
      for (i16 = 0; i16 < 2; i16++) {
        AH[(i16 + 3 * (i14 + i15)) + 1] = A0H_data[i16 + A0H_size[0] * i15];
      }
    }
  } else {
    FCast = ceil(FsbyTwo / 2.0);
    if (1.0 > FCast) {
      ord = -1;
    } else {
      ord = (int)FCast - 1;
    }

    for (i14 = 0; i14 <= ord; i14++) {
      for (i15 = 0; i15 < 3; i15++) {
        BL[i15 + 3 * i14] = B0L_data[i15 + B0L_size[0] * i14];
      }
    }

    FCast = ceil(FsbyTwo / 2.0);
    if (1.0 > FCast) {
      ord = -1;
    } else {
      ord = (int)FCast - 1;
    }

    for (i14 = 0; i14 <= ord; i14++) {
      for (i15 = 0; i15 < 2; i15++) {
        AL[(i15 + 3 * i14) + 1] = A0L_data[i15 + A0L_size[0] * i14];
      }
    }

    FCast = ceil(FsbyTwo / 2.0);
    if (1.0 > FCast) {
      ord = -1;
    } else {
      ord = (int)FCast - 1;
    }

    for (i14 = 0; i14 <= ord; i14++) {
      for (i15 = 0; i15 < 3; i15++) {
        BH[i15 + 3 * i14] = B0H_data[i15 + B0H_size[0] * i14];
      }
    }

    FCast = ceil(FsbyTwo / 2.0);
    if (1.0 > FCast) {
      ord = -1;
    } else {
      ord = (int)FCast - 1;
    }

    for (i14 = 0; i14 <= ord; i14++) {
      for (i15 = 0; i15 < 2; i15++) {
        AH[(i15 + 3 * i14) + 1] = A0H_data[i15 + A0H_size[0] * i14];
      }
    }
  }
}

//
// File trailer for tuneCrossoverFilterCoefficients.cpp
//
// [EOF]
//
