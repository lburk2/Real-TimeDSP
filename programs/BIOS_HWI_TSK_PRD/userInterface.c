
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
//#include "Dsplib.h"

#include "myNCO.h"
#include "myFIR.h"

//NEED TO MAKE HEADER

void TSKUserInterface(Arg value_arg)
{
	//prolog stuff to call at beginning

    while(1)
    {
        TSK_sleep(50);

        //1st call SEM_pend for I2C (binary?) because two threads want to use
        SEM_pend(&SEMI2C, SYS_FOREVER);
        //read switches on i2c

        //SEM_post
        SEM_pend(&SEMI2C);
    }
}


//void PRDLedFxn(void) can't do this anymore, we have to figure something else out, turning off SWI would let us use this block and then sem would be gone
//{
//	//runs in swi thread context
//    SEM_pend(&SEMI2C, SYS_FOREVER);
//    //toggle led
//
//    //SEM_post
//    SEM_pend(&SEMI2C);
//}







