################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
enet.obj: ../enet.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"D:/ti/ccsv6/tools/compiler/c5500_4.4.1/bin/cl55" -v5502 -g --include_path="D:/ti/ccsv6/tools/compiler/c5500_4.4.1/include" --include_path="Z:/Semester8/Real-Time DSP/Projects/Real-TimeDSP/C55xxCSL/include" --include_path="../../../include" --diag_warning=225 --ptrdiff_size=32 --memory_model=large --preproc_with_compile --preproc_dependency="enet.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

enet_test.obj: ../enet_test.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"D:/ti/ccsv6/tools/compiler/c5500_4.4.1/bin/cl55" -v5502 -g --include_path="D:/ti/ccsv6/tools/compiler/c5500_4.4.1/include" --include_path="Z:/Semester8/Real-Time DSP/Projects/Real-TimeDSP/C55xxCSL/include" --include_path="../../../include" --diag_warning=225 --ptrdiff_size=32 --memory_model=large --preproc_with_compile --preproc_dependency="enet_test.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

main.obj: ../main.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"D:/ti/ccsv6/tools/compiler/c5500_4.4.1/bin/cl55" -v5502 -g --include_path="D:/ti/ccsv6/tools/compiler/c5500_4.4.1/include" --include_path="Z:/Semester8/Real-Time DSP/Projects/Real-TimeDSP/C55xxCSL/include" --include_path="../../../include" --diag_warning=225 --ptrdiff_size=32 --memory_model=large --preproc_with_compile --preproc_dependency="main.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


