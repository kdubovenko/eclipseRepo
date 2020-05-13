//
// File: PsychoBass_types.h
//
// MATLAB Coder version            : 3.1
// C/C++ source code generated on  : 13-May-2020 13:38:55
//
#ifndef PSYCHOBASS_TYPES_H
#define PSYCHOBASS_TYPES_H

// Include Files
#include "rtwtypes.h"

// Type Definitions
typedef struct {
  int isInitialized;
  double yMinus1;
  double uMinus1;
  double K;
} audioexample_FullWaveIntegrator;

#ifndef struct_dsp_BiquadFilter_0
#define struct_dsp_BiquadFilter_0

struct dsp_BiquadFilter_0
{
  int S0_isInitialized;
  double W0_FILT_STATES[16];
  int W1_PreviousNumChannels;
  double P0_ICRTP;
};

#endif                                 //struct_dsp_BiquadFilter_0

typedef struct {
  int isInitialized;
  dsp_BiquadFilter_0 cSFunObject;
} dspcodegen_BiquadFilter;

typedef struct {
  int isInitialized;
  boolean_T TunablePropsChanged;
  double PrivateSampleRate;
  double LowCutoff;
  double HighCutoff;
  double Num[24];
  double Den[16];
  dspcodegen_BiquadFilter SOSObj;
  boolean_T AreFiltersDesigned;
  double pHighSlopeNumeric;
  double pLowSlopeNumeric;
} c_audiopluginexample_VarSlopeBa;

typedef struct {
  int isInitialized;
  boolean_T TunablePropsChanged;
  double CrossoverFrequencies;
  double CrossoverOrders;
  double SampleRate;
  double pCR1_B_LP[12];
  double pCR1_A_LP[12];
  double pCR1_B_HP[12];
  double pCR1_A_HP[12];
  double pPhaseMult;
  double pCR1_States_LP[16];
  double pCR1_States_HP[16];
} c_audio_internal_TwoBandCrossov;

typedef struct {
  int isInitialized;
  boolean_T TunablePropsChanged;
  unsigned int inputVarSize1[8];
  double pSampleRateDialog;
  double pOrders;
  double pCrossoverFrequencies;
  double pNumChannels;
  double pFreq[4];
  double pSlopes[4];
  c_audio_internal_TwoBandCrossov pFilter;
} crossoverFilter;

#ifndef struct_dsp_FIRFilter_1
#define struct_dsp_FIRFilter_1

struct dsp_FIRFilter_1
{
  int S0_isInitialized;
  double P0_InitialStates;
  double P1_Coefficients;
};

#endif                                 //struct_dsp_FIRFilter_1

typedef struct {
  int isInitialized;
  dsp_FIRFilter_1 cSFunObject;
  double Numerator;
} dspcodegen_FIRFilter;

typedef struct {
  double PrivateSampleRate;
  int isInitialized;
  boolean_T TunablePropsChanged;
  double BPUpperCutoff;
  double Gain;
  crossoverFilter pCrossover;
  audioexample_FullWaveIntegrator pIntegrator;
  c_audiopluginexample_VarSlopeBa pFilter;
  dspcodegen_FIRFilter pGainFilter;
} audiopluginexample_BassEnhancer;

typedef struct {
  unsigned int chunks[2];
} uint64m_T;

typedef struct {
  audiopluginexample_BassEnhancer bassEnhancer;
  boolean_T bassEnhancer_not_empty;
  uint64m_T thisPtr;
} PsychoBassPersistentData;

typedef struct {
  PsychoBassPersistentData *pd;
} PsychoBassStackData;

#endif

//
// File trailer for PsychoBass_types.h
//
// [EOF]
//
