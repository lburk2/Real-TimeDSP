################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

CG_TOOL_ROOT := D:/ti/ccsv6/tools/compiler/c5500_4.4.1

GEN_OPTS__FLAG := 
GEN_CMDS__FLAG := 

ORDERED_OBJS += \
"./aic3204.obj" \
"./ezdsp5502.obj" \
"./ezdsp5502_gpio.obj" \
"./ezdsp5502_i2c.obj" \
"./ezdsp5502_i2cgpio.obj" \
"./ezdsp5502_mcbsp.obj" \
"./main.obj" \
"./myFIR.obj" \
"../lnkx.cmd" \
$(GEN_CMDS__FLAG) \
-l"csl5502x.lib" \
-l"ezdsp5502bsl.lib" \
-l"rts55x.lib" \

-include ../makefile.init

RM := DEL /F
RMDIR := RMDIR /S/Q

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir_vars.mk
-include subdir_rules.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(S62_DEPS)),)
-include $(S62_DEPS)
endif
ifneq ($(strip $(C64_DEPS)),)
-include $(C64_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(S55_DEPS)),)
-include $(S55_DEPS)
endif
ifneq ($(strip $(C67_DEPS)),)
-include $(C67_DEPS)
endif
ifneq ($(strip $(CLA_DEPS)),)
-include $(CLA_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(S??_DEPS)),)
-include $(S??_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(C62_DEPS)),)
-include $(C62_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(K_DEPS)),)
-include $(K_DEPS)
endif
ifneq ($(strip $(C43_DEPS)),)
-include $(C43_DEPS)
endif
ifneq ($(strip $(INO_DEPS)),)
-include $(INO_DEPS)
endif
ifneq ($(strip $(S67_DEPS)),)
-include $(S67_DEPS)
endif
ifneq ($(strip $(SA_DEPS)),)
-include $(SA_DEPS)
endif
ifneq ($(strip $(S43_DEPS)),)
-include $(S43_DEPS)
endif
ifneq ($(strip $(OPT_DEPS)),)
-include $(OPT_DEPS)
endif
ifneq ($(strip $(PDE_DEPS)),)
-include $(PDE_DEPS)
endif
ifneq ($(strip $(S64_DEPS)),)
-include $(S64_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(C55_DEPS)),)
-include $(C55_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXE_OUTPUTS += \
FIR.out \

EXE_OUTPUTS__QUOTED += \
"FIR.out" \

BIN_OUTPUTS += \
FIR.hex \

BIN_OUTPUTS__QUOTED += \
"FIR.hex" \


# All Target
all: FIR.out

# Tool invocations
FIR.out: $(OBJS) $(CMD_SRCS) $(GEN_CMDS)
	@echo 'Building target: $@'
	@echo 'Invoking: C5500 Linker'
	"D:/ti/ccsv6/tools/compiler/c5500_4.4.1/bin/cl55" --memory_model=small -g --display_error_number --diag_warning=225 --ptrdiff_size=16 -z -m"FIR.map" -i"D:/ti/ccsv6/tools/compiler/c5500_4.4.1/lib" -i"Z:/Semester8/Real-Time DSP/Projects/Real-TimeDSP/lib" -i"Z:/Semester8/Real-Time DSP/Projects/Real-TimeDSP/C55xxCSL/lib" -i"D:/ti/ccsv6/tools/compiler/c5500_4.4.1/include" --reread_libs --display_error_number --warn_sections --xml_link_info="FIR_linkInfo.xml" --rom_model -o "FIR.out" $(ORDERED_OBJS)
	@echo 'Finished building target: $@'
	@echo ' '

FIR.hex: $(EXE_OUTPUTS)
	@echo 'Invoking: C5500 Hex Utility'
	"D:/ti/ccsv6/tools/compiler/c5500_4.4.1/bin/hex55"  -o "FIR.hex" $(EXE_OUTPUTS__QUOTED)
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(EXE_OUTPUTS__QUOTED)$(BIN_OUTPUTS__QUOTED)
	-$(RM) "aic3204.pp" "ezdsp5502.pp" "ezdsp5502_gpio.pp" "ezdsp5502_i2c.pp" "ezdsp5502_i2cgpio.pp" "ezdsp5502_mcbsp.pp" "main.pp" "myFIR.pp" 
	-$(RM) "aic3204.obj" "ezdsp5502.obj" "ezdsp5502_gpio.obj" "ezdsp5502_i2c.obj" "ezdsp5502_i2cgpio.obj" "ezdsp5502_mcbsp.obj" "main.obj" "myFIR.obj" 
	-@echo 'Finished clean'
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

