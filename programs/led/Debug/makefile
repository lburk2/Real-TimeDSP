################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

CG_TOOL_ROOT := D:/ti/ccsv6/tools/compiler/c5500_4.4.1

GEN_OPTS__FLAG := 
GEN_CMDS__FLAG := 

ORDERED_OBJS += \
"./ezdsp5502.obj" \
"./ezdsp5502_gpio.obj" \
"./ezdsp5502_i2c.obj" \
"./ezdsp5502_i2cgpio.obj" \
"./ezdsp5502_mcbsp.obj" \
"./led_test.obj" \
"./main.obj" \
"../lnkx.cmd" \
$(GEN_CMDS__FLAG) \
-l"rts55x.lib" \
-l"csl5502x.lib" \

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
led.out \

EXE_OUTPUTS__QUOTED += \
"led.out" \

BIN_OUTPUTS += \
led.hex \

BIN_OUTPUTS__QUOTED += \
"led.hex" \


# All Target
all: led.out

# Tool invocations
led.out: $(OBJS) $(CMD_SRCS) $(GEN_CMDS)
	@echo 'Building target: $@'
	@echo 'Invoking: C5500 Linker'
	"D:/ti/ccsv6/tools/compiler/c5500_4.4.1/bin/cl55" -v5502 --memory_model=large -g --define=c5502 --diag_warning=225 --ptrdiff_size=32 -z -m"led.map" --stack_size=0x200 --heap_size=0x400 -i"D:/ti/ccsv6/tools/compiler/c5500_4.4.1/lib" -i"Z:/Documents/Academics/temp/ezdsp5502_v1/lib" -i"D:/ti/ccsv6/tools/compiler/c5500_4.4.1/include" -i"C:/Users/lando/iCloudDrive/Documents/Semester8/Real-Time DSP/ezdsp5502_v1_spring2023/C55xxCSL/lib" -i"C:/Users/lando/iCloudDrive/Documents/Semester8/Real-Time DSP/ezdsp5502_v1_spring2023/lib" --reread_libs --warn_sections --xml_link_info="led_linkInfo.xml" --rom_model --sys_stacksize=0x200 -o "led.out" $(ORDERED_OBJS)
	@echo 'Finished building target: $@'
	@echo ' '

led.hex: $(EXE_OUTPUTS)
	@echo 'Invoking: C5500 Hex Utility'
	"D:/ti/ccsv6/tools/compiler/c5500_4.4.1/bin/hex55"  -o "led.hex" $(EXE_OUTPUTS__QUOTED)
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(EXE_OUTPUTS__QUOTED)$(BIN_OUTPUTS__QUOTED)
	-$(RM) "ezdsp5502.pp" "ezdsp5502_gpio.pp" "ezdsp5502_i2c.pp" "ezdsp5502_i2cgpio.pp" "ezdsp5502_mcbsp.pp" "led_test.pp" "main.pp" 
	-$(RM) "ezdsp5502.obj" "ezdsp5502_gpio.obj" "ezdsp5502_i2c.obj" "ezdsp5502_i2cgpio.obj" "ezdsp5502_mcbsp.obj" "led_test.obj" "main.obj" 
	-@echo 'Finished clean'
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

