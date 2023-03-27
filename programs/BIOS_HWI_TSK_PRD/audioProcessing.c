
#include <std.h>

#include <log.h>

#include "hellocfg.h"
#include "ezdsp5502.h"
#include "stdint.h"
#include "aic3204.h"
#include "ezdsp5502_mcbsp.h"
#include "csl_mcbsp.h"
//#include "Dsplib.h"

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
int16_t filteredLeftSample[48]={0};

extern int NCO;
extern int filterMode;
extern int16_t* delayLineLPptr;
extern int16_t* delayLineHPptr;
extern const int16_t* demoFilterptr;
extern const int16_t* highPassptr;
volatile int indexIn;
int txcounter=0;


int start;
int stop;
int time;

int16_t bufferIn[48]={0};
volatile uint16_t indexIn=0;

void audioProcessingInit(void)
{
	rxRightSample = 0;
	rxLeftSample = 0;
}


void HWI_I2S_Rx(void)
{

	if (leftRightFlag == 0)
	{
		if (indexIn<48)
		{
			bufferIn[indexIn] = MCBSP_read16(aicMcbsp);
			leftRightFlag = 1;
			indexIn++;
		}

		if(indexIn>=48) //landon made me, dave used ==
		{
			indexIn=0;
			MBX_post(&MBXAudio, bufferIn, 0); //=0 when called from hardware interrupt
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
	int16_t output[48];

	MBX_pend(&MBXAudio, output, SYS_FOREVER);
	if(txcounter<48)
	{
		filteredLeftSample=output[txcounter]
		EZDSP5502_MCBSP_write(&filteredLeftSample);
	}

}

void TSKAudioProcessor()
{
	int16_t msg[48];

	//prolog

	while(1)
	{
		MBX_pend(&MBXAudio, msg, SYS_FOREVER);

		switch(filterMode){
		case 1:
			myFIR(&msg,
					demoFilterptr,
					&filteredLeftSample,
					delayLineLPptr,
					48,
					70);
			break;
		case 2:
			myFIR(&msg,
					highPassptr,
					&filteredLeftSample,
					delayLineHPptr,
					48,
					67);
			break;
		default:
			filteredLeftSample=rxLeftSample;
			break;


		MBX_post(&MBXAudio, &filteredLeftSample, 0); //=0 when called from hardware interrupt
		}
	}
}




