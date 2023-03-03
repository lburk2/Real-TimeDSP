
#include <std.h>

#include <log.h>

#include "hellocfg.h"
#include "ezdsp5502.h"
#include "stdint.h"
#include "aic3204.h"
#include "ezdsp5502_mcbsp.h"
#include "csl_mcbsp.h"

extern MCBSP_Handle aicMcbsp;


/* Global Vars for Processing */

volatile int16_t inSample;
volatile int16_t outSample;

void audioProcessingInit(void)
{
	inSample = 0;
	outSample = 0;
}

void SWI_AudioProc(void)
{
	outSample = inSample;
}

void HWI_I2S_Rx(void){

	EZDSP5502_MCBSP_read((Int16*)&inSample);
	SWI_post(&SWI_Audio);
}

void HWI_I2S_Tx(void){

	EZDSP5502_MCBSP_write(outSample);
}


