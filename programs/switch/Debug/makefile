################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

CG_TOOL_ROOT := D:/ti/ccsv6/tools/compiler/c5500_4.4.1

GEN_OPTS__FLAG := 
GEN_CMDS__FLAG := 

ORDERED_OBJS += \
"./main.obj" \
"./switch_test.obj" \
"../lnkx.cmd" \
$(GEN_CMDS__FLAG) \
-lcsl5502x.lib \
-lezdsp5502bsl.lib \
-lrts55x.lib \

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
ifneq ($(strip $(SV7A_DEPS)),)
-include $(SV7A_DEPS)
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
switch.out \

EXE_OUTPUTS__QUOTED += \
"switch.out" \


# All Target
all: switch.out

dependents:
	-cd C:/Users/lando/iCloudDrive/Documents/Semester8/Real-Time\ DSP/ezdsp5502_v1_spring2023/ezdsp5502_v1_spring2023/lib/Debug && $(MAKE) clean all

# Tool invocations
switch.out: $(OBJS) $(CMD_SRCS) $(GEN_CMDS) C:/Users/lando/iCloudDrive/Documents/Semester8/Real-Time\ DSP/ezdsp5502_v1_spring2023/ezdsp5502_v1_spring2023/lib/Debug/../ezdsp5502bsl.lib
	@echo 'Building target: $@'
	@echo 'Invoking: C5500 Linker'
	"D:/ti/ccsv6/tools/compiler/c5500_4.4.1/bin/cl55" -v5502 -g --diag_warning=225 --ptrdiff_size=32 --memory_model=large -z -m"switch.map" --warn_sections -i"D:/ti/ccsv6/tools/compiler/c5500_4.4.1/lib" -i"D:/ti/ccsv6/tools/compiler/c5500_4.4.1/include" -i"C:/Users/lando/iCloudDrive/Documents/Semester8/Real-Time DSP/ezdsp5502_v1_spring2023/ezdsp5502_v1_spring2023/C55xxCSL/lib" -i"C:/Users/lando/iCloudDrive/Documents/Semester8/Real-Time DSP/ezdsp5502_v1_spring2023/ezdsp5502_v1_spring2023/lib" --reread_libs --xml_link_info="switch_linkInfo.xml" --rom_model -o "switch.out" $(ORDERED_OBJS)
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(EXE_OUTPUTS__QUOTED)
	-$(RM) "main.d" "switch_test.d" 
	-$(RM) "main.obj" "switch_test.obj" 
	-@echo 'Finished clean'
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:
C:/Users/lando/iCloudDrive/Documents/Semester8/Real-Time\ DSP/ezdsp5502_v1_spring2023/ezdsp5502_v1_spring2023/lib/Debug/../ezdsp5502bsl.lib:

-include ../makefile.targets

