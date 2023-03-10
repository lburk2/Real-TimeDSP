//////////////////////////////////////////////////////
//													//
//	Project 1: Numerically Controlled Oscillator	//
//													//
//	By: Landon Burk, Tess Jisa, Evan Cornwell		//
//													//
//	Created: 2023-02-08								//
//													//
//	Last Revision: 2023-02-10						//
//													//
//////////////////////////////////////////////////////

#include "stdio.h"
#include "stdint.h"
#include "ezdsp5502.h"
#include "ezdsp5502_i2cgpio.h"
#include "myNCO.h"

extern Int16 aic3204_setup( );
extern void aic3204_process(void);
void aic3204_output_sample(int16_t left, int16_t right);


void main( void )
{
    /* Initialize BSL */
    EZDSP5502_init( );

    /* Set to McBSP1 mode */
    EZDSP5502_I2CGPIO_writeLine(  BSP_SEL1, LOW );
    EZDSP5502_I2CGPIO_configLine( BSP_SEL1, OUT );

    /* Enable McBSP1 */
    EZDSP5502_I2CGPIO_configLine( BSP_SEL1_ENn, OUT );
    EZDSP5502_I2CGPIO_writeLine(  BSP_SEL1_ENn, LOW );

    aic3204_setup();

    /* Set frequency and attenuation factor*/
    nco_set_frequency(200);
    nco_set_attenuation(0);

    /* Variable Declaration */
    int16_t outputSample;
    int16_t f = 20;
    int i = 0;

    while(1)
    {
    	outputSample = nco_run_sinusoid(); //get next sinusoid sample
//    	outputSample = nco_run_triangle(); //get enxt triangle sample
    	aic3204_output_sample(outputSample, outputSample);	//output sample

    	/* Chirp */
//    	 if (f < 1000) // limit max frequency to 1000 Hz
//    	{
//			nco_set_frequency(f); // set frequecy
//			for (i = 0; i<=255; i++) // loop an entire period of the signal
//			{
//				outputSample = nco_run_sinusoid(); // get samples
//
//				aic3204_output_sample(outputSample, outputSample);// output samples
//			}
//			f += 1;//increment frequency by 1 Hz
//    	}

    }
}
