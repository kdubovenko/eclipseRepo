//
// File: SystemCore.h
//
// MATLAB Coder version            : 3.1
// C/C++ source code generated on  : 13-May-2020 13:38:55
//
#ifndef SYSTEMCORE_H
#define SYSTEMCORE_H

// Include Files
#include <float.h>
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rt_defines.h"
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "PsychoBass_types.h"

// Function Declarations
extern void SystemCore_setup(c_audio_internal_TwoBandCrossov *obj);
extern void SystemCore_setupAndReset(audiopluginexample_BassEnhancer *obj);
extern void SystemCore_step(crossoverFilter *obj, const double varargin_1[64],
  double varargout_1[64], double varargout_2[64]);

#endif

//
// File trailer for SystemCore.h
//
// [EOF]
//
