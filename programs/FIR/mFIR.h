/*
 * mFIR.h
 *
 *  Created on: Feb 15, 2023
 *      Author: Landon Burk, Tess Jisa, Evan Cornwell
 */

#ifndef MFIR_H_
#define MFIR_H_

void myFIR(int16_t* x, int16_t* restrict h, int16_t* y, int16_t* restrict delayLine, uint16_t nx, uint16_t nh);



#endif /* MFIR_H_ */
