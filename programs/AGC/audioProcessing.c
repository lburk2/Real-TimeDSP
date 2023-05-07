
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

#define MAX_GAIN 10.0
#define MIN_GAIN 0.0

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
int windowSize=3;
float detector=0;
float detector_array[48]={0};
int ones[3]= {1,1,1};

float sum_output=0;
float setpoint=35724.0;
float gain=1;
float alpha = 1 /  (0.83333333333 * 48000.0);
float out[48] = {0};



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
	//prolog aka init stuff
	int i=0;
	int count=0;

	while(1)
	{
		MBX_pend(&MBXAudio, msg, SYS_FOREVER);

		if(!filterMode)
		{
			// Compute Power
			for(i=0;i<48;i++)
			{
				detector+=((float)msg[i]*(float)msg[i]);
			}
			detector=detector/48.0;
			detector_array[count]= detector;
			count++;
			if(count>=48)
			{
				count=0;
			}

			//iir
			out[0] = alpha * detector_array[0];
			for( i=1;i<48;i++)
			{
			    out[i] = ((1.0-alpha)*out[i-1] + alpha *detector_array[i]);
			}

			// Average filter output
			for(i=0;i<48;i++)
			{
				sum_output+=out[i];
			}
			sum_output=sum_output/48;

		    // Limit gain to allowable range
		    if (gain > MAX_GAIN) {
		      gain = MAX_GAIN;
		    } else if (gain < MIN_GAIN) {
		      gain = MIN_GAIN;
		    }

		    //increase/decrease gain
			if(sum_output < setpoint)
			{
				gain+=0.01;
			}
			else if (sum_output > setpoint)
			{
				gain-=0.01;
			}

//			gain = setpoint/sum_output;

			for(i=0;i<48;i++)
			{
				msg[i]=(int)((float)msg[i]*gain);
			}
		}

		MBX_post(&MBXOutput, msg, SYS_FOREVER);
	}
}




