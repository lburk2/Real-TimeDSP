//////////////////////////////////////////////////////////////////////////////
// * File name: led_test.c
// *                                                                          
// * Description:  LED Test.
// *                                                                          
// * Copyright (C) 2011 Texas Instruments Incorporated - http://www.ti.com/ 
// * Copyright (C) 2011 Spectrum Digital, Incorporated
// *                                                                          
// *                                                                          
// *  Redistribution and use in source and binary forms, with or without      
// *  modification, are permitted provided that the following conditions      
// *  are met:                                                                
// *                                                                          
// *    Redistributions of source code must retain the above copyright        
// *    notice, this list of conditions and the following disclaimer.         
// *                                                                          
// *    Redistributions in binary form must reproduce the above copyright     
// *    notice, this list of conditions and the following disclaimer in the   
// *    documentation and/or other materials provided with the                
// *    distribution.                                                         
// *                                                                          
// *    Neither the name of Texas Instruments Incorporated nor the names of   
// *    its contributors may be used to endorse or promote products derived   
// *    from this software without specific prior written permission.         
// *                                                                          
// *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS     
// *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT       
// *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR   
// *  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT    
// *  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,   
// *  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT        
// *  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,   
// *  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY   
// *  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT     
// *  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE   
// *  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.    
// *                                                                          
//////////////////////////////////////////////////////////////////////////////

#include "ezdsp5502.h"

/*
 *
 *  sdram_test( )
 *    Tests the SDRAM by writing and verifying patterns
 *
 */

Int16 MEM_addr(Uint32 start, Uint32 len)
{
    Uint32 i, end;

    /* Calculate end of range */
    end = start + len;

    /* Fill the range with its address */
    for (i = start; i < end; i+=2)
    {
        *((Uint32 *)i) = i;
    }

    /* Verify the data */
    for (i = start; i < end; i+=2)
        if (*((Uint32 *)i) != i)
            return 1;

    return 0;
}

Int16 MEM_addrInv(Uint32 start, Uint32 len)
{
    Uint32 i, end;

    /* Calculate end of range */
    end = start + len;

    /* Fill the range with its address */
    for (i = start; i < end; i+=2)
    {
        *((Uint32 *)i) = ~i;
    }

    /* Verify the data */
    for (i = start; i < end; i+=2)
        if (*((Uint32 *)i) != (~i))
            return 1;

    return 0;
}


Int16 sdram_test( )
{
    Uint16 status = 0;
    status |= MEM_addr(0x8000, 0x1F8000);
    status |= MEM_addrInv(0x8000, 0x1F8000);

    return 0;
}

