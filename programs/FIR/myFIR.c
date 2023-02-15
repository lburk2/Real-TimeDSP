/*
 * myFIR.c
 *
 *  Created on: Feb 15, 2023
 *      Author: Landon Burk, Tess Jisa, Evan Cornwell
 */

int16_t fir1_delayLine[62];
const int16_t fir1Coeffs[62] = {};

void myFIR(int16_t* x, int16_t* restrict h, int16_t* y, int16_t* restrict delayLine, uint16_t nx, uint16_t nh)
{
	//copy new samples into delayLine
		int40_t sum = 0;
	//Filter
	#pragma MUST_ITERATE(2,,2)
	//	for (i = 0; i <nx; i++){
			fpr(j = 0; j<nh;j++){
				sum += delayline[j]*h[j]
			}
	//	}
	//output results

	*y = sum>>15


}

