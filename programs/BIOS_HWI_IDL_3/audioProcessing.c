
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
int16_t outputLP;
int16_t outputHP;
int16_t filteredLeftSample;

extern int NCO;
extern int filterMode;
extern int16_t* delayLineLPptr;
extern int16_t* delayLineHPptr;
extern const int16_t* demoFilterptr;
extern const int16_t* highPassptr;
volatile int NCO_counter=0;

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

		switch(filterMode){
		case 1:
			myFIR(&rxLeftSample,
					demoFilterptr,
					&filteredLeftSample,
					delayLineLPptr,
					1,
					70);
				EZDSP5502_MCBSP_write(filteredLeftSample);
				break;
			case 2:
				myFIR(&rxLeftSample,
						highPassptr,
						&filteredLeftSample,
						delayLineHPptr,
						1,
						67);
				EZDSP5502_MCBSP_write(filteredLeftSample);
				break;
			default:
				filteredLeftSample=rxLeftSample;
				EZDSP5502_MCBSP_write(filteredLeftSample);
				break;
			}

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
			if(NCO_counter<24000)
			{
				filteredLeftSample=nco_run_sinusoid();
				EZDSP5502_MCBSP_write(filteredLeftSample);
				NCO_counter++;
			}
			if(NCO_counter>=24000)
			{
				NCO_counter=0;
				NCO=0;
			}
		}


}



