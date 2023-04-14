/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: FFT_data.c
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

/* Constant parameters (default storage) */
const ConstP_FFT_T FFT_ConstP = {
  /* Computed Parameter: FFT_TwiddleTable
   * Referenced by: '<Root>/FFT'
   */
  { 1.0F, 0.99879545F, 0.99518472F, 0.989176512F, 0.980785251F, 0.970031261F,
    0.956940353F, 0.941544056F, 0.923879504F, 0.903989315F, 0.881921291F,
    0.857728601F, 0.831469595F, 0.803207517F, 0.773010433F, 0.740951121F,
    0.707106769F, 0.671559F, 0.634393275F, 0.59569931F, 0.555570245F,
    0.514102757F, 0.471396744F, 0.427555084F, 0.382683426F, 0.336889863F,
    0.290284663F, 0.242980182F, 0.195090324F, 0.146730468F, 0.0980171412F,
    0.0490676761F, 6.12323426E-17F, -0.0490676761F, -0.0980171412F,
    -0.146730468F, -0.195090324F, -0.242980182F, -0.290284663F, -0.336889863F,
    -0.382683426F, -0.427555084F, -0.471396744F, -0.514102757F, -0.555570245F,
    -0.59569931F, -0.634393275F, -0.671559F, -0.707106769F, -0.740951121F,
    -0.773010433F, -0.803207517F, -0.831469595F, -0.857728601F, -0.881921291F,
    -0.903989315F, -0.923879504F, -0.941544056F, -0.956940353F, -0.970031261F,
    -0.980785251F, -0.989176512F, -0.99518472F, -0.99879545F, -1.0F,
    -0.99879545F, -0.99518472F, -0.989176512F, -0.980785251F, -0.970031261F,
    -0.956940353F, -0.941544056F, -0.923879504F, -0.903989315F, -0.881921291F,
    -0.857728601F, -0.831469595F, -0.803207517F, -0.773010433F, -0.740951121F,
    -0.707106769F, -0.671559F, -0.634393275F, -0.59569931F, -0.555570245F,
    -0.514102757F, -0.471396744F, -0.427555084F, -0.382683426F, -0.336889863F,
    -0.290284663F, -0.242980182F, -0.195090324F, -0.146730468F, -0.0980171412F,
    -0.0490676761F }
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
