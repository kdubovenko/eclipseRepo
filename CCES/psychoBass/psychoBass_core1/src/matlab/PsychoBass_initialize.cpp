//
// File: PsychoBass_initialize.cpp
//
// MATLAB Coder version            : 3.1
// C/C++ source code generated on  : 13-May-2020 13:38:55
//

// Include Files
#include "rt_nonfinite.h"
#include "PsychoBass.h"
#include "PsychoBass_initialize.h"
#include "audioPlugin.h"
#include <stdio.h>

// Function Definitions

//
// Arguments    : PsychoBassStackData *SD
// Return Type  : void
//
void PsychoBass_initialize(PsychoBassStackData *SD)
{
  rt_InitInfAndNaN(8U);
  bassEnhancer_not_empty_init(SD);
  c_audioPlugin_wormholeToConstru(SD);
}

//
// File trailer for PsychoBass_initialize.cpp
//
// [EOF]
//
