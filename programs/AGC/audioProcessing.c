
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

#define MAX_GAIN 100.0
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

int16_t filteredLeftSample[48]={0};
int16_t msg[48]={0};
int16_t output[48]={0};
Int16 filteredLeftSampleOutput;

extern int filterMode;
int txcounter=0;


/*
 * Global Variables for AGC
 */

#define BUFF_SIZE 200
float detector=0;
float detector_array[BUFF_SIZE]={0};
float sum_output=0;
float gain=1;
float desiredGain=1;
float alpha = 1 /  (0.83333333333 * 48000.0);
float out[BUFF_SIZE] = {0};

/*
 * Tunable variables for AGC
 */
float attack = 0.000001;
float decay = 0.9999999;
float setpoint=14.0;


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

//		if(!filterMode)
		if(1)
		{
			detector = 0.0;
			// find max amplitude
			for(i=0;i<48;i++)
				if ((float)msg[i]>detector)
					detector =(float)msg[i];

			detector_array[count]= detector;
			count++;
			if(count>=BUFF_SIZE)
				count=0;

			//iir LPF
			out[0] = alpha * detector_array[0];
			for( i=1;i<BUFF_SIZE;i++)
			    out[i] = ((1.0-alpha)*out[i-1] + alpha *detector_array[i]);

			// Average filter output
			for(i=0;i<BUFF_SIZE;i++)
				sum_output+=out[i];

			sum_output=sum_output/200.0;

			//Compute Gain
			desiredGain = setpoint/sum_output;
//			if(sum_output>0.001)
//			{
				if (desiredGain > 1)
					gain = ((1.0-attack)*desiredGain + attack *gain);
				else if (desiredGain <= 1)
					gain = ((1.0-decay)*desiredGain + decay*gain);

				// Limit gain to allowable range
				if (gain > MAX_GAIN)
				  gain = MAX_GAIN;
				else if (gain < MIN_GAIN)
				  gain = MIN_GAIN;
			}
			for(i=0;i<48;i++)
				msg[i]=(int)((float)msg[i]*gain);
//		}

		MBX_post(&MBXOutput, msg, SYS_FOREVER);
	}
}




