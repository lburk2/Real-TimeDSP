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

extern Int16 aic3204_setup( );
extern void aic3204_process(void);
void aic3204_output_sample(int16_t left, int16_t right);
int16_t *fir1_delayLine[62];
int16_t *testVectorOutput;
int16_t *testVectorptr;

const int16_t fir1Coeffs[62] = {0,	1,	3,	9,	17,	25,	32,	33,	25,	5, -30, -79,
								-141, -208, -273, -325, -351, -339, -275, -152, 36, 289,
								602, 962, 1352, 1752, 2137, 2482 ,2765, 2965, 3069, 3069,
								2965, 2765, 2482, 2137, 1752, 1352, 962, 602, 289, 36, -152,
								-275, -339, -351, -325, -273, -208, -141, -79, -30, 5, 25, 33,
								32, 25, 17, 9, 3, 1, 0};
const int16_t *fir1Coeffsptr;

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
    testVectorptr=testVector;
    fir1Coeffsptr=fir1Coeffs;

    volatile int k,i;
    k=0;
    for(i=0;i<62;i++)
    {
    	fir1_delayLine[i]=0;
    }

   // volatile int16_t datOutput[240];
//    for(i=0;i<240;i++)
//       {
//       	datOutput[i]=0;
//       }
//    int16_t *datOutputptr;
//
//    datOutputptr=datOutput;

    while(1)
    {
    	for( k=0; k < INPUT_TEST_VECTOR_LENGTH ; k++)
    	{
    		myFIR(&testVectorptr[k],
    				fir1Coeffsptr,
					testVectorOutput,
					*fir1_delayLine,
					1,
					62);
    		aic3204_output_sample(*testVectorOutput, *testVectorOutput);

    		//datOutput[k]=testVectorOutput[k];

    	}

//    	for( k=0; k < INPUT_TEST_VECTOR_LENGTH ; k++) //check on 240, need length of test vector
//    	    {
//    	    		aic3204_output_sample(testVectorptr[k], testVectorptr[k]);
//    	    	}
    }
}

