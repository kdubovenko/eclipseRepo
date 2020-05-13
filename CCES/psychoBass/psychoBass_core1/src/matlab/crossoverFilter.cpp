//
// File: crossoverFilter.cpp
//
// MATLAB Coder version            : 3.1
// C/C++ source code generated on  : 13-May-2020 13:38:55
//

// Include Files
#include "rt_nonfinite.h"
#include "PsychoBass.h"
#include "crossoverFilter.h"
#include "filter.h"
#include "tuneCrossoverFilterCoefficients.h"
#include "SystemCore.h"
#include <stdio.h>

// Function Definitions

//
// Arguments    : crossoverFilter *obj
// Return Type  : void
//
void crossoverFilter_resetImpl(crossoverFilter *obj)
{
  crossoverFilter *b_obj;
  boolean_T flag;
  double Fs;
  c_audio_internal_TwoBandCrossov *c_obj;
  int i21;
  double BL1[12];
  double AL1[12];
  double BH1[12];
  double AH1[12];
  b_obj = obj;
  flag = (b_obj->pFilter.isInitialized == 1);
  if (flag) {
    b_obj->pFilter.TunablePropsChanged = true;
  }

  Fs = b_obj->pSampleRateDialog;
  b_obj->pFilter.SampleRate = Fs;
  flag = (b_obj->pFilter.isInitialized == 1);
  if (flag) {
    b_obj->pFilter.TunablePropsChanged = true;
  }

  b_obj->pFilter.CrossoverFrequencies = b_obj->pCrossoverFrequencies;
  flag = (b_obj->pFilter.isInitialized == 1);
  if (flag) {
    b_obj->pFilter.TunablePropsChanged = true;
  }

  b_obj->pFilter.CrossoverOrders = b_obj->pOrders;
  c_obj = &obj->pFilter;
  if (c_obj->isInitialized == 1) {
    for (i21 = 0; i21 < 16; i21++) {
      c_obj->pCR1_States_LP[i21] = 0.0;
    }

    for (i21 = 0; i21 < 16; i21++) {
      c_obj->pCR1_States_HP[i21] = 0.0;
    }

    tuneCrossoverFilterCoefficients(c_obj->CrossoverFrequencies,
      c_obj->CrossoverOrders, c_obj->SampleRate, BL1, AL1, BH1, AH1,
      &c_obj->pPhaseMult);
    for (i21 = 0; i21 < 12; i21++) {
      c_obj->pCR1_B_LP[i21] = BL1[i21];
    }

    for (i21 = 0; i21 < 12; i21++) {
      c_obj->pCR1_A_LP[i21] = AL1[i21];
    }

    for (i21 = 0; i21 < 12; i21++) {
      c_obj->pCR1_B_HP[i21] = BH1[i21];
    }

    for (i21 = 0; i21 < 12; i21++) {
      c_obj->pCR1_A_HP[i21] = AH1[i21];
    }
  }
}

