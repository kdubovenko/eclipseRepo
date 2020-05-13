//
// File: xzgeev.cpp
//
// MATLAB Coder version            : 3.1
// C/C++ source code generated on  : 13-May-2020 13:38:55
//

// Include Files
#include "rt_nonfinite.h"
#include "PsychoBass.h"
#include "xzgeev.h"
#include "xzhgeqz.h"
#include "xzlartg.h"
#include "sqrt1.h"
#include "PsychoBass_rtwutil.h"
#include <stdio.h>

// Function Definitions

//
// Arguments    : const creal_T A_data[]
//                const int A_size[2]
//                int *info
//                creal_T alpha1_data[]
//                int alpha1_size[1]
//                creal_T beta1_data[]
//                int beta1_size[1]
// Return Type  : void
//
void xzgeev(const creal_T A_data[], const int A_size[2], int *info, creal_T
            alpha1_data[], int alpha1_size[1], creal_T beta1_data[], int
            beta1_size[1])
{
  int At_size[2];
  int ii;
  int i8;
  creal_T At_data[16];
  double anrm;
  boolean_T exitg7;
  double absxk;
  boolean_T ilascl;
  double anrmto;
  int ilo;
  double ctoc;
  int ihi;
  boolean_T notdone;
  int exitg2;
  double stemp_im;
  int i;
  double cto1;
  int j;
  double mul;
  boolean_T exitg5;
  int nzcount;
  creal_T atmp;
  int jj;
  boolean_T exitg6;
  creal_T b_A_data[16];
  int exitg1;
  boolean_T guard2 = false;
  boolean_T exitg3;
  boolean_T exitg4;
  boolean_T guard1 = false;
  At_size[0] = A_size[0];
  At_size[1] = A_size[1];
  ii = A_size[0] * A_size[1];
  for (i8 = 0; i8 < ii; i8++) {
    At_data[i8] = A_data[i8];
  }

  *info = 0;
  anrm = 0.0;
  i8 = A_size[0] * A_size[1];
  ii = 0;
  exitg7 = false;
  while ((!exitg7) && (ii <= i8 - 1)) {
    absxk = rt_hypotd_snf(A_data[ii].re, A_data[ii].im);
    if (rtIsNaN(absxk)) {
      anrm = rtNaN;
      exitg7 = true;
    } else {
      if (absxk > anrm) {
        anrm = absxk;
      }

      ii++;
    }
  }

  if (!((!rtIsInf(anrm)) && (!rtIsNaN(anrm)))) {
    alpha1_size[0] = A_size[0];
    ii = A_size[0];
    for (i8 = 0; i8 < ii; i8++) {
      alpha1_data[i8].re = rtNaN;
      alpha1_data[i8].im = 0.0;
    }

    beta1_size[0] = A_size[0];
    ii = A_size[0];
    for (i8 = 0; i8 < ii; i8++) {
      beta1_data[i8].re = rtNaN;
      beta1_data[i8].im = 0.0;
    }
  } else {
    ilascl = false;
    anrmto = anrm;
    if ((anrm > 0.0) && (anrm < 6.7178761075670888E-139)) {
      anrmto = 6.7178761075670888E-139;
      ilascl = true;
    } else {
      if (anrm > 1.4885657073574029E+138) {
        anrmto = 1.4885657073574029E+138;
        ilascl = true;
      }
    }

    if (ilascl) {
      absxk = anrm;
      ctoc = anrmto;
      notdone = true;
      while (notdone) {
        stemp_im = absxk * 2.0041683600089728E-292;
        cto1 = ctoc / 4.9896007738368E+291;
        if ((stemp_im > ctoc) && (ctoc != 0.0)) {
          mul = 2.0041683600089728E-292;
          absxk = stemp_im;
        } else if (cto1 > absxk) {
          mul = 4.9896007738368E+291;
          ctoc = cto1;
        } else {
          mul = ctoc / absxk;
          notdone = false;
        }

        ii = At_size[0] * At_size[1];
        for (i8 = 0; i8 < ii; i8++) {
          At_data[i8].re *= mul;
          At_data[i8].im *= mul;
        }
      }
    }

    ilo = 0;
    ihi = A_size[0];
    if (A_size[0] <= 1) {
      ihi = 1;
    } else {
      do {
        exitg2 = 0;
        i = 0;
        j = 0;
        notdone = false;
        ii = ihi;
        exitg5 = false;
        while ((!exitg5) && (ii > 0)) {
          nzcount = 0;
          i = ii;
          j = ihi;
          jj = 1;
          exitg6 = false;
          while ((!exitg6) && (jj <= ihi)) {
            guard2 = false;
            if ((At_data[(ii + At_size[0] * (jj - 1)) - 1].re != 0.0) ||
                (At_data[(ii + At_size[0] * (jj - 1)) - 1].im != 0.0) || (ii ==
                 jj)) {
              if (nzcount == 0) {
                j = jj;
                nzcount = 1;
                guard2 = true;
              } else {
                nzcount = 2;
                exitg6 = true;
              }
            } else {
              guard2 = true;
            }

            if (guard2) {
              jj++;
            }
          }

          if (nzcount < 2) {
            notdone = true;
            exitg5 = true;
          } else {
            ii--;
          }
        }

        if (!notdone) {
          exitg2 = 2;
        } else {
          nzcount = At_size[0];
          jj = At_size[1];
          ii = At_size[0] * At_size[1];
          for (i8 = 0; i8 < ii; i8++) {
            b_A_data[i8] = At_data[i8];
          }

          if (i != ihi) {
            for (ii = 0; ii + 1 <= At_size[0]; ii++) {
              atmp = b_A_data[(i + nzcount * ii) - 1];
              b_A_data[(i + nzcount * ii) - 1] = b_A_data[(ihi + nzcount * ii) -
                1];
              b_A_data[(ihi + nzcount * ii) - 1] = atmp;
            }
          }

          if (j != ihi) {
            for (ii = 0; ii + 1 <= ihi; ii++) {
              atmp = b_A_data[ii + nzcount * (j - 1)];
              b_A_data[ii + nzcount * (j - 1)] = b_A_data[ii + nzcount * (ihi -
                1)];
              b_A_data[ii + nzcount * (ihi - 1)] = atmp;
            }
          }

          ii = nzcount * jj;
          for (i8 = 0; i8 < ii; i8++) {
            At_data[i8] = b_A_data[i8];
          }

          ihi--;
          if (ihi == 1) {
            exitg2 = 1;
          }
        }
      } while (exitg2 == 0);

      if (exitg2 == 1) {
      } else {
        do {
          exitg1 = 0;
          i = 0;
          j = 0;
          notdone = false;
          jj = ilo + 1;
          exitg3 = false;
          while ((!exitg3) && (jj <= ihi)) {
            nzcount = 0;
            i = ihi;
            j = jj;
            ii = ilo + 1;
            exitg4 = false;
            while ((!exitg4) && (ii <= ihi)) {
              guard1 = false;
              if ((At_data[(ii + At_size[0] * (jj - 1)) - 1].re != 0.0) ||
                  (At_data[(ii + At_size[0] * (jj - 1)) - 1].im != 0.0) || (ii ==
                   jj)) {
                if (nzcount == 0) {
                  i = ii;
                  nzcount = 1;
                  guard1 = true;
                } else {
                  nzcount = 2;
                  exitg4 = true;
                }
              } else {
                guard1 = true;
              }

              if (guard1) {
                ii++;
              }
            }

            if (nzcount < 2) {
              notdone = true;
              exitg3 = true;
            } else {
              jj++;
            }
          }

          if (!notdone) {
            exitg1 = 1;
          } else {
            nzcount = At_size[0];
            jj = At_size[1];
            ii = At_size[0] * At_size[1];
            for (i8 = 0; i8 < ii; i8++) {
              b_A_data[i8] = At_data[i8];
            }

            if (i != ilo + 1) {
              for (ii = ilo; ii + 1 <= At_size[0]; ii++) {
                atmp = b_A_data[(i + nzcount * ii) - 1];
                b_A_data[(i + nzcount * ii) - 1] = b_A_data[ilo + nzcount * ii];
                b_A_data[ilo + nzcount * ii] = atmp;
              }
            }

            if (j != ilo + 1) {
              for (ii = 0; ii + 1 <= ihi; ii++) {
                atmp = b_A_data[ii + nzcount * (j - 1)];
                b_A_data[ii + nzcount * (j - 1)] = b_A_data[ii + nzcount * ilo];
                b_A_data[ii + nzcount * ilo] = atmp;
              }
            }

            ii = nzcount * jj;
            for (i8 = 0; i8 < ii; i8++) {
              At_data[i8] = b_A_data[i8];
            }

            ilo++;
            if (ilo + 1 == ihi) {
              exitg1 = 1;
            }
          }
        } while (exitg1 == 0);
      }
    }

    if ((At_size[0] <= 1) || (ihi < ilo + 3)) {
    } else {
      for (ii = ilo; ii + 1 < ihi - 1; ii++) {
        for (nzcount = ihi - 1; nzcount + 1 > ii + 2; nzcount--) {
          xzlartg(At_data[(nzcount + At_size[0] * ii) - 1], At_data[nzcount +
                  At_size[0] * ii], &absxk, &atmp, &At_data[(nzcount + At_size[0]
                   * ii) - 1]);
          At_data[nzcount + At_size[0] * ii].re = 0.0;
          At_data[nzcount + At_size[0] * ii].im = 0.0;
          for (j = ii + 1; j + 1 <= At_size[0]; j++) {
            ctoc = absxk * At_data[(nzcount + At_size[0] * j) - 1].re + (atmp.re
              * At_data[nzcount + At_size[0] * j].re - atmp.im * At_data[nzcount
              + At_size[0] * j].im);
            stemp_im = absxk * At_data[(nzcount + At_size[0] * j) - 1].im +
              (atmp.re * At_data[nzcount + At_size[0] * j].im + atmp.im *
               At_data[nzcount + At_size[0] * j].re);
            cto1 = At_data[(nzcount + At_size[0] * j) - 1].re;
            At_data[nzcount + At_size[0] * j].re = absxk * At_data[nzcount +
              At_size[0] * j].re - (atmp.re * At_data[(nzcount + At_size[0] * j)
              - 1].re + atmp.im * At_data[(nzcount + At_size[0] * j) - 1].im);
            At_data[nzcount + At_size[0] * j].im = absxk * At_data[nzcount +
              At_size[0] * j].im - (atmp.re * At_data[(nzcount + At_size[0] * j)
              - 1].im - atmp.im * cto1);
            At_data[(nzcount + At_size[0] * j) - 1].re = ctoc;
            At_data[(nzcount + At_size[0] * j) - 1].im = stemp_im;
          }

          atmp.re = -atmp.re;
          atmp.im = -atmp.im;
          for (i = 0; i + 1 <= ihi; i++) {
            ctoc = absxk * At_data[i + At_size[0] * nzcount].re + (atmp.re *
              At_data[i + At_size[0] * (nzcount - 1)].re - atmp.im * At_data[i +
              At_size[0] * (nzcount - 1)].im);
            stemp_im = absxk * At_data[i + At_size[0] * nzcount].im + (atmp.re *
              At_data[i + At_size[0] * (nzcount - 1)].im + atmp.im * At_data[i +
              At_size[0] * (nzcount - 1)].re);
            cto1 = At_data[i + At_size[0] * nzcount].re;
            At_data[i + At_size[0] * (nzcount - 1)].re = absxk * At_data[i +
              At_size[0] * (nzcount - 1)].re - (atmp.re * At_data[i + At_size[0]
              * nzcount].re + atmp.im * At_data[i + At_size[0] * nzcount].im);
            At_data[i + At_size[0] * (nzcount - 1)].im = absxk * At_data[i +
              At_size[0] * (nzcount - 1)].im - (atmp.re * At_data[i + At_size[0]
              * nzcount].im - atmp.im * cto1);
            At_data[i + At_size[0] * nzcount].re = ctoc;
            At_data[i + At_size[0] * nzcount].im = stemp_im;
          }
        }
      }
    }

    xzhgeqz(At_data, At_size, ilo + 1, ihi, info, alpha1_data, alpha1_size,
            beta1_data, beta1_size);
    if ((*info != 0) || (!ilascl)) {
    } else {
      notdone = true;
      while (notdone) {
        stemp_im = anrmto * 2.0041683600089728E-292;
        cto1 = anrm / 4.9896007738368E+291;
        if ((stemp_im > anrm) && (anrm != 0.0)) {
          mul = 2.0041683600089728E-292;
          anrmto = stemp_im;
        } else if (cto1 > anrmto) {
          mul = 4.9896007738368E+291;
          anrm = cto1;
        } else {
          mul = anrm / anrmto;
          notdone = false;
        }

        ii = alpha1_size[0];
        for (i8 = 0; i8 < ii; i8++) {
          alpha1_data[i8].re *= mul;
          alpha1_data[i8].im *= mul;
        }
      }
    }
  }
}

//
// File trailer for xzgeev.cpp
//
// [EOF]
//
