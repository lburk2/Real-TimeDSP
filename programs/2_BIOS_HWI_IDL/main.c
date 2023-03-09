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
#include <c55.h>//us
//#include "clkcfg.h"

#include "hellocfg.h"
#include "ezdsp5502.h"
#include "ezdsp5502_i2cgpio.h"//added by us
#include "stdint.h"
#include "aic3204.h"
#include "ezdsp5502_mcbsp.h"
#include "csl_mcbsp.h"
//#include "c55xx_flash.h"//us

#include "stdio.h"
#include "myFIR.h"
#include "myNCO.h"
#include "demo_filt.h"
#include "highPassCoeffs.h"

extern void audioProcessingInit(void);
//extern void ConfigureAic3204(void);
extern Int16 aic3204_setup( );
void aic3204_init(void);
void aic3204_output_sample(int16_t left, int16_t right);
//extern void C55_enableInt(Uns vecid);

//define global variables
int filterMode=0;
int NCO=0;//sorry about bool landon
volatile int counter = 0;
int switch0_prev=1;
int switch0;
int switch1;
int16_t output;

const int16_t demoFilter[];
const int16_t highPassCoeffs[];

void main(void)
{
    /* Initialize BSL */
    EZDSP5502_init( );

    // configure the Codec chip
    //ConfigureAic3204();
    aic3204_setup();

    /* Initialize I2S */
    EZDSP5502_MCBSP_init();

    /* enable the interrupt with BIOS call */
    C55_enableInt(7); // reference technical manual, I2S2 tx interrupt
    C55_enableInt(6); // reference technical manual, I2S2 rx interrupt

    //audioProcessingInit();

    //initializing buttons
    EZDSP5502_I2CGPIO_configLine( SW0, IN);
    EZDSP5502_I2CGPIO_configLine( SW1, IN);

	//initializing LED
    EZDSP5502_I2CGPIO_configLine(  LED0, OUT );
    EZDSP5502_I2CGPIO_configLine(  LED1, OUT );
    EZDSP5502_I2CGPIO_configLine(  LED2, OUT );

    //initialize nco
    nco_set_frequency(1000);

    //initialize FIR

    // after main() exits the DSP/BIOS scheduler starts
}

void myIDLThread(void)
{
	counter++;

	switch0 = EZDSP5502_I2CGPIO_readLine(SW0);
	switch1 = EZDSP5502_I2CGPIO_readLine(SW1);

	if(!switch0)
	{
		NCO=1; //has to connect to interrupt?
	}
	else NCO=0;


	if(switch1 != switch1_prev)
	{
		if(!switch1)
		{
			filterMode++;
			if(filterMode==3)
			{
				filterMode=0;
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
		switch0_prev=switch0;
		}
	}
}

//Void taskFxn(Arg value_arg)
//{
//    LgUns prevHtime, currHtime;
//    uint32_t delta;
//    float ncycles;
//
//    /* get cpu cycles per htime count */
//    ncycles = CLK_cpuCyclesPerHtime();
//
//
//    while(1)
//    {
//        TSK_sleep(1);
//        LOG_printf(&trace, "task running! Time is: %d ticks", (Int)TSK_time());
//
//        prevHtime = currHtime;
//        currHtime = CLK_gethtime();
//
//        delta = (currHtime - prevHtime) * ncycles;
//        LOG_printf(&trace, "CPU cycles = 0x%x %x", (uint16_t)(delta >> 16), (uint16_t)(delta));
//
//
//
//    }
//}
