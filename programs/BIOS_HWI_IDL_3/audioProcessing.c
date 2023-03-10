
#include <std.h>

#include <log.h>

#include "hellocfg.h"
#include "ezdsp5502.h"
#include "stdint.h"
#include "aic3204.h"
#include "ezdsp5502_mcbsp.h"
#include "csl_mcbsp.h"

#include "myNCO.h"
#include "myFIR.h"


extern MCBSP_Handle aicMcbsp;

int16_t rxRightSample;
int16_t rxLeftSample;
int16_t leftRightFlag = 0;
int16_t txleftRightFlag = 0;

int16_t output;

extern int NCO;
extern int filterMode;
extern int16_t* delayLineLPptr;
extern const int16_t* demoFilterptr;
int i;

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
	if(NCO)
	{
		for(i=0;i<24000;i++)
		{
			rxLeftSample=nco_run_sinusoid();
			EZDSP5502_MCBSP_write(rxLeftSample);
		}
			NCO=0;
	}

//		switch(filterMode){
//		case 1:
//			myFIR(&rxLeftSample,
//				  demoFilterptr,
//				  &output,
//				  delayLineLPptr,
//				  1,
//				  68);

//			break;
//		case 2:
//			break;
//		default:
//			break;

//		}


	if (txleftRightFlag == 0)
	{
		EZDSP5502_MCBSP_write(rxRightSample);
		//MCBSP_write16(aicMcbsp,rxLeftSample);
		txleftRightFlag = 1;
	}
	else
	{
		EZDSP5502_MCBSP_write(rxRightSample);
		//MCBSP_write16(aicMcbsp,rxRightSample);
		txleftRightFlag = 0;
	}

}



