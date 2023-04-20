/*
 * Filter Coefficients (C Source) generated by the Filter Design and Analysis Tool
 * Generated by MATLAB(R) 9.12 and Signal Processing Toolbox 9.0.
 * Generated on: 09-Mar-2023 23:30:57
 */

/*
 * Discrete-Time FIR Filter (real)
 * -------------------------------
 * Filter Structure  : Direct-Form FIR
 * Filter Length     : 67
 * Stable            : Yes
 * Linear Phase      : Yes (Type 1)
 */

/* General type conversion for MATLAB generated C-code  */
//#include "tmwtypes.h"
/* 
 * Expected path to tmwtypes.h 
 * C:\Program Files\MATLAB\R2022a\extern\include\tmwtypes.h 
 */
/*
 * Warning - Filter coefficients were truncated to fit specified data type.  
 *   The resulting response may not match generated theoretical response.
 *   Use the Filter Design & Analysis Tool to design accurate
 *   int16 filter coefficients.
 */
const int BL = 67;
const int16_t highPass[67] = {
      311,   -254,   -174,   -111,    -51,     13,     79,    140,    181,
      190,    156,     78,    -35,   -167,   -289,   -373,   -390,   -321,
     -163,     70,    343,    607,    801,    866,    753,    431,    -99,
     -810,  -1641,  -2511,  -3324,  -3986,  -4420,  28198,  -4420,  -3986,
    -3324,  -2511,  -1641,   -810,    -99,    431,    753,    866,    801,
      607,    343,     70,   -163,   -321,   -390,   -373,   -289,   -167,
      -35,     78,    156,    190,    181,    140,     79,     13,    -51,
     -111,   -174,   -254,    311
};
