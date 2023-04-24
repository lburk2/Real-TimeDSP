################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
aic3204.obj: ../aic3204.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"D:/ti/ccsv6/tools/compiler/c5500_4.4.1/bin/cl55" -v5502 --memory_model=large -g --include_path="D:/ti/ccsv6/tools/compiler/c5500_4.4.1/include" --include_path="Z:/Semester8/Real-Time DSP/Projects/Real-TimeDSP/C55xxCSL/include" --include_path="Z:/Semester8/Real-Time DSP/Projects/Real-TimeDSP/include" --include_path="Z:/Semester8/Real-Time DSP/Projects/Real-TimeDSP/programs/AGC/Debug" --include_path="D:/ti/bios_5_42_01_09/packages/ti/bios/include" --include_path="D:/ti/bios_5_42_01_09/packages/ti/rtdx/include/c5500" --define=c5502 --display_error_number --diag_warning=225 --ptrdiff_size=32 --preproc_with_compile --preproc_dependency="aic3204.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

audioProcessing.obj: ../audioProcessing.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"D:/ti/ccsv6/tools/compiler/c5500_4.4.1/bin/cl55" -v5502 --memory_model=large -O3 -g --include_path="D:/ti/ccsv6/tools/compiler/c5500_4.4.1/include" --include_path="Z:/Semester8/Real-Time DSP/Projects/Real-TimeDSP/C55xxCSL/include" --include_path="Z:/Semester8/Real-Time DSP/Projects/Real-TimeDSP/include" --include_path="Z:/Semester8/Real-Time DSP/Projects/Real-TimeDSP/programs/AGC/Debug" --include_path="D:/ti/bios_5_42_01_09/packages/ti/bios/include" --include_path="D:/ti/bios_5_42_01_09/packages/ti/rtdx/include/c5500" --define=c5502 --display_error_number --diag_warning=225 --ptrdiff_size=32 --preproc_with_compile --preproc_dependency="audioProcessing.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

ezdsp5502.obj: ../ezdsp5502.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"D:/ti/ccsv6/tools/compiler/c5500_4.4.1/bin/cl55" -v5502 --memory_model=large -g --include_path="D:/ti/ccsv6/tools/compiler/c5500_4.4.1/include" --include_path="Z:/Semester8/Real-Time DSP/Projects/Real-TimeDSP/C55xxCSL/include" --include_path="Z:/Semester8/Real-Time DSP/Projects/Real-TimeDSP/include" --include_path="Z:/Semester8/Real-Time DSP/Projects/Real-TimeDSP/programs/AGC/Debug" --include_path="D:/ti/bios_5_42_01_09/packages/ti/bios/include" --include_path="D:/ti/bios_5_42_01_09/packages/ti/rtdx/include/c5500" --define=c5502 --display_error_number --diag_warning=225 --ptrdiff_size=32 --preproc_with_compile --preproc_dependency="ezdsp5502.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

ezdsp5502_gpio.obj: ../ezdsp5502_gpio.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"D:/ti/ccsv6/tools/compiler/c5500_4.4.1/bin/cl55" -v5502 --memory_model=large -g --include_path="D:/ti/ccsv6/tools/compiler/c5500_4.4.1/include" --include_path="Z:/Semester8/Real-Time DSP/Projects/Real-TimeDSP/C55xxCSL/include" --include_path="Z:/Semester8/Real-Time DSP/Projects/Real-TimeDSP/include" --include_path="Z:/Semester8/Real-Time DSP/Projects/Real-TimeDSP/programs/AGC/Debug" --include_path="D:/ti/bios_5_42_01_09/packages/ti/bios/include" --include_path="D:/ti/bios_5_42_01_09/packages/ti/rtdx/include/c5500" --define=c5502 --display_error_number --diag_warning=225 --ptrdiff_size=32 --preproc_with_compile --preproc_dependency="ezdsp5502_gpio.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

ezdsp5502_i2c.obj: ../ezdsp5502_i2c.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"D:/ti/ccsv6/tools/compiler/c5500_4.4.1/bin/cl55" -v5502 --memory_model=large -g --include_path="D:/ti/ccsv6/tools/compiler/c5500_4.4.1/include" --include_path="Z:/Semester8/Real-Time DSP/Projects/Real-TimeDSP/C55xxCSL/include" --include_path="Z:/Semester8/Real-Time DSP/Projects/Real-TimeDSP/include" --include_path="Z:/Semester8/Real-Time DSP/Projects/Real-TimeDSP/programs/AGC/Debug" --include_path="D:/ti/bios_5_42_01_09/packages/ti/bios/include" --include_path="D:/ti/bios_5_42_01_09/packages/ti/rtdx/include/c5500" --define=c5502 --display_error_number --diag_warning=225 --ptrdiff_size=32 --preproc_with_compile --preproc_dependency="ezdsp5502_i2c.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

