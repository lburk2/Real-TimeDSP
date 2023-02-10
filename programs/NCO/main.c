//////////////////////////////////////////////////////
//													//
//	Project 1: Numerically Controlled Oscillator	//
//													//
//	By: Landon Burk, Tess Jisa, Evan Cornwell		//
//													//
//	Created: 2023-02-08								//
//													//
//	Last Revision: 2023-02-08						//
//													//
//////////////////////////////////////////////////////

#include "stdio.h"
#include "stdint.h"
#include "ezdsp5502.h"
#include "ezdsp5502_i2cgpio.h"
#include "myNCO.h"


//extern Int16 aic3204_test( );
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

    nco_set_frequency(1000);

    int16_t outputSample;
    int16_t f = 20;

    while(1)
    {
    	// outputSample = nco_run_sinusoid();
    	// outputSample = nco_run_triangle();

    	if (f < 10000){
			nco_set_frequency(f);
			for (int i = 0; i<=255)
			{
				outputSample = nco_run_sinusoid();

				aic3204_output_sample(outputSample, outputSample);
			}
			f += 100;
    	}
    }
}
