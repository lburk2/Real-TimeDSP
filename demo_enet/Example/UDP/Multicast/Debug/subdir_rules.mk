################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
common.obj: C:/Users/lando/iCloudDrive/Documents/Semester8/Real-Time\ DSP/ezdsp5502_v1_spring2023/ezdsp5502_v1_spring2023/demo_enet/common/common.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"D:/ti/ccsv6/tools/compiler/c5500_4.4.1/bin/cl55" -v5502 -g --include_path="D:/ti/ccsv6/tools/compiler/c5500_4.4.1/include" --include_path="/packages/ti/xdais" --include_path="/include" --quiet --display_error_number --issue_remarks --verbose_diagnostics --diag_warning=225 --large_memory_model --ptrdiff_size=32 --memory_model=large --preproc_with_compile --preproc_dependency="common.d" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

cprintf.obj: C:/Users/lando/iCloudDrive/Documents/Semester8/Real-Time\ DSP/ezdsp5502_v1_spring2023/ezdsp5502_v1_spring2023/demo_enet/common/cprintf.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"D:/ti/ccsv6/tools/compiler/c5500_4.4.1/bin/cl55" -v5502 -g --include_path="D:/ti/ccsv6/tools/compiler/c5500_4.4.1/include" --include_path="/packages/ti/xdais" --include_path="/include" --quiet --display_error_number --issue_remarks --verbose_diagnostics --diag_warning=225 --large_memory_model --ptrdiff_size=32 --memory_model=large --preproc_with_compile --preproc_dependency="cprintf.d" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

dskemif.obj: C:/Users/lando/iCloudDrive/Documents/Semester8/Real-Time\ DSP/ezdsp5502_v1_spring2023/ezdsp5502_v1_spring2023/demo_enet/DSK/dskemif.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"D:/ti/ccsv6/tools/compiler/c5500_4.4.1/bin/cl55" -v5502 -g --include_path="D:/ti/ccsv6/tools/compiler/c5500_4.4.1/include" --include_path="/packages/ti/xdais" --include_path="/include" --quiet --display_error_number --issue_remarks --verbose_diagnostics --diag_warning=225 --large_memory_model --ptrdiff_size=32 --memory_model=large --preproc_with_compile --preproc_dependency="dskemif.d" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

dskpll.obj: C:/Users/lando/iCloudDrive/Documents/Semester8/Real-Time\ DSP/ezdsp5502_v1_spring2023/ezdsp5502_v1_spring2023/demo_enet/DSK/dskpll.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"D:/ti/ccsv6/tools/compiler/c5500_4.4.1/bin/cl55" -v5502 -g --include_path="D:/ti/ccsv6/tools/compiler/c5500_4.4.1/include" --include_path="/packages/ti/xdais" --include_path="/include" --quiet --display_error_number --issue_remarks --verbose_diagnostics --diag_warning=225 --large_memory_model --ptrdiff_size=32 --memory_model=large --preproc_with_compile --preproc_dependency="dskpll.d" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

lcd.obj: C:/Users/lando/iCloudDrive/Documents/Semester8/Real-Time\ DSP/ezdsp5502_v1_spring2023/ezdsp5502_v1_spring2023/demo_enet/common/lcd.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"D:/ti/ccsv6/tools/compiler/c5500_4.4.1/bin/cl55" -v5502 -g --include_path="D:/ti/ccsv6/tools/compiler/c5500_4.4.1/include" --include_path="/packages/ti/xdais" --include_path="/include" --quiet --display_error_number --issue_remarks --verbose_diagnostics --diag_warning=225 --large_memory_model --ptrdiff_size=32 --memory_model=large --preproc_with_compile --preproc_dependency="lcd.d" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

multicast.obj: ../multicast.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"D:/ti/ccsv6/tools/compiler/c5500_4.4.1/bin/cl55" -v5502 -g --include_path="D:/ti/ccsv6/tools/compiler/c5500_4.4.1/include" --include_path="/packages/ti/xdais" --include_path="/include" --quiet --display_error_number --issue_remarks --verbose_diagnostics --diag_warning=225 --large_memory_model --ptrdiff_size=32 --memory_model=large --preproc_with_compile --preproc_dependency="multicast.d" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

oled_printf.obj: C:/Users/lando/iCloudDrive/Documents/Semester8/Real-Time\ DSP/ezdsp5502_v1_spring2023/ezdsp5502_v1_spring2023/demo_enet/common/oled_printf.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"D:/ti/ccsv6/tools/compiler/c5500_4.4.1/bin/cl55" -v5502 -g --include_path="D:/ti/ccsv6/tools/compiler/c5500_4.4.1/include" --include_path="/packages/ti/xdais" --include_path="/include" --quiet --display_error_number --issue_remarks --verbose_diagnostics --diag_warning=225 --large_memory_model --ptrdiff_size=32 --memory_model=large --preproc_with_compile --preproc_dependency="oled_printf.d" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


