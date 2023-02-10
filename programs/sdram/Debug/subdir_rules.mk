################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
main.obj: ../main.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"D:/ti/ccsv6/tools/compiler/c5500_4.4.1/bin/cl55" -v5502 -g --include_path="D:/ti/ccsv6/tools/compiler/c5500_4.4.1/include" --include_path="C:/Users/lando/iCloudDrive/Documents/Semester8/Real-Time DSP/ezdsp5502_v1_spring2023/ezdsp5502_v1_spring2023/C55xxCSL/include" --include_path="C:/Users/lando/iCloudDrive/Documents/Semester8/Real-Time DSP/ezdsp5502_v1_spring2023/ezdsp5502_v1_spring2023/include" --diag_warning=225 --ptrdiff_size=32 --memory_model=large --preproc_with_compile --preproc_dependency="main.d" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

sdram_test.obj: ../sdram_test.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"D:/ti/ccsv6/tools/compiler/c5500_4.4.1/bin/cl55" -v5502 -g --include_path="D:/ti/ccsv6/tools/compiler/c5500_4.4.1/include" --include_path="C:/Users/lando/iCloudDrive/Documents/Semester8/Real-Time DSP/ezdsp5502_v1_spring2023/ezdsp5502_v1_spring2023/C55xxCSL/include" --include_path="C:/Users/lando/iCloudDrive/Documents/Semester8/Real-Time DSP/ezdsp5502_v1_spring2023/ezdsp5502_v1_spring2023/include" --diag_warning=225 --ptrdiff_size=32 --memory_model=large --preproc_with_compile --preproc_dependency="sdram_test.d" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


