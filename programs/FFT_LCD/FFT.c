/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: FFT.c
 *
 * Code generated for Simulink model 'FFT'.
 *
 * Model version                  : 4.3
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Fri Apr  7 09:56:01 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C5000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "FFT.h"
#include "FFT_private.h"

extern const ConstP_FFT_T FFT_ConstP;
/* External inputs (root inport signals with default storage) */
ExtU_FFT_T FFT_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_FFT_T FFT_Y;

/* Real-time model */
static RT_MODEL_FFT_T FFT_M_;
RT_MODEL_FFT_T *const FFT_M = &FFT_M_;
void MWDSPCG_FFT_Interleave_R2BR_S(const real32_T x[], creal32_T y[], int32_T
  nChans, int32_T nRows)
{
  int32_T bit_fftLen;
  int32_T br_j;
  int32_T j;
  int32_T nChansBy2;
  int32_T uIdx;
  int32_T yIdx;

  /* S-Function (sdspfft2): '<Root>/FFT' */
  /* Bit-reverses the input data simultaneously with the interleaving operation,
     obviating the need for explicit data reordering later.  This requires an
     FFT with bit-reversed inputs.
   */
  br_j = 0L;
  yIdx = 0L;
  uIdx = 0L;
  for (nChansBy2 = nChans >> 1U; nChansBy2 != 0L; nChansBy2--) {
    for (j = nRows; j - 1L > 0L; j--) {
      bit_fftLen = yIdx + br_j;
      y[bit_fftLen].re = x[uIdx];
      y[bit_fftLen].im = x[uIdx + nRows];
      uIdx++;

      /* Compute next bit-reversed destination index */
      bit_fftLen = nRows;
      do {
        bit_fftLen = (int32_T)((uint32_T)bit_fftLen >> 1);
        br_j ^= bit_fftLen;
      } while ((uint32_T)(br_j & bit_fftLen) == 0UL);
    }

    bit_fftLen = yIdx + br_j;
    y[bit_fftLen].re = x[uIdx];
    br_j = uIdx + nRows;
    y[bit_fftLen].im = x[br_j];
    uIdx = br_j + 1L;
    yIdx += nRows << 1U;
    br_j = 0L;
  }

  /* For an odd number of channels, prepare the last channel
     for a double-length real signal algorithm.  No actual
     interleaving is required, just a copy of the last column
     of real data, but now placed in bit-reversed order.
     We need to cast the real u pointer to a cDType_T pointer,
     in order to fake the interleaving, and cut the number
     of elements in half (half as many complex interleaved
     elements as compared to real non-interleaved elements).
   */
  if (((uint16_T)nChans & 1U) != 0U) {
    for (j = nRows >> 1U; j - 1L > 0L; j--) {
      bit_fftLen = yIdx + br_j;
      y[bit_fftLen].re = x[uIdx];
      y[bit_fftLen].im = x[uIdx + 1L];
      uIdx += 2L;

      /* Compute next bit-reversed destination index */
      bit_fftLen = nRows >> 1U;
      do {
        bit_fftLen = (int32_T)((uint32_T)bit_fftLen >> 1);
        br_j ^= bit_fftLen;
      } while ((uint32_T)(br_j & bit_fftLen) == 0UL);
    }

    bit_fftLen = yIdx + br_j;
    y[bit_fftLen].re = x[uIdx];
    y[bit_fftLen].im = x[uIdx + 1L];
  }

  /* End of S-Function (sdspfft2): '<Root>/FFT' */
}

