#include <stdio.h>
#include <stdint.h>

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
#include "FFT.h"
#include "lcd.h"

#include "myNCO.h"



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
int16_t spectrum[128]={0};
int16_t FFTSamps[128]={0};
int16_t wave[128]={0}; //FOR TESTING PURPOSES
int16_t spectrumOut[128]={0};
uint16_t buffcount=0;
Int16 filteredLeftSampleOutput;

const uint16_t sally[16]={0,1,3,7,15,31,63,127,255,511,1023,2047,4095,8191,16383,32767};

extern int NCO;
extern int filterMode;
extern int16_t* delayLineLPptr;
extern int16_t* delayLineHPptr;
extern const int16_t* demoFilterptr;
extern const int16_t* highPassptr;
//volatile int indexIn;
int txcounter=0;

extern ExtU_FFT_T FFT_U;

int start;
int stop;
int time;

int16_t bufferIn[48]={0};
volatile uint16_t indexIn=0;

void *memcpy(void *dest, const void *src, size_t n);

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
	while(1)
	{
		MBX_pend(&MBXAudio, msg, SYS_FOREVER);

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

		MBX_post(&MBXOutput, filteredLeftSample, SYS_FOREVER);

		volatile int x=0;
		for(x;x<128;x++)
		{
			wave[x]=nco_run_sinusoid();
		}
		volatile int i=0;
		for(i;i<48;i++)
		{
			//spectrum[buffcount]=filteredLeftSample[i];
			spectrum[buffcount]=wave[i];
			buffcount++;
			if(buffcount==128)
			{
				MBX_post(&MBXFFT, spectrum, 0);
				buffcount=0;
			}
		}
	}
}

void TSKFFTfxn(Arg value_arg)
{
	//call init
	FFT_initialize();

	osd9616_send(0x00,0x21); //setting start address
	osd9616_send(0x00,0x00);
	osd9616_send(0x00,0x3F); //end column
	osd9616_send(0x00,0x22); //start page
	osd9616_send(0x00,0x00);
	osd9616_send(0x00,0x01);//end page
	//osd9616_send(0x00,0xC8);//left to right display
	volatile int i=0;
	for(i=0;i<128;i++)
	{
		osd9616_send(0x40,0xff);//clears display
	}
	for(i=0;i<128;i++)
	{
		osd9616_send(0x40,0x00);//clears display
	}

	uint16_t steve;
	while(1)
	{
		MBX_pend(&MBXFFT, FFTSamps, 0);

		memcpy(FFT_U.In1, FFTSamps, 128);

		FFT_step();

		memcpy(spectrumOut, FFT_Y.Out1, 128); //output

		SEM_pendBinary(&SEMFFT, SYS_FOREVER);
		volatile int i=0;

		for(i=0;i<64;i++)
		{
			steve=spectrumOut[i]>>11;

			osd9616_send(0x40,sally[steve&0xf]); //printing spectrum
			//osd9616_send(0x40,0x00);
			i++;
		}
//		osd9616_send(0x40,0x00);
//		osd9616_multiSend((Uint16*)spectrumOut, 128);
		SEM_postBinary(&SEMFFT);
		//MBX_post(&MBXFFT, FFTSamps, 0);

	 /* our display is only 96 by 16 (two 8 bit rows  and 96 columns)
	 * we'll only use 64 columns (128/2)
	 *
	 * use veritcal addressing mode
	 *
	 * while(1){
	 * 	MBX_pend(&mbx1, msg, sys_forever)
	 * 	FFT(msg, output);
	 * 	//semaphore pend here??
	 * 	//write LCD
	 * 	//semaphore post here??
	 * 	//post mail box??
	 *
	 * }*/
	}

}
