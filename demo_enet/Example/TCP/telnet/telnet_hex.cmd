/* Use CCS to build the telnet.out program
 * by opening the telnet.pjt file and selecting
 * Build. After that, open a DOS window in the same
 * directory and type
 *
 * hex55 telnet_hex.cmd
 *
 * to produce telnet.hex.
 * Use the FTP Server application to upload.
 */
-boot                      /* Place all initialized sections in image */
-v5510:2                   /* Set processor type                      */
-serial8                   /* Set Flash system memory width           */
-reg_config 0x6c00,0x0001  /* enable ext. bus                         */
-reg_config 0x0804,0xFF33  /* 32-bit SDRAM in CE0 space.              */
-reg_config 0x0805,0xFFFF
-reg_config 0x080C,0xF000  /* EMIF SDRAM Control Register 1           */
-reg_config 0x080D,0x4748  /* EMIF SDRAM Control Register 2           */
-reg_config 0x080E,0x0001
-reg_config 0x080F,0x0000
-delay 0x100
-i                         /* select Intel Hex format                 */
-map telnet_hex.map        /* Name hex utility map file               */
-o telnet.hex              /* Name hex output file                    */
telnet.out                 /* Input COFF file                         */