ezdsp5502_i2cgpio.obj: ../ezdsp5502_i2cgpio.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"D:/ti/ccsv6/tools/compiler/c5500_4.4.1/bin/cl55" -v5502 --memory_model=large -g --include_path="D:/ti/ccsv6/tools/compiler/c5500_4.4.1/include" --include_path="Z:/Semester8/Real-Time DSP/Projects/Real-TimeDSP/C55xxCSL/include" --include_path="Z:/Semester8/Real-Time DSP/Projects/Real-TimeDSP/include" --include_path="Z:/Semester8/Real-Time DSP/Projects/Real-TimeDSP/programs/AGC/Debug" --include_path="D:/ti/bios_5_42_01_09/packages/ti/bios/include" --include_path="D:/ti/bios_5_42_01_09/packages/ti/rtdx/include/c5500" --define=c5502 --display_error_number --diag_warning=225 --ptrdiff_size=32 --preproc_with_compile --preproc_dependency="ezdsp5502_i2cgpio.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

ezdsp5502_mcbsp.obj: ../ezdsp5502_mcbsp.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"D:/ti/ccsv6/tools/compiler/c5500_4.4.1/bin/cl55" -v5502 --memory_model=large -g --include_path="D:/ti/ccsv6/tools/compiler/c5500_4.4.1/include" --include_path="Z:/Semester8/Real-Time DSP/Projects/Real-TimeDSP/C55xxCSL/include" --include_path="Z:/Semester8/Real-Time DSP/Projects/Real-TimeDSP/include" --include_path="Z:/Semester8/Real-Time DSP/Projects/Real-TimeDSP/programs/AGC/Debug" --include_path="D:/ti/bios_5_42_01_09/packages/ti/bios/include" --include_path="D:/ti/bios_5_42_01_09/packages/ti/rtdx/include/c5500" --define=c5502 --display_error_number --diag_warning=225 --ptrdiff_size=32 --preproc_with_compile --preproc_dependency="ezdsp5502_mcbsp.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

fir2.obj: ../fir2.asm $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"D:/ti/ccsv6/tools/compiler/c5500_4.4.1/bin/cl55" -v5502 --memory_model=large -g --include_path="D:/ti/ccsv6/tools/compiler/c5500_4.4.1/include" --include_path="Z:/Semester8/Real-Time DSP/Projects/Real-TimeDSP/C55xxCSL/include" --include_path="Z:/Semester8/Real-Time DSP/Projects/Real-TimeDSP/include" --include_path="Z:/Semester8/Real-Time DSP/Projects/Real-TimeDSP/programs/AGC/Debug" --include_path="D:/ti/bios_5_42_01_09/packages/ti/bios/include" --include_path="D:/ti/bios_5_42_01_09/packages/ti/rtdx/include/c5500" --define=c5502 --display_error_number --diag_warning=225 --ptrdiff_size=32 --preproc_with_compile --preproc_dependency="fir2.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

hellocfg.cmd: ../hello.tcf
	@echo 'Building file: $<'
	@echo 'Invoking: TConf'
	"D:/ti/bios_5_42_01_09/xdctools/tconf" -b -Dconfig.importPath="D:/ti/bios_5_42_01_09/packages;" "$<"
	@echo 'Finished building: $<'
	@echo ' '

hellocfg.s??: | hellocfg.cmd
hellocfg_c.c: | hellocfg.cmd
hellocfg.h: | hellocfg.cmd
hellocfg.h??: | hellocfg.cmd
hello.cdb: | hellocfg.cmd

hellocfg.obj: ./hellocfg.s?? $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"D:/ti/ccsv6/tools/compiler/c5500_4.4.1/bin/cl55" -v5502 --memory_model=large -g --include_path="D:/ti/ccsv6/tools/compiler/c5500_4.4.1/include" --include_path="Z:/Semester8/Real-Time DSP/Projects/Real-TimeDSP/C55xxCSL/include" --include_path="Z:/Semester8/Real-Time DSP/Projects/Real-TimeDSP/include" --include_path="Z:/Semester8/Real-Time DSP/Projects/Real-TimeDSP/programs/AGC/Debug" --include_path="D:/ti/bios_5_42_01_09/packages/ti/bios/include" --include_path="D:/ti/bios_5_42_01_09/packages/ti/rtdx/include/c5500" --define=c5502 --display_error_number --diag_warning=225 --ptrdiff_size=32 --preproc_with_compile --preproc_dependency="hellocfg.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

