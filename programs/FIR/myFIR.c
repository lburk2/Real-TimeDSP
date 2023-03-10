/*
 * myFIR.c
 *
 *  Created on: Feb 15, 2023
 *      Author: Landon Burk, Tess Jisa, Evan Cornwell
 */

#include "stdio.h"
#include "stdint.h"



void myFIR(int16_t* x, const int16_t* restrict  h, int16_t* y, int16_t* restrict delayLine, uint16_t nx, uint16_t nh)
{
	//copy new samples into delayLine
	int40_t sum = 0x4000;
	uint16_t i = 0;

	for(i=nh-1; i>0;i--)
		delayLine[i]=delayLine[i-1];

	delayLine[0] = *x;

	//Filter

	#pragma MUST_ITERATE(2,,2) //commented out for the first part
	for(i = 0; i < nh; i++)
		sum = _smac(sum, (int)delayLine[i], (int)h[i]);

	//output results

	*y = sum>>15;


	//in debug, tools, save memory can specify that we want output buffer saved

}

//void fir(int16_t* x, int16_t* restrict  h, int16_t* y, int16_t* restrict d, uint16_t nx, uint16_t nh)
//{
//	/*
//	 * delay line is irregular, must be length nh-1+nx
//	 */
//	int i, k;
//	int32_t sum;
//	//move past nh-1 samples to top of delayline
//	for(i=0;i<nh-1;i++)
//	{
//		d[i]=d[i+nx];
//
//	}
//	//copy nx new samples to bottom of delayline
//	for(i=0;i<nx,i++)
//	{
//		d[i+nh-1]=x[i];
//	}
//	//perform FIR filter
//	for(i=0;i<nx;i++)
//	{
//		sum = 0x4000;
//	#pragma SP_LOOP(2, ,2) //will run minimum 2 times will have maximum 2 iterations?
//		for(k=0;k<nh;k++)
//		{
//			sum=_smpy(sum, h[k], d[k+i])
//		}
//		y[i]=sum >> 15;
//	}
//}
//
//
//
//
