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
#include "ezdsp5502_mcbsp.h"
#include "myFIR.h"
#include "testVector.h"
#include "demo_filt.h"

#define NH (68) //change to number of coeffs in filter being used


extern Int16 aic3204_setup( );
extern void aic3204_process(void);
void aic3204_output_sample(int16_t left, int16_t right);


const int16_t fir1Coeffs[62] =
{
        12,     20,     28,     37,     46,     54,     56,     51,     35,      6,    -37,    -95,   -162,   -234,   -300,   -351,
      -373,   -356,   -286,   -157,     37,    294,    609,    969,   1358,   1754,   2135,   2475,   2754,   2951,   3053,   3053,
      2951,   2754,   2475,   2135,   1754,   1358,    969,    609,    294,     37,   -157,   -286,   -356,   -373,   -351,   -300,
      -234,   -162,    -95,    -37,      6,     35,     51,     56,     54,     46,     37,     28,     20,     12,
};
const int16_t demoFilter[];

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

    // Pointer + Variable Declaration
    const int16_t* restrict fir1Coeffsptr;
    const int16_t* restrict demoFilterptr;
    int16_t* restrict fir1_delayLineptr;
    int16_t* testVectorOutput;
    int16_t* testVectorptr;
    int16_t fir1_delayLine[NH];
    Int16 dataLeft;


    //Passing Arrays to Pointers
    testVectorptr=testVector;
    fir1Coeffsptr=fir1Coeffs;
    demoFilterptr=demoFilter;

    volatile int k,i;
    //fill delay line with zero
    for(i=0; i<NH; i++)
    	fir1_delayLine[i]=0;

    //Assign delayline to pointer
    fir1_delayLineptr = fir1_delayLine;

    //Dummy variable for watching output
    int16_t datOutput[240];
    for(i=0;i<240;i++)
       	datOutput[i]=0;

   //Start with left channel input at 0
   dataLeft = 0;
   while(1)
   {	//Filter and output signal (also output original signal for fun)
    	for( k=0; k < INPUT_TEST_VECTOR_LENGTH ; k++)
    	{
    		EZDSP5502_MCBSP_read(&dataLeft);

    		myFIR(//&testVectorptr[k], //function takes a vector or realtime input and outputs to testVectorOutput
    				(int16_t*)&dataLeft,
    				//fir1Coeffsptr,
    				demoFilterptr,
					testVectorOutput,
					fir1_delayLineptr,
					1,
					NH);
    		datOutput[k] = *testVectorOutput;

    		//aic3204_output_sample(*testVectorOutput, *testVector);
    		aic3204_output_sample(*testVectorOutput, *testVectorOutput);

    	}
    	k=0;//dummy instruction for debugging
    }
}

