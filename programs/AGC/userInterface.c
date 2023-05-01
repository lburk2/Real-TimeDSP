
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
int filterMode=1;
int flagHighakadanger=0;


void TSKUserInterfaceFxn(Arg value_arg)
{
    while(1)
    {
        TSK_sleep(50);

        //SEM_pend(&SEMI2C, SYS_FOREVER);

        //read switches on i2c
        switch1=EZDSP5502_I2CGPIO_readLine(SW1);

        	if(switch1 != switch1Prev)
        	{
        		if(!switch1)
        		{
					if(filterMode==0)
					{
						filterMode=1; //button pressed
					}
					else if(filterMode==1)
					{
						filterMode=0;
					}
        		}
        		switch1Prev=switch1;
        	}
        //SEM_post(&SEMI2C);
    }
}


void PRDLedFxn(void)
{
    SEM_pend(&SEMI2C, SYS_POLL);//SYS_POLL to prove we read notes
    //set flags to toggle led
    if(flagHighakadanger==0)
    {
    	flagHighakadanger=1;
    }
    else
    {
    	flagHighakadanger=0;
    }
    SEM_post(&SEMI2C);
}







