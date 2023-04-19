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
uint16_t spectrumOut[128]={0};
int16_t display[64]={0};
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

//		volatile int x=0;
//		for(x;x<128;x++)
//		{
//			wave[x]=nco_run_sinusoid();
//		}
		volatile int i=0;
		for(i;i<48;i++)
		{
			spectrum[buffcount]=filteredLeftSample[i];
			//spectrum[buffcount]=wave[i];
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

	uint16_t steve=0;
	uint16_t sarah[128] = {0};
	while(1)
	{
		MBX_pend(&MBXFFT, FFTSamps, 0);

		memcpy(FFT_U.In1, FFTSamps, 128);

		FFT_step();

		memcpy(spectrumOut, FFT_Y.Out1, 128);

		volatile int i=0;
		volatile int j=0;
		for(i=0;i<128;i+=4)
		{
			steve=(uint16_t)(((double)spectrumOut[j]/128.0));

			sarah[i] = sally[steve&0xf]>>8;
			sarah[i+1] = sally[steve&0xf] & 0xFF;
			sarah[i+2] = sally[steve&0xf]>>8;
			sarah[i+3] = sally[steve&0xf] & 0xFF;
			j++;
		}



		    /*
		     * convert FFT result to display buffer information
		     * assume:
		     * 1 - FFT is 128 points
		     * 2 - dispBuff is 128 bytes (64 16-bit words)
		     */

//		    const uint16_t pixels_on_16 = 0xffff;
//		    const uint16_t pixels_on_15 = 0x7fff; // assuming big endian, you may have to byte swap these
//		    const uint16_t pixels_on_14 = 0x3fff;
//		    const uint16_t pixels_on_13 = 0x1fff;
//		    const uint16_t pixels_on_12 = 0x0fff;
//		    const uint16_t pixels_on_11 = 0x07ff;
//		    const uint16_t pixels_on_10 = 0x03ff;
//		    const uint16_t pixels_on_9 = 0x01ff;
//		    const uint16_t pixels_on_8 = 0x00ff;
//		    const uint16_t pixels_on_7 = 0x007f;
//		    const uint16_t pixels_on_6 = 0x003f;
//		    const uint16_t pixels_on_5 = 0x001f;
//		    const uint16_t pixels_on_4 = 0x000f;
//		    const uint16_t pixels_on_3 = 0x0007;
//		    const uint16_t pixels_on_2 = 0x0003;
//		    const uint16_t pixels_on_1 = 0x0001;
//
//		    uint16_t i;
//
//		    for (i = 0; i < 64; i++)
//		    {
//		        /*
//		         * This is kinda lame code, but you have complete control over thresholds and it is easy to follow
//		         */
//		        if (spectrumOut[i] > 30000)
//		        {
//		            sarah[i] = pixels_on_16;
//		        }
//		        else if (spectrumOut[i] > 28000)
//		        {
//		            sarah[i] = pixels_on_15;
//		        }
//		        else if (spectrumOut[i] > 26000)
//		        {
//		            sarah[i] = pixels_on_14;
//		        }
//		        else if (spectrumOut[i] > 24000)
//				{
//					sarah[i] = pixels_on_13;
//				}
//		        else if (spectrumOut[i] > 22000)
//				{
//					sarah[i] = pixels_on_12;
//				}
//		        else if (spectrumOut[i] > 20000)
//				{
//					sarah[i] = pixels_on_11;
//				}
//		        else if (spectrumOut[i] > 18000)
//				{
//					sarah[i] = pixels_on_10;
//				}
//		        else if (spectrumOut[i] > 16000)
//				{
//					sarah[i] = pixels_on_9;
//				}
//		        else if (spectrumOut[i] > 14000)
//				{
//					sarah[i] = pixels_on_8;
//				}
//		        else if (spectrumOut[i] > 12000)
//				{
//					sarah[i] = pixels_on_7;
//				}
//		        else if (spectrumOut[i] > 10000)
//				{
//					sarah[i] = pixels_on_6;
//				}
//		        else if (spectrumOut[i] > 8000)
//				{
//					sarah[i] = pixels_on_5;
//				}
//		        else if (spectrumOut[i] > 6000)
//				{
//					sarah[i] = pixels_on_4;
//				}
//		        else if (spectrumOut[i] > 4000)
//				{
//					sarah[i] = pixels_on_3;
//				}
//		        else if (spectrumOut[i] > 2000)
//				{
//					sarah[i] = pixels_on_2;
//				}
//		        else if (spectrumOut[i] > 1000)
//				{
//					sarah[i] = pixels_on_1;
//				}
//		        else
//		        {
//		            sarah[i] = 0;
//		        }

//		}

		SEM_pend(&SEMI2C, SYS_FOREVER);
		osd9616_send(0x00,0x21); //setting start address
		osd9616_send(0x00,0x20);
		osd9616_send(0x00,0x60); //end column
		osd9616_send(0x00,0x22); //start page
		osd9616_send(0x00,0x00);
		osd9616_send(0x00,0x01);//end page

		myosd9616_multiSend((Uint16*)sarah, 128);
		SEM_post(&SEMI2C);
	}
}