hellocfg_c.obj: ./hellocfg_c.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"D:/ti/ccsv6/tools/compiler/c5500_4.4.1/bin/cl55" -v5502 --memory_model=large -g --include_path="D:/ti/ccsv6/tools/compiler/c5500_4.4.1/include" --include_path="Z:/Semester8/Real-Time DSP/Projects/Real-TimeDSP/C55xxCSL/include" --include_path="Z:/Semester8/Real-Time DSP/Projects/Real-TimeDSP/include" --include_path="Z:/Semester8/Real-Time DSP/Projects/Real-TimeDSP/programs/AGC/Debug" --include_path="D:/ti/bios_5_42_01_09/packages/ti/bios/include" --include_path="D:/ti/bios_5_42_01_09/packages/ti/rtdx/include/c5500" --define=c5502 --display_error_number --diag_warning=225 --ptrdiff_size=32 --preproc_with_compile --preproc_dependency="hellocfg_c.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

main.obj: ../main.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"D:/ti/ccsv6/tools/compiler/c5500_4.4.1/bin/cl55" -v5502 --memory_model=large -g --include_path="D:/ti/ccsv6/tools/compiler/c5500_4.4.1/include" --include_path="Z:/Semester8/Real-Time DSP/Projects/Real-TimeDSP/C55xxCSL/include" --include_path="Z:/Semester8/Real-Time DSP/Projects/Real-TimeDSP/include" --include_path="Z:/Semester8/Real-Time DSP/Projects/Real-TimeDSP/programs/AGC/Debug" --include_path="D:/ti/bios_5_42_01_09/packages/ti/bios/include" --include_path="D:/ti/bios_5_42_01_09/packages/ti/rtdx/include/c5500" --define=c5502 --display_error_number --diag_warning=225 --ptrdiff_size=32 --preproc_with_compile --preproc_dependency="main.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

myFIR.obj: ../myFIR.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"D:/ti/ccsv6/tools/compiler/c5500_4.4.1/bin/cl55" -v5502 --memory_model=large -g --include_path="D:/ti/ccsv6/tools/compiler/c5500_4.4.1/include" --include_path="Z:/Semester8/Real-Time DSP/Projects/Real-TimeDSP/C55xxCSL/include" --include_path="Z:/Semester8/Real-Time DSP/Projects/Real-TimeDSP/include" --include_path="Z:/Semester8/Real-Time DSP/Projects/Real-TimeDSP/programs/AGC/Debug" --include_path="D:/ti/bios_5_42_01_09/packages/ti/bios/include" --include_path="D:/ti/bios_5_42_01_09/packages/ti/rtdx/include/c5500" --define=c5502 --display_error_number --diag_warning=225 --ptrdiff_size=32 --preproc_with_compile --preproc_dependency="myFIR.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

myNCO.obj: ../myNCO.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"D:/ti/ccsv6/tools/compiler/c5500_4.4.1/bin/cl55" -v5502 --memory_model=large -g --include_path="D:/ti/ccsv6/tools/compiler/c5500_4.4.1/include" --include_path="Z:/Semester8/Real-Time DSP/Projects/Real-TimeDSP/C55xxCSL/include" --include_path="Z:/Semester8/Real-Time DSP/Projects/Real-TimeDSP/include" --include_path="Z:/Semester8/Real-Time DSP/Projects/Real-TimeDSP/programs/AGC/Debug" --include_path="D:/ti/bios_5_42_01_09/packages/ti/bios/include" --include_path="D:/ti/bios_5_42_01_09/packages/ti/rtdx/include/c5500" --define=c5502 --display_error_number --diag_warning=225 --ptrdiff_size=32 --preproc_with_compile --preproc_dependency="myNCO.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

userInterface.obj: ../userInterface.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"D:/ti/ccsv6/tools/compiler/c5500_4.4.1/bin/cl55" -v5502 --memory_model=large -g --include_path="D:/ti/ccsv6/tools/compiler/c5500_4.4.1/include" --include_path="Z:/Semester8/Real-Time DSP/Projects/Real-TimeDSP/C55xxCSL/include" --include_path="Z:/Semester8/Real-Time DSP/Projects/Real-TimeDSP/include" --include_path="Z:/Semester8/Real-Time DSP/Projects/Real-TimeDSP/programs/AGC/Debug" --include_path="D:/ti/bios_5_42_01_09/packages/ti/bios/include" --include_path="D:/ti/bios_5_42_01_09/packages/ti/rtdx/include/c5500" --define=c5502 --display_error_number --diag_warning=225 --ptrdiff_size=32 --preproc_with_compile --preproc_dependency="userInterface.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


