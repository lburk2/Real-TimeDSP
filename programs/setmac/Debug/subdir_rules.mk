################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
enet.obj: ../enet.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"D:/ti/ccsv6/tools/compiler/c5500_4.4.1/bin/cl55" -v5502 -g --include_path="D:/ti/ccsv6/tools/compiler/c5500_4.4.1/include" --include_path="Z:/Semester8/Real-Time DSP/Projects/Real-TimeDSP/C55xxCSL/include" --include_path="../../../include" --display_error_number --issue_remarks --verbose_diagnostics --diag_warning=225 --large_memory_model --ptrdiff_size=32 --memory_model=large --preproc_with_compile --preproc_dependency="enet.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

setmac.obj: ../setmac.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"D:/ti/ccsv6/tools/compiler/c5500_4.4.1/bin/cl55" -v5502 -g --include_path="D:/ti/ccsv6/tools/compiler/c5500_4.4.1/include" --include_path="Z:/Semester8/Real-Time DSP/Projects/Real-TimeDSP/C55xxCSL/include" --include_path="../../../include" --display_error_number --issue_remarks --verbose_diagnostics --diag_warning=225 --large_memory_model --ptrdiff_size=32 --memory_model=large --preproc_with_compile --preproc_dependency="setmac.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


