//
// File: SystemCore.cpp
//
// MATLAB Coder version            : 3.1
// C/C++ source code generated on  : 13-May-2020 13:38:55
//

// Include Files
#include "rt_nonfinite.h"
#include "PsychoBass.h"
#include "SystemCore.h"
#include "tuneCrossoverFilterCoefficients.h"
#include "repmat.h"
#include "crossoverFilter.h"
#include "designVarSlopeFilter.h"
#include "VarSlopeBandpassFilter.h"
#include "designParamEQ.h"
#include "PsychoBass_rtwutil.h"
#include <stdio.h>

// Function Definitions

//
// Arguments    : c_audio_internal_TwoBandCrossov *obj
// Return Type  : void
//
void SystemCore_setup(c_audio_internal_TwoBandCrossov *obj)
{
  c_audio_internal_TwoBandCrossov *b_obj;
  double BL1[12];
  double AL1[12];
  double BH1[12];
  double AH1[12];
  int i13;
  obj->isInitialized = 1;
  b_obj = obj;
  b_repmat(b_obj->pCR1_B_LP);
  b_repmat(b_obj->pCR1_A_LP);
  b_repmat(b_obj->pCR1_B_HP);
  b_repmat(b_obj->pCR1_A_HP);
  b_obj->pPhaseMult = 0.0;
  tuneCrossoverFilterCoefficients(b_obj->CrossoverFrequencies,
    b_obj->CrossoverOrders, b_obj->SampleRate, BL1, AL1, BH1, AH1,
    &b_obj->pPhaseMult);
  for (i13 = 0; i13 < 12; i13++) {
    b_obj->pCR1_B_LP[i13] = BL1[i13];
  }

  for (i13 = 0; i13 < 12; i13++) {
    b_obj->pCR1_A_LP[i13] = AL1[i13];
  }

  for (i13 = 0; i13 < 12; i13++) {
    b_obj->pCR1_B_HP[i13] = BH1[i13];
  }

  for (i13 = 0; i13 < 12; i13++) {
    b_obj->pCR1_A_HP[i13] = AH1[i13];
  }

  obj->TunablePropsChanged = false;
}