//
// Arguments    : crossoverFilter *obj
//                const double x[64]
//                double varargout_1[64]
//                double varargout_2[64]
// Return Type  : void
//
void crossoverFilter_stepImpl(crossoverFilter *obj, const double x[64], double
  varargout_1[64], double varargout_2[64])
{
  c_audio_internal_TwoBandCrossov *b_obj;
  int i22;
  double B[12];
  double A[12];
  double BH1[12];
  double AH1[12];
  double S[16];
  int b_index;
  double b_B[3];
  double b_A[3];
  double b_varargout_1[64];
  double b_S[4];
  int i23;
  double b;
  double b_varargout_2[64];
  b_obj = &obj->pFilter;
  if (b_obj->isInitialized != 1) {
    SystemCore_setup(b_obj);
    for (i22 = 0; i22 < 16; i22++) {
      b_obj->pCR1_States_LP[i22] = 0.0;
    }

    for (i22 = 0; i22 < 16; i22++) {
      b_obj->pCR1_States_HP[i22] = 0.0;
    }

    tuneCrossoverFilterCoefficients(b_obj->CrossoverFrequencies,
      b_obj->CrossoverOrders, b_obj->SampleRate, B, A, BH1, AH1,
      &b_obj->pPhaseMult);
    for (i22 = 0; i22 < 12; i22++) {
      b_obj->pCR1_B_LP[i22] = B[i22];
    }

    for (i22 = 0; i22 < 12; i22++) {
      b_obj->pCR1_A_LP[i22] = A[i22];
    }

    for (i22 = 0; i22 < 12; i22++) {
      b_obj->pCR1_B_HP[i22] = BH1[i22];
    }

    for (i22 = 0; i22 < 12; i22++) {
      b_obj->pCR1_A_HP[i22] = AH1[i22];
    }
  }

  if (b_obj->TunablePropsChanged) {
    b_obj->TunablePropsChanged = false;
    tuneCrossoverFilterCoefficients(b_obj->CrossoverFrequencies,
      b_obj->CrossoverOrders, b_obj->SampleRate, B, A, BH1, AH1,
      &b_obj->pPhaseMult);
    for (i22 = 0; i22 < 12; i22++) {
      b_obj->pCR1_B_LP[i22] = B[i22];
    }

    for (i22 = 0; i22 < 12; i22++) {
      b_obj->pCR1_A_LP[i22] = A[i22];
    }

    for (i22 = 0; i22 < 12; i22++) {
      b_obj->pCR1_B_HP[i22] = BH1[i22];
    }

    for (i22 = 0; i22 < 12; i22++) {
      b_obj->pCR1_A_HP[i22] = AH1[i22];
    }
  }

  memcpy(&varargout_1[0], &x[0], sizeof(double) << 6U);
  for (i22 = 0; i22 < 12; i22++) {
    B[i22] = b_obj->pCR1_B_LP[i22];
    A[i22] = b_obj->pCR1_A_LP[i22];
  }

  for (i22 = 0; i22 < 16; i22++) {
    S[i22] = b_obj->pCR1_States_LP[i22];
  }

  for (b_index = 0; b_index < 4; b_index++) {
    for (i22 = 0; i22 < 3; i22++) {
      b_B[i22] = B[i22 + 3 * b_index];
      b_A[i22] = A[i22 + 3 * b_index];
    }

    memcpy(&b_varargout_1[0], &varargout_1[0], sizeof(double) << 6U);
    for (i22 = 0; i22 < 2; i22++) {
      for (i23 = 0; i23 < 2; i23++) {
        b_S[i23 + (i22 << 1U)] = S[(i23 + (i22 << 1U)) + (b_index << 2U)];
      }
    }

    filter(b_B, b_A, b_varargout_1, b_S, varargout_1, *(double (*)[4])&S[b_index
           << 2U]);
  }

  for (i22 = 0; i22 < 16; i22++) {
    b_obj->pCR1_States_LP[i22] = S[i22];
  }

  memcpy(&varargout_2[0], &x[0], sizeof(double) << 6U);
  for (i22 = 0; i22 < 12; i22++) {
    B[i22] = b_obj->pCR1_B_HP[i22];
    A[i22] = b_obj->pCR1_A_HP[i22];
  }

  for (i22 = 0; i22 < 16; i22++) {
    S[i22] = b_obj->pCR1_States_HP[i22];
  }

  for (b_index = 0; b_index < 4; b_index++) {
    for (i22 = 0; i22 < 3; i22++) {
      b_B[i22] = B[i22 + 3 * b_index];
      b_A[i22] = A[i22 + 3 * b_index];
    }

    memcpy(&b_varargout_2[0], &varargout_2[0], sizeof(double) << 6U);
    for (i22 = 0; i22 < 2; i22++) {
      for (i23 = 0; i23 < 2; i23++) {
        b_S[i23 + (i22 << 1U)] = S[(i23 + (i22 << 1U)) + (b_index << 2U)];
      }
    }

    filter(b_B, b_A, b_varargout_2, b_S, varargout_2, *(double (*)[4])&S[b_index
           << 2U]);
  }

  for (i22 = 0; i22 < 16; i22++) {
    b_obj->pCR1_States_HP[i22] = S[i22];
  }

  b = b_obj->pPhaseMult;
  for (i22 = 0; i22 < 64; i22++) {
    varargout_2[i22] *= b;
  }
}

//
// File trailer for crossoverFilter.cpp
//
// [EOF]
//
