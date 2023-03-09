
#include <std.h>

#include <log.h>

#include "hellocfg.h"
#include "ezdsp5502.h"
#include "stdint.h"
#include "aic3204.h"
#include "ezdsp5502_mcbsp.h"
#include "csl_mcbsp.h"

extern MCBSP_Handle aicMcbsp;

int16_t rxRightSample;
int16_t rxLeftSample;
int16_t leftRightFlag = 0;
int16_t txleftRightFlag = 0;

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
	if(NC0)
	{
		output=nco_run_sinusoid() //then have to change bottom to output just the tone
	}

	if(filterMode==2)
	{
		fir((int16_t*)&dataLeft,
			demoFilterptr,
			testVectorOutput,
			fir1_delayLineptr,
			1,
			NH);
		datOutput[k] = *testVectorOutput;
	}
	if(filterMode==1)
	{

	}


	if (txleftRightFlag == 0)
	{
		MCBSP_write16(aicMcbsp,rxLeftSample);
		aic3204_output_sample(*testVectorOutput, *testVectorOutput); //perhaps use this instead?? not sure yet
		txleftRightFlag = 1;
	}
	else
	{
		MCBSP_write16(aicMcbsp,rxRightSample);
		txleftRightFlag = 0;
	}
}



