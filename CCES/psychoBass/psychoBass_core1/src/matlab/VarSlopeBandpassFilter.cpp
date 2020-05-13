//
// File: VarSlopeBandpassFilter.cpp
//
// MATLAB Coder version            : 3.1
// C/C++ source code generated on  : 13-May-2020 13:38:55
//

// Include Files
#include "rt_nonfinite.h"
#include "PsychoBass.h"
#include "VarSlopeBandpassFilter.h"
#include <stdio.h>

// Function Definitions

//
// Arguments    : c_audiopluginexample_VarSlopeBa *plugin
//                double val
// Return Type  : void
//
void c_VarSlopeBandpassFilter_set_Hi(c_audiopluginexample_VarSlopeBa *plugin,
  double val)
{
  c_audiopluginexample_VarSlopeBa *b_plugin;
  plugin->HighCutoff = val;
  b_plugin = plugin;
  b_plugin->AreFiltersDesigned = false;
}

//
// File trailer for VarSlopeBandpassFilter.cpp
//
// [EOF]
//
