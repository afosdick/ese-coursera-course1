#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# <Put a Description Here>
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <Put a description of the supported targets here>
#
# Platform Overrides:
#      <Put a description of the supported Overrides here
#
#------------------------------------------------------------------------------
include sources.mk

# Switching based on Platform
ifeq ($(PLATFORM), HOST)
# Architectures Specific Flags
CC = gcc
CPU = 
ARCH = 
SPECS = 
LINKER_FILE = 
LDFLAGS = -Wl,-Map=$(TARGET).map
CFLAGS = -Wall
SOURCES = $(COMMON_SOURCES)
INCLUDES = $(COMMON_INCLUDES)
else
ifeq ($(PLATFORM), MSP432)
# Architectures Specific Flags
CC = arm-none-eabi-gcc
CPU = cortex-m4
ARCH = armv7e-m
SPECS = nosys.specs
LINKER_FILE = ../msp432p401r.lds
LDFLAGS = -Wl,-Map=$(TARGET).map -T $(LINKER_FILE)
CFLAGS = -mcpu=$(CPU) -march=$(ARCH) --specs=$(SPECS) -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16
SOURCES = $(COMMON_SOURCES) $(MSP432_SOURCES)
INCLUDES = $(COMMON_INCLUDES) $(MSP432_INCLUDES)
else
$(error Please specify Platform: HOST or MSP432)
endif
endif
TARGET = c1m2
COMMON_FLAGS = -Wall -Werror -g -O0 -std=c99 -D$(PLATFORM)
INCLUDE_FLAGS = $(addprefix -I, $(INCLUDES))
OBJS = $(SOURCES:.c=.o)
PREPROCESSED = $(SOURCES:.c=.i)
ASSEMBLY = $(SOURCES:.c=.asm)


.PHONY: all
all: $(TARGET).out

.PHONY: build
build: $(TARGET).out

.PHONY: compile-all
compile-all: $(OBJS)

$(TARGET).out : $(OBJS)
	$(CC) $(COMMON_FLAGS) $(OBJS) $(CFLAGS) $(LDFLAGS) -o $@
	size $@

%.o : %.c
	$(CC) $(COMMON_FLAGS) $(INCLUDE_FLAGS) -c $< $(CFLAGS) -o $@

%.d : %.c
	$(CC) $(COMMON_FLAGS) $(INCLUDE_FLAGS) -S $< $(CFLAGS) -o $@ -M

%.asm : %.c
	$(CC) $(COMMON_FLAGS) $(INCLUDE_FLAGS) -S $< $(CFLAGS) -o $@

%.i : %.c
	$(CC) $(COMMON_FLAGS) $(INCLUDE_FLAGS) -E $< $(CFLAGS) -o $@

.PHONY: clean
clean:
	rm -f $(ASSEMBLY) $(PREPROCESSED) $(OBJS) $(TARGET).out $(TARGET).map
