
#include <std.h>

#include <log.h>
#include <clk.h>
#include <tsk.h>
#include <gbl.h>
#include <c55.h>
#include <sem.h>
#include <prd.h>

#include "hellocfg.h"
#include "ezdsp5502.h"
#include "stdint.h"
#include "aic3204.h"
#include "ezdsp5502_mcbsp.h"
#include "csl_mcbsp.h"
#include "Dsplib.h"
#include "ezdsp5502_i2cgpio.h"


int switch1;
int switch1Prev=1;
int filterMode=0;
int flagHighakadanger=0;


void TSKUserInterfaceFxn(Arg value_arg)
{
    while(1)
    {
        TSK_sleep(50);

        SEM_pend(&SEMI2C, SYS_FOREVER);

        //read switches on i2c
        switch1=EZDSP5502_I2CGPIO_readLine(SW1);

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

        EZDSP5502_I2CGPIO_writeLine(   LED3, flagHighakadanger );
        SEM_post(&SEMI2C);
    }
}


void PRDLedFxn(void)
{
//    SEM_pend(&SEMI2C, SYS_POLL);//SYS_POLL to prove we read notes
//    //set flags to toggle led
//    if(flagHighakadanger==0)
//    {
//    	flagHighakadanger=1;
//    }
//    else
//    {
//    	flagHighakadanger=0;
//    }
//    SEM_post(&SEMI2C);
}

/*
 * our display is only 96 by 16 (two 8 bit rows  and 96 columns)
 * we'll only use 64 columns (128/2)
 *
 * use veritcal addressing mode
 *
 * while(1){
 * 	MBX_pend(&mbx1, msg, sys_forever)
 * 	FFT(msg, output);
 * 	//semaphore pend here??
 * 	//write LCD
 * 	//semaphore post here??
 * 	//post mail box??
 *
 * }
 *
 */





