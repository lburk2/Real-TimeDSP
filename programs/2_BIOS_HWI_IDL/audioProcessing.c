
#include <std.h>

#include <log.h>

#include "hellocfg.h"
#include "ezdsp5502.h"
#include "stdint.h"
#include "aic3204.h"
#include "ezdsp5502_mcbsp.h"
#include "csl_mcbsp.h"

#include "myFIR.h"
#include "myNCO.h"
#include "demo_filt.h"
#include "highPassCoeffs.h"
//#include "main.c"

extern MCBSP_Handle aicMcbsp;

int16_t rxRightSample;
int16_t rxLeftSample;
int16_t leftRightFlag = 0;
int16_t txleftRightFlag = 0;
int16_t output=0;

extern int filterMode;
extern int NCO;//sorry about bool landon
extern int switch1_prev;
extern int switch0;
extern int switch1;
extern int16_t* restrict fir1_delayLineptr;
extern int16_t* restrict fir1_delayLine;
//extern const int16_t demoFilter[];
extern const int16_t* restrict demoFilterptr;
//const int16_t* restrict highPassCoeffs;

//highPassCoeffsptr=highPassCoeffs;

void audioProcessingInit(void)
{
	rxRightSample = 0;
	rxLeftSample = 0;
}


void HWI_I2S_Rx(void)
{
	if (leftRightFlag == 0)
	{
		rxLeftSample = MCBSP_read16(aicMcbsp);
		leftRightFlag = 1;
	}
	else
	{
		rxRightSample = MCBSP_read16(aicMcbsp);
		leftRightFlag = 0;
	}
}

void HWI_I2S_Tx(void)
{
//	if(NCO)
//	{
//		int i;
//		for(i=0;i<24000;i++)
//		{
//			output=nco_run_sinusoid(); //then have to change bottom to output just the tone
//			MCBSP_write16(aicMcbsp,output);
//		}
//		NCO=0;
//	}

//		datOutput[k] = *testVectorOutput;


	switch(filterMode){
	case 0:

		break;
	case 1:
		fir((int16_t*)rxLeftSample,
			(int16_t*) demoFilter, //demoFilterptr,
			(int16_t*)rxLeftSample,
			fir1_delayLineptr,
			1,
			68);
		break;
//	case 2:
//		fir((int16_t*)&dataLeft,
//			demoFilterptr,
//			testVectorOutput,
//			fir1_delayLineptr,
//			1,
//			NH);
//		break;

	}

	if (txleftRightFlag == 0)
	{
		MCBSP_write16(aicMcbsp,rxLeftSample);
		//aic3204_output_sample(*testVectorOutput, *testVectorOutput); //perhaps use this instead?? not sure yet
		txleftRightFlag = 1;
	}
	else
	{
		MCBSP_write16(aicMcbsp,rxRightSample);
		txleftRightFlag = 0;
	}
}