void MWDSPCG_R2DIT_TBLS_C(creal32_T y[], int32_T nChans, int32_T nRows, int32_T
  fftLen, int32_T offset, const real32_T tablePtr[], int32_T twiddleStep,
  boolean_T isInverse)
{
  int32_T i1;
  int32_T i2;
  int32_T iCh;
  int32_T idelta;
  int32_T istart;
  int32_T ix;
  int32_T j;
  int32_T k;
  int32_T kratio;
  int32_T nHalf;
  int32_T nQtr;
  int32_T offsetCh;
  real32_T tmp_im;
  real32_T tmp_re;
  real32_T twidIm;
  real32_T twidRe;
  int16_T fwdInvFactor;

  /* S-Function (sdspfft2): '<Root>/FFT' */
  /* DSP System Toolbox Decimation in Time FFT  */
  /* Computation performed using table lookup  */
  /* Output type: complex real32_T */
  nHalf = (fftLen >> 1U) * twiddleStep;
  nQtr = nHalf >> 1U;
  fwdInvFactor = isInverse ? -1 : 1;

  /* For each channel */
  offsetCh = offset;
  for (iCh = 0L; iCh < nChans; iCh++) {
    /* Perform butterflies for the first stage, where no multiply is required. */
    for (ix = offsetCh; ix < (fftLen + offsetCh) - 1L; ix += 2L) {
      tmp_re = y[ix + 1L].re;
      tmp_im = y[ix + 1L].im;
      y[ix + 1L].re = y[ix].re - y[ix + 1L].re;
      y[ix + 1L].im = y[ix].im - y[ix + 1L].im;
      y[ix].re += tmp_re;
      y[ix].im += tmp_im;
    }

    idelta = 2L;
    k = fftLen >> 2U;
    kratio = k * twiddleStep;
    while (k > 0L) {
      i1 = offsetCh;

      /* Perform the first butterfly in each remaining stage, where no multiply is required. */
      for (ix = 0L; ix < k; ix++) {
        i2 = i1 + idelta;
        tmp_re = y[i2].re;
        tmp_im = y[i2].im;
        y[i2].re = y[i1].re - y[i2].re;
        y[i2].im = y[i1].im - y[i2].im;
        y[i1].re += tmp_re;
        y[i1].im += tmp_im;
        i1 += idelta << 1U;
      }

      istart = offsetCh;

      /* Perform remaining butterflies */
      for (j = kratio; j < nHalf; j += kratio) {
        i1 = istart + 1L;
        twidRe = tablePtr[j];
        twidIm = tablePtr[j + nQtr] * (real32_T)fwdInvFactor;
        for (ix = 0L; ix < k; ix++) {
          i2 = i1 + idelta;
          tmp_re = y[i2].re * twidRe - y[i2].im * twidIm;
          tmp_im = y[i2].re * twidIm + y[i2].im * twidRe;
          y[i2].re = y[i1].re - tmp_re;
          y[i2].im = y[i1].im - tmp_im;
          y[i1].re += tmp_re;
          y[i1].im += tmp_im;
          i1 += idelta << 1U;
        }

        istart++;
      }

      idelta <<= 1U;
      k >>= 1U;
      kratio >>= 1U;
    }

    /* Point to next channel */
    offsetCh += nRows;
  }

  /* End of S-Function (sdspfft2): '<Root>/FFT' */
}

void MWDSPCG_FFT_DblLen_C(creal32_T y[], int32_T nChans, int32_T nRows, const
  real32_T twiddleTable[], int32_T twiddleStep)
{
  int32_T N2;
  int32_T N4;
  int32_T W4;
  int32_T ix;
  int32_T temp2Re_tmp;
  int32_T temp2Re_tmp_0;
  int32_T tempOut0Re_tmp;
  int32_T tmp;
  int32_T yIdx;
  real32_T cTemp_im;
  real32_T cTemp_re;
  real32_T cTemp_re_tmp;
  real32_T tempOut0Im;
  real32_T tempOut0Re;

  /* S-Function (sdspfft2): '<Root>/FFT' */
  /* In-place "double-length" data recovery
     Table-based mem-optimized twiddle computation

     Used to recover linear-ordered length-N point complex FFT result
     from a linear-ordered complex length-N/2 point FFT, performed
     on N interleaved real values.
   */
  N2 = nRows >> 1U;
  N4 = N2 >> 1U;
  W4 = N4 * twiddleStep;
  yIdx = (nChans - 1L) * nRows;
  if (nRows > 2L) {
    tempOut0Re_tmp = N4 + yIdx;
    tempOut0Re = y[tempOut0Re_tmp].re;
    tempOut0Im = y[tempOut0Re_tmp].im;
    tmp = (N2 + N4) + yIdx;
    y[tmp].re = tempOut0Re;
    y[tmp].im = tempOut0Im;
    y[tempOut0Re_tmp].re = tempOut0Re;
    y[tempOut0Re_tmp].im = -tempOut0Im;
  }

  if (nRows > 1L) {
    tmp = N2 + yIdx;
    y[tmp].re = y[yIdx].re - y[yIdx].im;
    y[tmp].im = 0.0F;
  }

  y[yIdx].re += y[yIdx].im;
  y[yIdx].im = 0.0F;
  tempOut0Re_tmp = twiddleStep;
  for (ix = 1L; ix < N4; ix++) {
    temp2Re_tmp = ix + yIdx;
    temp2Re_tmp_0 = (N2 - ix) + yIdx;
    tempOut0Re = (y[temp2Re_tmp_0].re + y[temp2Re_tmp].re) / 2.0F;
    tempOut0Im = (y[temp2Re_tmp].im - y[temp2Re_tmp_0].im) / 2.0F;
    cTemp_re_tmp = y[temp2Re_tmp_0].re;
    cTemp_re = y[temp2Re_tmp].re;
    y[temp2Re_tmp].re = (y[temp2Re_tmp_0].im + y[temp2Re_tmp].im) / 2.0F;
    y[temp2Re_tmp].im = (cTemp_re_tmp - cTemp_re) / 2.0F;
    cTemp_re_tmp = -twiddleTable[W4 - tempOut0Re_tmp];
    cTemp_re = y[temp2Re_tmp].re * twiddleTable[tempOut0Re_tmp] - cTemp_re_tmp *
      y[temp2Re_tmp].im;
    cTemp_im = y[temp2Re_tmp].im * twiddleTable[tempOut0Re_tmp] + cTemp_re_tmp *
      y[temp2Re_tmp].re;
    y[temp2Re_tmp].re = tempOut0Re + cTemp_re;
    y[temp2Re_tmp].im = tempOut0Im + cTemp_im;
    cTemp_re_tmp = y[temp2Re_tmp].im;
    tmp = (nRows - ix) + yIdx;
    y[tmp].re = y[temp2Re_tmp].re;
    y[tmp].im = -cTemp_re_tmp;
    tmp = (N2 + ix) + yIdx;
    y[tmp].re = tempOut0Re - cTemp_re;
    y[tmp].im = tempOut0Im - cTemp_im;
    cTemp_re_tmp = y[tmp].im;
    y[temp2Re_tmp_0].re = y[tmp].re;
    y[temp2Re_tmp_0].im = -cTemp_re_tmp;
    tempOut0Re_tmp += twiddleStep;
  }

  /* End of S-Function (sdspfft2): '<Root>/FFT' */
}