//
// Arguments    : audiopluginexample_BassEnhancer *obj
// Return Type  : void
//
void SystemCore_setupAndReset(audiopluginexample_BassEnhancer *obj)
{
  audiopluginexample_BassEnhancer *b_obj;
  int i1;
  static const int iv0[4] = { 100, 800, 1500, 3000 };

  boolean_T flag;
  double A;
  c_audiopluginexample_VarSlopeBa *plugin;
  double Fs;
  double B1[12];
  double A1[8];
  double B2[12];
  double A2[8];
  int i2;
  dspcodegen_FIRFilter *c_obj;
  b_obj = obj;
  b_obj->isInitialized = 1;
  b_obj->pCrossover.pNumChannels = -1.0;
  for (i1 = 0; i1 < 4; i1++) {
    b_obj->pCrossover.pFreq[i1] = iv0[i1];
  }

  for (i1 = 0; i1 < 4; i1++) {
    b_obj->pCrossover.pSlopes[i1] = 12.0;
  }

  b_obj->pCrossover.isInitialized = 0;
  flag = (b_obj->pCrossover.isInitialized == 1);
  if (flag) {
    b_obj->pCrossover.TunablePropsChanged = true;
  }

  b_obj->pCrossover.pFreq[0] = 60.0;
  flag = (b_obj->pCrossover.isInitialized == 1);
  if (flag) {
    b_obj->pCrossover.TunablePropsChanged = true;
  }

  b_obj->pCrossover.pSlopes[0] = 24.0;
  A = b_obj->pCrossover.pSlopes[0];
  A = 6.0 * rt_roundd_snf(A / 6.0);
  if (A <= 48.0) {
    b_obj->pCrossover.pSlopes[0] = A;
  } else {
    b_obj->pCrossover.pSlopes[0] = 48.0;
  }

  if (b_obj->pCrossover.pSlopes[0] == 0.0) {
    b_obj->pCrossover.pSlopes[0] = 6.0;
  }

  b_obj->pIntegrator.K = 1.0;
  b_obj->pIntegrator.isInitialized = 0;
  plugin = &b_obj->pFilter;
  A = b_obj->BPUpperCutoff;
  b_obj->pFilter.isInitialized = 0;
  b_obj->pFilter.PrivateSampleRate = 44100.0;
  flag = (b_obj->pFilter.isInitialized == 1);
  if (flag) {
    b_obj->pFilter.TunablePropsChanged = true;
  }

  b_obj->pFilter.LowCutoff = 60.0;
  b_obj->pFilter.AreFiltersDesigned = false;
  flag = (b_obj->pFilter.isInitialized == 1);
  if (flag) {
    b_obj->pFilter.TunablePropsChanged = true;
  }

  c_VarSlopeBandpassFilter_set_Hi(&b_obj->pFilter, A);
  flag = (b_obj->pFilter.isInitialized == 1);
  if (flag) {
    b_obj->pFilter.TunablePropsChanged = true;
  }

  b_obj->pFilter.pLowSlopeNumeric = 24.0;
  b_obj->pFilter.AreFiltersDesigned = false;
  flag = (b_obj->pFilter.isInitialized == 1);
  if (flag) {
    b_obj->pFilter.TunablePropsChanged = true;
  }

  b_obj->pFilter.pHighSlopeNumeric = 24.0;
  b_obj->pFilter.AreFiltersDesigned = false;
  plugin->SOSObj.isInitialized = 0;

  // System object Constructor function: dsp.BiquadFilter
  b_obj->pFilter.SOSObj.cSFunObject.P0_ICRTP = 0.0;
  Fs = b_obj->pFilter.PrivateSampleRate;
  A = b_obj->pFilter.LowCutoff;
  designVarSlopeFilter(b_obj->pFilter.pLowSlopeNumeric, A / (Fs / 2.0), B1, A1);
  A = b_obj->pFilter.HighCutoff;
  b_designVarSlopeFilter(b_obj->pFilter.pHighSlopeNumeric, A / (Fs / 2.0), B2,
    A2);
  for (i1 = 0; i1 < 4; i1++) {
    for (i2 = 0; i2 < 3; i2++) {
      b_obj->pFilter.Num[i2 + 3 * i1] = B1[i2 + 3 * i1];
    }
  }

  for (i1 = 0; i1 < 4; i1++) {
    for (i2 = 0; i2 < 3; i2++) {
      b_obj->pFilter.Num[i2 + 3 * (i1 + 4)] = B2[i2 + 3 * i1];
    }
  }

  for (i1 = 0; i1 < 4; i1++) {
    for (i2 = 0; i2 < 2; i2++) {
      b_obj->pFilter.Den[i2 + (i1 << 1U)] = A1[i2 + (i1 << 1U)];
    }
  }

  for (i1 = 0; i1 < 4; i1++) {
    for (i2 = 0; i2 < 2; i2++) {
      b_obj->pFilter.Den[i2 + ((i1 + 4) << 1U)] = A2[i2 + (i1 << 1U)];
    }
  }

  b_obj->pFilter.AreFiltersDesigned = true;
  c_obj = &b_obj->pGainFilter;
  b_obj->pGainFilter.isInitialized = 0;

  // System object Constructor function: dsp.FIRFilter
  c_obj->cSFunObject.P0_InitialStates = 0.0;
  c_obj->cSFunObject.P1_Coefficients = 1.0;
  c_obj->cSFunObject.P1_Coefficients = 1.0;
  b_obj->pGainFilter.Numerator = 1.0;
  b_obj->pGainFilter.isInitialized = 1;
  A = b_obj->Gain;
  b_obj->pGainFilter.cSFunObject.P1_Coefficients = A;
  b_obj->pGainFilter.Numerator = A;
  b_obj->TunablePropsChanged = false;
  b_obj = obj;
  flag = (b_obj->pCrossover.isInitialized == 1);
  if (flag) {
    b_obj->pCrossover.TunablePropsChanged = true;
  }

  A = b_obj->PrivateSampleRate;
  b_obj->pCrossover.pSampleRateDialog = A;
  plugin = &b_obj->pFilter;
  if (b_obj->pFilter.isInitialized == 1) {
    if (plugin->SOSObj.isInitialized == 1) {
      // System object Initialization function: dsp.BiquadFilter
      A = b_obj->pFilter.SOSObj.cSFunObject.P0_ICRTP;
      for (i1 = 0; i1 < 16; i1++) {
        b_obj->pFilter.SOSObj.cSFunObject.W0_FILT_STATES[i1] = A;
      }
    }

    Fs = b_obj->pFilter.PrivateSampleRate;
    A = b_obj->pFilter.LowCutoff;
    designVarSlopeFilter(b_obj->pFilter.pLowSlopeNumeric, A / (Fs / 2.0), B1, A1);
    A = b_obj->pFilter.HighCutoff;
    b_designVarSlopeFilter(b_obj->pFilter.pHighSlopeNumeric, A / (Fs / 2.0), B2,
      A2);
    for (i1 = 0; i1 < 4; i1++) {
      for (i2 = 0; i2 < 3; i2++) {
        b_obj->pFilter.Num[i2 + 3 * i1] = B1[i2 + 3 * i1];
      }
    }

    for (i1 = 0; i1 < 4; i1++) {
      for (i2 = 0; i2 < 3; i2++) {
        b_obj->pFilter.Num[i2 + 3 * (i1 + 4)] = B2[i2 + 3 * i1];
      }
    }

    for (i1 = 0; i1 < 4; i1++) {
      for (i2 = 0; i2 < 2; i2++) {
        b_obj->pFilter.Den[i2 + (i1 << 1U)] = A1[i2 + (i1 << 1U)];
      }
    }

    for (i1 = 0; i1 < 4; i1++) {
      for (i2 = 0; i2 < 2; i2++) {
        b_obj->pFilter.Den[i2 + ((i1 + 4) << 1U)] = A2[i2 + (i1 << 1U)];
      }
    }

    b_obj->pFilter.AreFiltersDesigned = true;
  }

  if (b_obj->pCrossover.isInitialized == 1) {
    crossoverFilter_resetImpl(&b_obj->pCrossover);
  }

  if (b_obj->pIntegrator.isInitialized == 1) {
    b_obj->pIntegrator.yMinus1 = 0.0;
    b_obj->pIntegrator.uMinus1 = 0.0;
  }
}

