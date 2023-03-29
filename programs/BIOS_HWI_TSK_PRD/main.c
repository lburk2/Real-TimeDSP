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
//#include "Dsplib.h"

#include "demo_filt.h"
#include "highPass.h"

extern void audioProcessingInit(void);

volatile int counter = 0;
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

    EZDSP5502_I2CGPIO_configLine(  SW1, IN );
    //init leds
    EZDSP5502_I2CGPIO_configLine(  LED0, OUT );
    EZDSP5502_I2CGPIO_configLine(  LED1, OUT );
    EZDSP5502_I2CGPIO_configLine(  LED2, OUT );

    memset(delayLineLP, 0, sizeof delayLineLP);
    memset(delayLineHP, 0, sizeof delayLineHP);

    delayLineLPptr=delayLineLP;
    delayLineHPptr=delayLineHP;
    demoFilterptr=demoFilter;
    highPassptr=highPass;
    // after main() exits the DSP/BIOS scheduler starts

}

