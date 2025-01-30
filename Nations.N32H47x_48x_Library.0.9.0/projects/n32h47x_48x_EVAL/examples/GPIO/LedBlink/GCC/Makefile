# Directories
SRC_DIR = ../src
BUILD_DIR = ../build
INC_DIR = ../inc \
          -IC:\Users\Arjun\Desktop\Nations.N32H47x_48x_Library.0.9.0\firmware\CMSIS\core \
          -IC:\Users\Arjun\Desktop\Nations.N32H47x_48x_Library.0.9.0\firmware\CMSIS\device \
          -IC:\Users\Arjun\Desktop\Nations.N32H47x_48x_Library.0.9.0\firmware\n32h47x_48x_std_periph_driver/inc

# Compiler and linker flags
CC = arm-none-eabi-gcc
AS = arm-none-eabi-as
LD = arm-none-eabi-ld
CFLAGS = -mcpu=cortex-m4 -mthumb -Wall -O2 -g -std=gnu11 -I$(INC_DIR)
LDFLAGS = -T C:\Users\Arjun\Desktop\Nations.N32H47x_48x_Library.0.9.0\firmware\CMSIS\device\n32h473_flash.ld

# Files
SRCS = $(wildcard $(SRC_DIR)/*.c) \
       C:\Users\Arjun\Desktop\Nations.N32H47x_48x_Library.0.9.0\firmware\n32h47x_48x_std_periph_driver/src/*.c
OBJS = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRCS))
STARTUP = C:\Users\Arjun\Desktop\Nations.N32H47x_48x_Library.0.9.0\firmware\CMSIS\device\startup\startup_n32h473.s
TARGET = $(BUILD_DIR)/LedBlink.elf

# Rules
all: $(BUILD_DIR) $(TARGET)

$(BUILD_DIR):
	@if not exist $(BUILD_DIR) mkdir $(BUILD_DIR)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@echo "Compiling $<"
	@$(CC) $(CFLAGS) -c $< -o $@

$(TARGET): $(OBJS)
	@echo "Linking $@"
	@$(CC) $(OBJS) $(STARTUP) $(LDFLAGS) -o $@

clean:
	@echo "Cleaning up..."
	@rm -rf $(BUILD_DIR)
