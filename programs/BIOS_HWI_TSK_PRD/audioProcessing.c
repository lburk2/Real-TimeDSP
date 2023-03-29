
#include <std.h>

#include <log.h>
#include <mbx.h>
#include <sem.h>

#include "hellocfg.h"
#include "ezdsp5502.h"
#include "stdint.h"
#include "aic3204.h"
#include "ezdsp5502_mcbsp.h"
#include "csl_mcbsp.h"
#include "Dsplib.h"

//#include "myNCO.h"
//#include "myFIR.h"

extern ushort fir2(DATA *, DATA *, DATA *, DATA *, ushort, ushort);
void *memcpy(void *dest, const void * src, size_t n);

extern MCBSP_Handle aicMcbsp;

int16_t rxRightSample;
int16_t rxLeftSample;
int16_t leftRightFlag = 0;
int16_t txleftRightFlag = 0;

//int16_t output;
int16_t outputLP;
int16_t outputHP;
int16_t filteredLeftSample[48]={0};
int16_t msg[48]={0};
int16_t output[48]={0};
Int16 filteredLeftSampleOutput;

extern int NCO;
extern int filterMode;
extern int16_t* delayLineLPptr;
extern int16_t* delayLineHPptr;
extern const int16_t* demoFilterptr;
extern const int16_t* highPassptr;
//volatile int indexIn;
int txcounter=0;


int start;
int stop;
int time;

int16_t bufferIn[48]={0};
volatile uint16_t indexIn=0;

//have to protect the two lights with a semaphore
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

		if(indexIn>=48)
		{
			indexIn=0;
			MBX_post(&MBXAudio, bufferIn, 0);
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
	if (txleftRightFlag == 0)
	{
		if(txcounter<48)
		{
			filteredLeftSampleOutput=output[txcounter];
			EZDSP5502_MCBSP_write(filteredLeftSampleOutput);
			txcounter++;
			txleftRightFlag = 1;
		}
		if(txcounter>=48)
		{
			txcounter=0;
			MBX_pend(&MBXOutput, output, 0);
		}
	}
	else
	{
		//rxRightSample = MCBSP_read16(aicMcbsp);
		EZDSP5502_MCBSP_write(filteredLeftSampleOutput);

		txleftRightFlag = 0;
	}
}

void TSKAudioProcessorFxn(Arg value_arg)
{
	 //add something like this for the post

	//prolog aka init stuff
	while(1)//in general you don't return from task, one time thing? make it higher priority
	{
		MBX_pend(&MBXAudio, msg, SYS_FOREVER);
		//need to have semaphore in here or some kind of sleep or maybe mxb pend is the sleep
		//SEM_pend(&SEMFilter, SYS_FOREVER);
		switch(filterMode){
		case 1:
			fir2((DATA *)&msg,
				 (DATA *)demoFilterptr,
				 (DATA *)&filteredLeftSample,
				 (DATA *)delayLineLPptr,
				 (ushort)48,
				 (ushort)70);
			break;
		case 2:
			fir2((DATA *)&msg,
				 (DATA *)highPassptr,
				 (DATA *)&filteredLeftSample,
				 (DATA *)delayLineHPptr,
				 (ushort)48,
				 (ushort)67);
			break;
		default:
			memcpy(filteredLeftSample,msg,48);
			break;
		}

		//SEM_post(&SEMFilter);
		MBX_post(&MBXOutput, filteredLeftSample, SYS_FOREVER);

	}
}




