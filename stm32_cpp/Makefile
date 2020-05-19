######################################
# target
######################################
TARGET = stm32cpp

#######################################
# paths
#######################################
# Build path
BUILD_DIR = build

######################################
# building variables
######################################
# debug build?
DEBUG = 1
# optimization
OPT = -Og

#######################################
# binaries
#######################################
GCC_PATH = /opt/Atollic_TrueSTUDIO_for_STM32_x86_64_9.1.0/ARMTools/bin
PREFIX = arm-atollic-eabi-
# The gcc compiler bin path can be either defined in make command via GCC_PATH variable (> make GCC_PATH=xxx)
# either it can be added to the PATH environment variable.
CC = $(GCC_PATH)/$(PREFIX)g++
AS = $(GCC_PATH)/$(PREFIX)g++ -x assembler-with-cpp
CP = $(GCC_PATH)/$(PREFIX)objcopy
SZ = $(GCC_PATH)/$(PREFIX)size

#######################################
# CFLAGS
#######################################
# cpu
CPPVER = -std=c++17
CPU = -mcpu=cortex-m3

# mcu
MCU = $(CPU) -mthumb

# lib
LIB = -DUSE_FULL_LL_DRIVER

# parameters
PARAM = -DHSE_VALUE=8000000 -DHSE_STARTUP_TIMEOUT=100 -DLSE_STARTUP_TIMEOUT=5000 -DLSE_VALUE=32768 -DHSI_VALUE=8000000 -DLSI_VALUE=40000 -DVDD_VALUE=3300 -DPREFETCH_ENABLE=1

# C defines
C_DEFS =  \
-DSTM32F103xE

# C includes
C_INCLUDES =  \
-IInc

# compile gcc flags
CFLAGS = $(CPPVER) $(MCU) $(LIB) $(PARAM) $(C_DEFS) $(C_INCLUDES) $(OPT) -Wall -fdata-sections -ffunction-sections

ifeq ($(DEBUG), 1)
CFLAGS += -g -gdwarf-2
endif

# Generate dependency information
CFLAGS += -MMD -MP

#######################################
# LDFLAGS
#######################################
# link script
LDSCRIPT = STM32F103VETx_FLASH.ld

# libraries
LIBS = -lc -lm -lnosys 
LIBDIR = 
LDFLAGS = $(MCU) -specs=nano.specs -specs=nosys.specs -T$(LDSCRIPT) $(LIBDIR) $(LIBS) -Wl,-Map=$(BUILD_DIR)/$(TARGET).map,--cref -Wl,--gc-sections


ASM_SOURCES =  \
startup_stm32f103xe.s

C_SOURCES = \
Src/main.cc \
Src/system_stm32f1xx.c

#######################################
# Directory
#######################################
DIRS = Src

# list of objects
C_SOURCES = $(shell find $(DIRS) -type f -name "*.c")
OBJECTS = $(addprefix $(BUILD_DIR)/,$(notdir $(patsubst %.c,%.o,$(C_SOURCES))))

CPP_SOURCES = $(shell find $(DIRS) -type f -name "*.cc")
OBJECTS += $(addprefix $(BUILD_DIR)/,$(notdir $(patsubst %.cc,%.o,$(CPP_SOURCES))))

ASM_SOURCES = $(shell find $(DIRS) -type f -name "*.s")
OBJECTS += $(addprefix $(BUILD_DIR)/,$(notdir $(patsubst %.s,%.o,$(ASM_SOURCES))))

all: $(BUILD_DIR)/$(TARGET).elf $(BUILD_DIR)/$(TARGET).hex $(BUILD_DIR)/$(TARGET).bin

$(BUILD_DIR)/%.o: $(DIRS)/%.cc
	$(CC) -c $(CFLAGS) -MF$(addprefix $(BUILD_DIR)/,$(notdir $(patsubst %.cc,%.d,$<))) -Wa,-a,-ad,-alms=$(addprefix $(BUILD_DIR)/,$(notdir $(patsubst %.cc,%.lst,$<))) $< -o $@

$(BUILD_DIR)/%.o: $(DIRS)/%.c
	$(CC) -c $(CFLAGS) -MF$(addprefix $(BUILD_DIR)/,$(notdir $(patsubst %.c,%.d,$<))) -Wa,-a,-ad,-alms=$(addprefix $(BUILD_DIR)/,$(notdir $(patsubst %.c,%.lst,$<))) $< -o $@

$(BUILD_DIR)/%.o: $(DIRS)/%.s
	$(AS) -c $(CFLAGS) -MF$(addprefix $(BUILD_DIR)/,$(notdir $(patsubst %.s,%.d,$<))) $< -o $@

$(BUILD_DIR)/$(TARGET).elf: $(BUILD_DIR) $(OBJECTS)
	$(CC) $(OBJECTS) $(LDFLAGS) -o $@
	$(SZ) $@

$(BUILD_DIR)/%.hex: $(BUILD_DIR)/%.elf | $(BUILD_DIR)
	$(CP) -O ihex $< $@

$(BUILD_DIR)/%.bin: $(BUILD_DIR)/%.elf | $(BUILD_DIR)
	$(CP) -O binary -S $< $@
	$(RM) $(BUILD_DIR)/*.d
	$(RM) $(BUILD_DIR)/*.lst

$(BUILD_DIR):
	mkdir $@

clean :
	$(RM) $(BUILD_DIR) -rf

