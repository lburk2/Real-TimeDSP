/*
 *  Copyright 2010 by Texas Instruments Incorporated.
 *  All rights reserved. Property of Texas Instruments Incorporated.
 *  Restricted rights to use, duplicate or disclose this code are
 *  granted through contract.
 *
 */
/***************************************************************************/
/*                                                                         */
/*     H E L L O . C                                                       */
/*                                                                         */
/*     Basic LOG event operation from main.                                */
/*                                                                         */
/***************************************************************************/

#include <std.h>

#include <log.h>
#include <clk.h>
#include <tsk.h>
#include <gbl.h>
#include <c55.h>
//#include "clkcfg.h"

#include "hellocfg.h"
#include "ezdsp5502.h"
#include "ezdsp5502_i2cgpio.h"
#include "stdint.h"
#include "aic3204.h"
#include "ezdsp5502_mcbsp.h"
#include "csl_mcbsp.h"

#include "myNCO.h"

extern void audioProcessingInit(void);

volatile int counter = 0;
int switch0;
int switch1;
int switchPrev=1;
int NCO;
int filterMode=0;


void main(void)
{
    /* Initialize BSL */
    EZDSP5502_init( );

    // configure the Codec chip
    ConfigureAic3204();

    /* Initialize I2S */
    EZDSP5502_MCBSP_init();

    /* enable the interrupt with BIOS call */
    C55_enableInt(7); // reference technical manual, I2S2 tx interrupt
    C55_enableInt(6); // reference technical manual, I2S2 rx interrupt

    //audioProcessingInit();

    //init NCO
    nco_set_frequency(1000);
    nco_set_attenuation(0);
    // after main() exits the DSP/BIOS scheduler starts
}

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

void myIDLThread(void)
{
	counter++;

	switch0=EZDSP5502_I2CGPIO_readLine(SW0);
	if(switch0 != switchPrev)
	{
		if(!switch0)
		{
			NCO=1;
		}
		switchPrev=switch0;
	}
	else NCO=0;


}

