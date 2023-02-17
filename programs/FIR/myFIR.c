/*
 * myFIR.c
 *
 *  Created on: Feb 15, 2023
 *      Author: Landon Burk, Tess Jisa, Evan Cornwell
 */

#include "stdio.h"
#include "stdint.h"



void myFIR(int16_t* x, int16_t* h, int16_t* y, int16_t* delayLine, uint16_t nx, uint16_t nh)
{
	//copy new samples into delayLine
	int40_t sum = 0;
	int i,j;

	for(i=nh-1; i>0;i--)
	{
		delayLine[i]=delayLine[i-1];
	}
	*delayLine[0]= &x;

	//Filter
	//#pragma MUST_ITERATE(2,,2) //commented out for the first part
	for(j = 0; j<nh;j++)
	{
		sum = _smac(sum, (int)delayLine[j], (int)&h[j]);
	}

	//output results

	*y = sum>>15;
	//in debug, tools, save memory can specify that we want output buffer saved

}




