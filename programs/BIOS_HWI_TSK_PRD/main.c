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
#include "demo_filt.h"
#include "highPass.h"

extern void audioProcessingInit(void);

volatile int counter = 0;
int switch0;
int switch1;
int switch0Prev=1;
int switch1Prev=1;
int NCO;
int filterMode=0;
int16_t delayLineLP[70]={0};
int16_t delayLineHP[67]={0};
const int16_t* restrict demoFilterptr;
int16_t* restrict delayLineLPptr;
int16_t* restrict delayLineHPptr;
const int16_t highPass[];
const int16_t* restrict highPassptr;

volatile int k;

void *memset(void *str, int c, size_t n);
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

    EZDSP5502_I2CGPIO_configLine(  SW0, IN );
    EZDSP5502_I2CGPIO_configLine(  SW1, IN );
    //init leds
    EZDSP5502_I2CGPIO_configLine(  LED0, OUT );
    EZDSP5502_I2CGPIO_configLine(  LED1, OUT );
    EZDSP5502_I2CGPIO_configLine(  LED2, OUT );

    //init NCO
    nco_set_frequency(1000);
    nco_set_attenuation(3);

    memset(delayLineLP, 0, sizeof delayLineLP);
    memset(delayLineHP, 0, sizeof delayLineHP);

    delayLineLPptr=delayLineLP;
    delayLineHPptr=delayLineHP;
    demoFilterptr=demoFilter;
    highPassptr=highPass;
    // after main() exits the DSP/BIOS scheduler starts
}

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

void myIDLThread(void)
{
	counter++;


	switch0=EZDSP5502_I2CGPIO_readLine(SW0);
	switch1=EZDSP5502_I2CGPIO_readLine(SW1);
	if(switch0 != switch0Prev)
	{
		if(!switch0)
		{
			NCO=1;
		}
		switch0Prev=switch0;
	}

	if(switch1 != switch1Prev)
	{
		if(!switch1)
		{
			filterMode++;
			if(filterMode>2)
			{
				filterMode=0;
			}
			switch(filterMode){
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
		switch1Prev=switch1;
	}
}

