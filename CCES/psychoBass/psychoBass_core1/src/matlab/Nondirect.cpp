//
// File: Nondirect.cpp
//
// MATLAB Coder version            : 3.1
// C/C++ source code generated on  : 13-May-2020 13:38:55
//

// Include Files
#include "rt_nonfinite.h"
#include "PsychoBass.h"
#include "Nondirect.h"
#include <stdio.h>

// Function Definitions

//
// Arguments    : dspcodegen_BiquadFilter *obj
//                const double varargin_1[32]
//                const double varargin_2[24]
//                const double varargin_3[16]
//                double varargout_1[32]
// Return Type  : void
//
void Nondirect_stepImpl(dspcodegen_BiquadFilter *obj, const double varargin_1[32],
  const double varargin_2[24], const double varargin_3[16], double varargout_1
  [32])
{
  dspcodegen_BiquadFilter *b_obj;
  dsp_BiquadFilter_0 *c_obj;
  int ioIdx;
  int i;
  double numAccum;
  double stageOut;
  double stageIn;
  b_obj = obj;
  c_obj = &b_obj->cSFunObject;

  // System object Outputs function: dsp.BiquadFilter
  ioIdx = 0;
  for (i = 0; i < 32; i++) {
    numAccum = c_obj->W0_FILT_STATES[0];
    numAccum += varargin_2[0] * varargin_1[ioIdx];
    stageOut = numAccum;
    numAccum = c_obj->W0_FILT_STATES[1];
    numAccum += varargin_2[1] * varargin_1[ioIdx];
    c_obj->W0_FILT_STATES[0] = numAccum - varargin_3[0] * stageOut;
    c_obj->W0_FILT_STATES[1] = varargin_2[2] * varargin_1[ioIdx] - varargin_3[1]
      * stageOut;
    stageIn = stageOut;
    numAccum = c_obj->W0_FILT_STATES[2];
    numAccum += varargin_2[3] * stageOut;
    stageOut = numAccum;
    numAccum = c_obj->W0_FILT_STATES[3];
    numAccum += varargin_2[4] * stageIn;
    c_obj->W0_FILT_STATES[2] = numAccum - varargin_3[2] * stageOut;
    c_obj->W0_FILT_STATES[3] = varargin_2[5] * stageIn - varargin_3[3] *
      stageOut;
    stageIn = stageOut;
    numAccum = c_obj->W0_FILT_STATES[4];
    numAccum += varargin_2[6] * stageOut;
    stageOut = numAccum;
    numAccum = c_obj->W0_FILT_STATES[5];
    numAccum += varargin_2[7] * stageIn;
    c_obj->W0_FILT_STATES[4] = numAccum - varargin_3[4] * stageOut;
    c_obj->W0_FILT_STATES[5] = varargin_2[8] * stageIn - varargin_3[5] *
      stageOut;
    stageIn = stageOut;
    numAccum = c_obj->W0_FILT_STATES[6];
    numAccum += varargin_2[9] * stageOut;
    stageOut = numAccum;
    numAccum = c_obj->W0_FILT_STATES[7];
    numAccum += varargin_2[10] * stageIn;
    c_obj->W0_FILT_STATES[6] = numAccum - varargin_3[6] * stageOut;
    c_obj->W0_FILT_STATES[7] = varargin_2[11] * stageIn - varargin_3[7] *
      stageOut;
    stageIn = stageOut;
    numAccum = c_obj->W0_FILT_STATES[8];
    numAccum += varargin_2[12] * stageOut;
    stageOut = numAccum;
    numAccum = c_obj->W0_FILT_STATES[9];
    numAccum += varargin_2[13] * stageIn;
    c_obj->W0_FILT_STATES[8] = numAccum - varargin_3[8] * stageOut;
    c_obj->W0_FILT_STATES[9] = varargin_2[14] * stageIn - varargin_3[9] *
      stageOut;
    stageIn = stageOut;
    numAccum = c_obj->W0_FILT_STATES[10];
    numAccum += varargin_2[15] * stageOut;
    stageOut = numAccum;
    numAccum = c_obj->W0_FILT_STATES[11];
    numAccum += varargin_2[16] * stageIn;
    c_obj->W0_FILT_STATES[10] = numAccum - varargin_3[10] * stageOut;
    c_obj->W0_FILT_STATES[11] = varargin_2[17] * stageIn - varargin_3[11] *
      stageOut;
    stageIn = stageOut;
    numAccum = c_obj->W0_FILT_STATES[12];
    numAccum += varargin_2[18] * stageOut;
    stageOut = numAccum;
    numAccum = c_obj->W0_FILT_STATES[13];
    numAccum += varargin_2[19] * stageIn;
    c_obj->W0_FILT_STATES[12] = numAccum - varargin_3[12] * stageOut;
    c_obj->W0_FILT_STATES[13] = varargin_2[20] * stageIn - varargin_3[13] *
      stageOut;
    stageIn = stageOut;
    numAccum = c_obj->W0_FILT_STATES[14];
    numAccum += varargin_2[21] * stageOut;
    stageOut = numAccum;
    numAccum = c_obj->W0_FILT_STATES[15];
    numAccum += varargin_2[22] * stageIn;
    c_obj->W0_FILT_STATES[14] = numAccum - varargin_3[14] * stageOut;
    c_obj->W0_FILT_STATES[15] = varargin_2[23] * stageIn - varargin_3[15] *
      stageOut;
    varargout_1[ioIdx] = stageOut;
    ioIdx++;
  }
}

//
// File trailer for Nondirect.cpp
//
// [EOF]
//
