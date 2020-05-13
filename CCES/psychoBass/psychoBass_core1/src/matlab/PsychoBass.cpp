//
// File: PsychoBass.cpp
//
// MATLAB Coder version            : 3.1
// C/C++ source code generated on  : 13-May-2020 13:38:55
//

// Include Files
#include "rt_nonfinite.h"
#include "PsychoBass.h"
#include "Nondirect.h"
#include "designVarSlopeFilter.h"
#include "SystemCore.h"
#include "VarSlopeBandpassFilter.h"
#include <stdio.h>

// Function Definitions

//
// HelperBassEnhancerSim This function is used in the "Psychoacoustic Bass
//  enhancement for Band-Limited Signals" featured example
//
//  x      : Input stereo signal
//  Fcutoff: Upper cutoff of the bass enhancer's bandpass filter
//  G      : Gain applied at output of the bandpass filter
// Arguments    : PsychoBassStackData *SD
//                const double x[64]
//                double Fcutoff
//                double G
//                double z[64]
// Return Type  : void
//
void PsychoBass(PsychoBassStackData *SD, const double x[64], double Fcutoff,
                double G, double z[64])
{
  boolean_T flag;
  audiopluginexample_BassEnhancer *obj;
  double b_x[64];
  double hp[64];
  double lpSum[32];
  int k;
  double Fs;
  audioexample_FullWaveIntegrator *b_obj;
  double uAbs[32];
  double integratorOutput[32];
  c_audiopluginexample_VarSlopeBa *c_obj;
  dspcodegen_BiquadFilter *d_obj;
  double varargin_2[24];
  double A;
  double B1[12];
  double A1[8];
  double varargin_3[16];
  double B2[12];
  double A2[8];
  int i0;

  //  Copyright 2015 The MathWorks, Inc.
  //  Instantiate and initialize System objects. The objects are declared
  //  persistent so that they are not recreated every time the function is
  //  called inside the simulation loop.
  if (!SD->pd->bassEnhancer_not_empty) {
    SD->pd->bassEnhancer.isInitialized = 0;
    SD->pd->bassEnhancer.PrivateSampleRate = 44100.0;
    SD->pd->bassEnhancer_not_empty = true;
  }

  //  Tune the object
  flag = (SD->pd->bassEnhancer.isInitialized == 1);
  if (flag) {
    SD->pd->bassEnhancer.TunablePropsChanged = true;
  }

  SD->pd->bassEnhancer.BPUpperCutoff = Fcutoff;
  flag = (SD->pd->bassEnhancer.isInitialized == 1);
  if (flag) {
    SD->pd->bassEnhancer.TunablePropsChanged = true;
  }

  SD->pd->bassEnhancer.Gain = G;
  obj = &SD->pd->bassEnhancer;
  if (SD->pd->bassEnhancer.isInitialized != 1) {
    SystemCore_setupAndReset(&SD->pd->bassEnhancer);
  }

  if (obj->TunablePropsChanged) {
    obj->TunablePropsChanged = false;
    if (obj->pFilter.HighCutoff != obj->BPUpperCutoff) {
      flag = (obj->pFilter.isInitialized == 1);
      if (flag) {
        obj->pFilter.TunablePropsChanged = true;
      }

      c_VarSlopeBandpassFilter_set_Hi(&obj->pFilter, obj->BPUpperCutoff);
    }

    if (obj->pGainFilter.Numerator != obj->Gain) {
      Fs = obj->Gain;
      obj->pGainFilter.cSFunObject.P1_Coefficients = Fs;
      obj->pGainFilter.Numerator = Fs;
    }
  }

  SystemCore_step(&obj->pCrossover, x, b_x, hp);
  for (k = 0; k < 32; k++) {
    lpSum[k] = b_x[k] + b_x[k + 32];
  }

  b_obj = &obj->pIntegrator;
  if (obj->pIntegrator.isInitialized != 1) {
    obj->pIntegrator.isInitialized = 1;
    obj->pIntegrator.yMinus1 = 0.0;
    obj->pIntegrator.uMinus1 = 0.0;
    obj->pIntegrator.yMinus1 = 0.0;
    obj->pIntegrator.uMinus1 = 0.0;
  }

  for (k = 0; k < 32; k++) {
    integratorOutput[k] = 0.0;
    uAbs[k] = fabs(lpSum[k]);
  }

  integratorOutput[0] = obj->pIntegrator.yMinus1 + obj->pIntegrator.K *
    obj->pIntegrator.uMinus1;
  for (k = 0; k < 31; k++) {
    integratorOutput[k + 1] = integratorOutput[k] + b_obj->K * uAbs[k];
    if ((lpSum[k + 1] > 0.0) && (lpSum[k] <= 0.0)) {
      integratorOutput[k + 1] = 0.0;
    }
  }

  obj->pIntegrator.yMinus1 = integratorOutput[31];
  obj->pIntegrator.uMinus1 = uAbs[31];
  c_obj = &obj->pFilter;
  if (obj->pFilter.isInitialized != 1) {
    obj->pFilter.isInitialized = 1;
    obj->pFilter.TunablePropsChanged = false;
    if (c_obj->SOSObj.isInitialized == 1) {
      // System object Initialization function: dsp.BiquadFilter
      Fs = obj->pFilter.SOSObj.cSFunObject.P0_ICRTP;
      for (k = 0; k < 16; k++) {
        obj->pFilter.SOSObj.cSFunObject.W0_FILT_STATES[k] = Fs;
      }
    }

    Fs = obj->pFilter.PrivateSampleRate;
    A = obj->pFilter.LowCutoff;
    designVarSlopeFilter(obj->pFilter.pLowSlopeNumeric, A / (Fs / 2.0), B1, A1);
    A = obj->pFilter.HighCutoff;
    b_designVarSlopeFilter(obj->pFilter.pHighSlopeNumeric, A / (Fs / 2.0), B2,
      A2);
    for (k = 0; k < 4; k++) {
      for (i0 = 0; i0 < 3; i0++) {
        obj->pFilter.Num[i0 + 3 * k] = B1[i0 + 3 * k];
      }
    }

    for (k = 0; k < 4; k++) {
      for (i0 = 0; i0 < 3; i0++) {
        obj->pFilter.Num[i0 + 3 * (k + 4)] = B2[i0 + 3 * k];
      }
    }

    for (k = 0; k < 4; k++) {
      for (i0 = 0; i0 < 2; i0++) {
        obj->pFilter.Den[i0 + (k << 1U)] = A1[i0 + (k << 1U)];
      }
    }

    for (k = 0; k < 4; k++) {
      for (i0 = 0; i0 < 2; i0++) {
        obj->pFilter.Den[i0 + ((k + 4) << 1U)] = A2[i0 + (k << 1U)];
      }
    }

    obj->pFilter.AreFiltersDesigned = true;
  }

  if (obj->pFilter.TunablePropsChanged) {
    obj->pFilter.TunablePropsChanged = false;
    if (!obj->pFilter.AreFiltersDesigned) {
      Fs = obj->pFilter.PrivateSampleRate;
      A = obj->pFilter.LowCutoff;
      designVarSlopeFilter(obj->pFilter.pLowSlopeNumeric, A / (Fs / 2.0), B1, A1);
      A = obj->pFilter.HighCutoff;
      b_designVarSlopeFilter(obj->pFilter.pHighSlopeNumeric, A / (Fs / 2.0), B2,
        A2);
      for (k = 0; k < 4; k++) {
        for (i0 = 0; i0 < 3; i0++) {
          obj->pFilter.Num[i0 + 3 * k] = B1[i0 + 3 * k];
        }
      }

      for (k = 0; k < 4; k++) {
        for (i0 = 0; i0 < 3; i0++) {
          obj->pFilter.Num[i0 + 3 * (k + 4)] = B2[i0 + 3 * k];
        }
      }

      for (k = 0; k < 4; k++) {
        for (i0 = 0; i0 < 2; i0++) {
          obj->pFilter.Den[i0 + (k << 1U)] = A1[i0 + (k << 1U)];
        }
      }

      for (k = 0; k < 4; k++) {
        for (i0 = 0; i0 < 2; i0++) {
          obj->pFilter.Den[i0 + ((k + 4) << 1U)] = A2[i0 + (k << 1U)];
        }
      }

      obj->pFilter.AreFiltersDesigned = true;
    }
  }

  d_obj = &obj->pFilter.SOSObj;
  for (k = 0; k < 24; k++) {
    varargin_2[k] = obj->pFilter.Num[k];
  }

  for (k = 0; k < 16; k++) {
    varargin_3[k] = obj->pFilter.Den[k];
  }

  if (c_obj->SOSObj.isInitialized != 1) {
    c_obj->SOSObj.isInitialized = 1;

    // System object Initialization function: dsp.BiquadFilter
    Fs = d_obj->cSFunObject.P0_ICRTP;
    for (k = 0; k < 16; k++) {
      d_obj->cSFunObject.W0_FILT_STATES[k] = Fs;
    }
  }

  Nondirect_stepImpl(&c_obj->SOSObj, integratorOutput, varargin_2, varargin_3,
                     lpSum);
  if (obj->pGainFilter.isInitialized != 1) {
    obj->pGainFilter.isInitialized = 1;
  }

  // System object Outputs function: dsp.FIRFilter
  for (k = 0; k < 32; k++) {
    Fs = lpSum[k] * obj->pGainFilter.cSFunObject.P1_Coefficients;
    z[k] = Fs + hp[k];
    z[32 + k] = Fs + hp[32 + k];
  }
}

//
// Arguments    : PsychoBassStackData *SD
// Return Type  : void
//
void bassEnhancer_not_empty_init(PsychoBassStackData *SD)
{
  SD->pd->bassEnhancer_not_empty = false;
}

//
// File trailer for PsychoBass.cpp
//
// [EOF]
//
