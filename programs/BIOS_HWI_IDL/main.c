/***************************************************************************/
/*                                                                         */
/*     H E L L O . C                                                       */
/*                                                                         */
/*     Basic LOG event operation from main.                                */
/*                                                                         */
/***************************************************************************/

//#include <std.h>
#include "hellocfg.h"
#include "ezdsp5502.h"
#include "stdint.h"
#include "stdbool.h"
#include "aic3204.h"
#include "ezdsp5502_mcbsp.h"
#include "csl_mcbsp.h"
#include "ezdsp5502_i2cgpio.h"
#include "csl_gpio.h"
#include "highPassCoeffs.h"


extern void audioProcessingInit(void);
extern void ConfigureAic3204(void);
//extern void C55_enableInt();

int filterMode=0;
_Bool NCO=false;


int counter = 0;

void main(void)
{
	/* Initialize BSL */
    EZDSP5502_init( );

    /* configure the Codec chip */
    ConfigureAic3204();

    /* Initialize I2S */
    EZDSP5502_MCBSP_init();

    /* enable the interrupt with BIOS call */
    C55_enableInt(7); // reference technical manual, I2S2 tx interrupt
    C55_enableInt(6); // reference technical manual, I2S2 rx interrupt

    audioProcessingInit();

    //initializing buttons
    EZDSP5502_I2CGPIO_configLine( SW0, IN);
    EZDSP5502_I2CGPIO_configLine( SW1, IN);

	//initializing LED
    EZDSP5502_I2CGPIO_configLine(  LED0, OUT );
    EZDSP5502_I2CGPIO_configLine(  LED1, OUT );
    EZDSP5502_I2CGPIO_configLine(  LED2, OUT );

    // after main() exits the DSP/BIOS scheduler starts
}

void myIDLThread(void){
	counter++;

	int switch0 = EZDSP5502_I2CGPIO_readLine( SW0);
	int switch1 = EZDSP5502_I2CGPIO_readLine( SW1);

	if(switch1)
	{
		NCO=true;
	}
	else NCO=false;


	if(switch0)
	{
		filterMode++;
		if(filterMode==4)
		{
			filterMode=0;
		}
	}

	switch (filterMode){
	case 0:
	    EZDSP5502_I2CGPIO_writeLine(   LED0, LOW );
	    EZDSP5502_I2CGPIO_writeLine(   LED1, HIGH );
	    EZDSP5502_I2CGPIO_writeLine(   LED2, HIGH );
	    break;
	case 1:
		EZDSP5502_I2CGPIO_writeLine(   LED0, HIGH );
		EZDSP5502_I2CGPIO_writeLine(   LED1, LOW );
	    EZDSP5502_I2CGPIO_writeLine(   LED2, HIGH );
	    break;
	case 2:
		EZDSP5502_I2CGPIO_writeLine(   LED0, HIGH );
		EZDSP5502_I2CGPIO_writeLine(   LED1, HIGH );
	    EZDSP5502_I2CGPIO_writeLine(   LED2, LOW );
	    break;
	}

}

void

#if 0
Void taskFxn(Arg value_arg)
{
    LgUns prevHtime, currHtime;
    uint32_t delta;
    float ncycles;

    /* get cpu cycles per htime count */
    ncycles = CLK_cpuCyclesPerHtime();

    while(1)
    {
        TSK_sleep(1);
        LOG_printf(&trace, "task running! Time is: %d ticks", (Int)TSK_time());

        prevHtime = currHtime;
        currHtime = CLK_gethtime();

        delta = (currHtime - prevHtime) * ncycles;
        LOG_printf(&trace, "CPU cycles = 0x%x %x", (uint16_t)(delta >> 16), (uint16_t)(delta));

    }
}
#endif


