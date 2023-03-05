/*
 * mFIR.h
 *
 *  Created on: Feb 15, 2023
 *      Author: Landon Burk, Tess Jisa, Evan Cornwell
 */


//void myFIR(int16_t* x, const int16_t* restrict h, int16_t* y, int16_t* restrict delayLine, uint16_t nx, uint16_t nh);
void davesFIR(int16_t* x, int16_t* restrict  h, int16_t* y, int16_t* restrict d, uint16_t nx, uint16_t nh);