//
// Arguments    : crossoverFilter *obj
//                const double varargin_1[64]
//                double varargout_1[64]
//                double varargout_2[64]
// Return Type  : void
//
void SystemCore_step(crossoverFilter *obj, const double varargin_1[64], double
                     varargout_1[64], double varargout_2[64])
{
  crossoverFilter *b_obj;
  int k;
  double freq;
  static const unsigned int inputSize[8] = { 32U, 2U, 1U, 1U, 1U, 1U, 1U, 1U };

  double freqVect;
  boolean_T exitg1;
  double FsByTwo;
  static const unsigned int uv0[8] = { 32U, 2U, 1U, 1U, 1U, 1U, 1U, 1U };

  boolean_T flag;
  double BL1[12];
  double AL1[12];
  double BH1[12];
  double AH1[12];
  if (obj->isInitialized != 1) {
    b_obj = obj;
    b_obj->isInitialized = 1;
    for (k = 0; k < 8; k++) {
      b_obj->inputVarSize1[k] = inputSize[k];
    }

    b_obj->pNumChannels = 2.0;
    freq = b_obj->pFreq[0];
    b_obj->pCrossoverFrequencies = freq;
    freq = b_obj->pCrossoverFrequencies;
    freqVect = b_obj->pSampleRateDialog;
    FsByTwo = freqVect / 2.0;
    freqVect = freq;
    if (freq >= FsByTwo) {
      freqVect = FsByTwo - 1.0;
    }

    if (freq == 0.0) {
      freqVect = 1.0;
    }

    b_obj->pCrossoverFrequencies = freqVect;
    freqVect = b_obj->pSlopes[0];
    b_obj->pOrders = freqVect / 6.0;
    freqVect = b_obj->pSampleRateDialog;
    b_obj->pFilter.isInitialized = 0;
    flag = (b_obj->pFilter.isInitialized == 1);
    if (flag) {
      b_obj->pFilter.TunablePropsChanged = true;
    }

    b_obj->pFilter.SampleRate = freqVect;
    flag = (b_obj->pFilter.isInitialized == 1);
    if (flag) {
      b_obj->pFilter.TunablePropsChanged = true;
    }

    b_obj->pFilter.CrossoverFrequencies = 500.0;
    flag = (b_obj->pFilter.isInitialized == 1);
    if (flag) {
      b_obj->pFilter.TunablePropsChanged = true;
    }

    b_obj->pFilter.CrossoverOrders = 2.0;
    SystemCore_setup(&b_obj->pFilter);
    flag = (b_obj->pFilter.isInitialized == 1);
    if (flag) {
      b_obj->pFilter.TunablePropsChanged = true;
    }

    freqVect = b_obj->pSampleRateDialog;
    b_obj->pFilter.SampleRate = freqVect;
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
    if (b_obj->pFilter.isInitialized == 1) {
      for (k = 0; k < 16; k++) {
        b_obj->pFilter.pCR1_States_LP[k] = 0.0;
      }

      for (k = 0; k < 16; k++) {
        b_obj->pFilter.pCR1_States_HP[k] = 0.0;
      }

      tuneCrossoverFilterCoefficients(b_obj->pFilter.CrossoverFrequencies,
        b_obj->pFilter.CrossoverOrders, b_obj->pFilter.SampleRate, BL1, AL1, BH1,
        AH1, &b_obj->pFilter.pPhaseMult);
      for (k = 0; k < 12; k++) {
        b_obj->pFilter.pCR1_B_LP[k] = BL1[k];
      }

      for (k = 0; k < 12; k++) {
        b_obj->pFilter.pCR1_A_LP[k] = AL1[k];
      }

      for (k = 0; k < 12; k++) {
        b_obj->pFilter.pCR1_B_HP[k] = BH1[k];
      }

      for (k = 0; k < 12; k++) {
        b_obj->pFilter.pCR1_A_HP[k] = AH1[k];
      }
    }

    b_obj->TunablePropsChanged = false;
    crossoverFilter_resetImpl(b_obj);
  }

  b_obj = obj;
  if (b_obj->TunablePropsChanged) {
    b_obj->TunablePropsChanged = false;
    freq = b_obj->pFreq[0];
    freqVect = b_obj->pSampleRateDialog;
    FsByTwo = freqVect / 2.0;
    freqVect = freq;
    if (freq >= FsByTwo) {
      freqVect = FsByTwo - 1.0;
    }

    if (freq == 0.0) {
      freqVect = 1.0;
    }

    b_obj->pCrossoverFrequencies = freqVect;
    freqVect = b_obj->pSlopes[0];
    b_obj->pOrders = freqVect / 6.0;
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
    flag = (b_obj->pFilter.isInitialized == 1);
    if (flag) {
      b_obj->pFilter.TunablePropsChanged = true;
    }

    freqVect = b_obj->pSampleRateDialog;
    b_obj->pFilter.SampleRate = freqVect;
  }

  b_obj = obj;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 8)) {
    if (b_obj->inputVarSize1[k] != uv0[k]) {
      for (k = 0; k < 8; k++) {
        b_obj->inputVarSize1[k] = inputSize[k];
      }

      exitg1 = true;
    } else {
      k++;
    }
  }

  crossoverFilter_stepImpl(obj, varargin_1, varargout_1, varargout_2);
}

//
// File trailer for SystemCore.cpp
//
// [EOF]
//
