//////////////////////////////////////////////////////
//													//
//	Project 1: Finite Impulse Response Filter		//
//													//
//	By: Landon Burk, Tess Jisa, Evan Cornwell		//
//													//
//	Created: 2023-02-15								//
//													//
//	Last Revision: 2023-02-15						//
//													//
//////////////////////////////////////////////////////

#include "stdio.h"
#include "stdint.h"
#include "ezdsp5502.h"
#include "ezdsp5502_i2cgpio.h"
#include "myFIR.h"
#include "testVector.h"

extern int16_t aic3204_setup( );
extern void aic3204_process(void);
void aic3204_output_sample(int16_t left, int16_t right);
int16_t fir1_delayLine[62];
int16_t testVectorOutput[240];
const int16_t fir1Coeffs[62] = {};

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

    memset(dl,0,siteof(dl))

    while(1)
    {
    	for(int k=0,k<240,i++) //check on 240, need length of test vector
    	{
    		myFIR(*testVector[k],*h,*testVectorOutput[k],*delayLine,1,62);
    	}

    }
}

