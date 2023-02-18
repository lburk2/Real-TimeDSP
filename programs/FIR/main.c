//////////////////////////////////////////////////////
//													//
//	Project 1: Finite Impulse Response Filter		//
//													//
//	By: Landon Burk, Tess Jisa, Evan Cornwell		//
//													//
//	Created: 2023-02-15								//
//													//
//	Last Revision: 2023-02-17						//
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

const  int16_t fir1Coeffs[62] =
{
        12,     20,     28,     37,     46,     54,     56,     51,     35,      6,    -37,    -95,   -162,   -234,   -300,   -351,
      -373,   -356,   -286,   -157,     37,    294,    609,    969,   1358,   1754,   2135,   2475,   2754,   2951,   3053,   3053,
      2951,   2754,   2475,   2135,   1754,   1358,    969,    609,    294,     37,   -157,   -286,   -356,   -373,   -351,   -300,
      -234,   -162,    -95,    -37,      6,     35,     51,     56,     54,     46,     37,     28,     20,     12,
};


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

    const int16_t* restrict fir1Coeffsptr;
    int16_t *testVectorOutput;
    int16_t *testVectorptr;
    int16_t fir1_delayLine[62];
    int16_t* restrict fir1_delayLineptr;

    testVectorptr=testVector;
    fir1Coeffsptr=fir1Coeffs;

    volatile int k,i;
    k=0;
    for(i=0; i<62; i++)
    {
    	fir1_delayLine[i]=0;
    }

    fir1_delayLineptr = fir1_delayLine;

    int16_t datOutput[240];
    for(i=0;i<240;i++)
       {
       	datOutput[i]=0;
       }
    int16_t *datOutputptr;
    datOutputptr=datOutput;

   while(1)
   {
    	for( k=0; k < INPUT_TEST_VECTOR_LENGTH*10 ; k++)
    	{
    		myFIR(&testVectorptr[k],
    				fir1Coeffsptr,
					testVectorOutput,
					fir1_delayLineptr,
					1,
					62);
    		datOutputptr = testVectorOutput;

    		aic3204_output_sample(*testVectorOutput, testVectorptr[k]);

    	}

//    	for( k=0; k < INPUT_TEST_VECTOR_LENGTH ; k++)
//    	{
//    	    aic3204_output_sample(testVectorptr[k], testVectorptr[k]);
//    	}
    }
}