real32_T rt_hypotf_snf(real32_T u0, real32_T u1)
{
  real32_T a;
  real32_T y;
  a = (real32_T)fabs(u0);
  y = (real32_T)fabs(u1);
  if (a < y) {
    a /= y;
    y *= (real32_T)sqrt(a * a + 1.0F);
  } else if (a > y) {
    y /= a;
    y = (real32_T)sqrt(y * y + 1.0F) * a;
  } else {
    if (!rtIsNaNF(y)) {
      y = a * 1.41421354F;
    }
  }

  return y;
}

/* Model step function */
void FFT_step(void)
{
  creal32_T rtb_FFT[128];
  creal32_T *rtb_FFT_0;
  real32_T rtb_Abs[128];
  real32_T tmp;
  int16_T i;

  /* DataTypeConversion: '<Root>/Data Type Conversion' incorporates:
   *  Abs: '<Root>/Abs'
   *  Inport: '<Root>/In1'
   */
  for (i = 0; i < 128; i++) {
    rtb_Abs[i] = (real32_T)FFT_U.In1[i] * 3.05175781E-5F;
  }

  /* End of DataTypeConversion: '<Root>/Data Type Conversion' */

  /* S-Function (sdspfft2): '<Root>/FFT' incorporates:
   *  Abs: '<Root>/Abs'
   */
  MWDSPCG_FFT_Interleave_R2BR_S(&rtb_Abs[0UL], &rtb_FFT[0UL], 1L, 128L);
  MWDSPCG_R2DIT_TBLS_C(&rtb_FFT[0UL], 1L, 128L, 64L, 0L,
                       &FFT_ConstP.FFT_TwiddleTable[0UL], 2L, false);
  MWDSPCG_FFT_DblLen_C(&rtb_FFT[0UL], 1L, 128L, &FFT_ConstP.FFT_TwiddleTable[0UL],
                       1L);

  /* Scale inverse transformation */
  for (i = 0; i < 128; i++) {
    rtb_FFT[(int32_T)i].re /= 128.0F;
    rtb_FFT[(int32_T)i].im /= 128.0F;

    /* Abs: '<Root>/Abs' */
    rtb_FFT_0 = &rtb_FFT[i];

    /* DataTypeConversion: '<Root>/Data Type Conversion1' incorporates:
     *  Abs: '<Root>/Abs'
     */
    tmp = (real32_T)floor(rt_hypotf_snf(rtb_FFT_0->re, rtb_FFT_0->im) * 32768.0F);
    if (tmp < 32768.0F) {
      /* Outport: '<Root>/Out1' */
      FFT_Y.Out1[i] = (int16_T)tmp;
    } else {
      /* Outport: '<Root>/Out1' */
      FFT_Y.Out1[i] = MAX_int16_T;
    }

    /* End of DataTypeConversion: '<Root>/Data Type Conversion1' */
  }

  /* End of S-Function (sdspfft2): '<Root>/FFT' */
}

/* Model initialize function */
void FFT_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));
}

/* Model terminate function */
void FFT_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
