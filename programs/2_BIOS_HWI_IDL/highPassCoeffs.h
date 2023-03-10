/*
 * Filter Coefficients (C Source) generated by the Filter Design and Analysis Tool
 * Generated by MATLAB(R) 9.12 and Signal Processing Toolbox 9.0.
 * Generated on: 05-Mar-2023 14:35:29
 */

/*
 * Discrete-Time FIR Filter (real)
 * -------------------------------
 * Filter Structure  : Direct-Form FIR
 * Filter Length     : 67
 * Stable            : Yes
 * Linear Phase      : Yes (Type 1)
 * Stop 2kHz, Pass 4kHz
 */

/* General type conversion for MATLAB generated C-code  */

/* 
 * Expected path to tmwtypes.h 
 * C:\Program Files\MATLAB\R2022a\extern\include\tmwtypes.h 
 */
/*
 * Warning - Filter coefficients were truncated to fit specified data type.  
 *   The resulting response may not match generated theoretical response.
 *   Use the Filter Design & Analysis Tool to design accurate
 *   int32 filter coefficients.
 */
const int BL = 67;
const int32_t highPassCoeffs[67] = {
      20351818,   -16663936,   -11388645,    -7277414,    -3356635,      843037,
       5203823,     9168877,    11860876,    12420619,    10212385,     5139933,
      -2310074,   -10921706,   -18964755,   -24417557,   -25543959,   -21043470,
     -10667958,     4567864,    22493935,    39768758,    52514201,    56785075,
      49347226,    28274897,    -6515419,   -53089212,  -107565099,  -164546728,
    -217823816,  -261254020,  -289645740,  1847980605,  -289645740,  -261254020,
    -217823816,  -164546728,  -107565099,   -53089212,    -6515419,    28274897,
      49347226,    56785075,    52514201,    39768758,    22493935,     4567864,
     -10667958,   -21043470,   -25543959,   -24417557,   -18964755,   -10921706,
      -2310074,     5139933,    10212385,    12420619,    11860876,     9168877,
       5203823,      843037,    -3356635,    -7277414,   -11388645,   -16663936,
      20351818
};
