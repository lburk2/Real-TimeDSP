
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


void TSKUserInterfaceFxn(Arg value_arg)
{
	//prolog stuff to call at beginning

    while(1)
    {
        TSK_sleep(50);

        //1st call SEM_pend for I2C (binary?) because two threads want to use
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

        //SEM_post
        SEM_post(&SEMI2C);
    }
}


void PRDLedFxn(void) //can't do this anymore, we have to figure something else out, turning off SWI would let us use this block and then sem would be gone
{
//	//runs in swi thread context
//    SEM_pend(&SEMI2C, SYS_FOREVER);
//    //toggle led
//
//    //SEM_post
//    SEM_post(&SEMI2C);
}







