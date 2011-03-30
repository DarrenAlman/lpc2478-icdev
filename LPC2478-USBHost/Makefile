# ============================================================
# USBHostLite Makefile
# Yecunkui
# 2011/03/23
# Version 1.1
# ============================================================

# Target related
TARGETNAME	=	usbhost
TARGETDIR	= 	./UsbHost
TOOLCHAINPREFIX	= arm-none-eabi#定义toolchain的前缀
# Tool definitions
CC	= $(TOOLCHAINPREFIX)-gcc
LD	= $(TOOLCHAINPREFIX)-ld 
AR	= $(TOOLCHAINPREFIX)-ar
AS	= $(TOOLCHAINPREFIX)-as
CP	= $(TOOLCHAINPREFIX)-objcopy
OD	= $(TOOLCHAINPREFIX)-objdump
RM	= rm

# Tool flags
CFLAGS  = -I./ -I./UsbHost -c -W -Wall -g -mcpu=arm7tdmi
ASFLAGS = -c -Wa,-ahlms=$*.lst,-mapcs-32
LFLAGS  = -v -nostartfiles --warn-common
CPFLAGS = -O ihex
ODFLAGS	= -x --syms


# set virtual path
vpath %.c $(SRCDIR)
vpath %.S $(SRCDIR)
vpath %.o $(SRCDIR)
# Add a link library path
LSEARCHGCC = "/home/fanghuaqi/CodeSourcery/Sourcery_G++_Lite/lib/gcc/arm-none-eabi/4.4.1"

# Linker script
LINKFILE	= $(TARGETDIR)/lpc2478_RAM.ld

# C source files
CSRCS = target.c UsbHost/LPC2478clk.c UsbHost/LPC2478hw.c UsbHost/lpc_i2c.c \
		UsbHost/mystring.c UsbHost/usbhost_fat.c UsbHost/usbhost_lpc2468.c \
		UsbHost/usbhost_main.c UsbHost/usbhost_ms.c UsbHost/usbhost_uart.c

# Assembler source files				
ASRCS = start.S

# Object files				
COBJS	= $(CSRCS:.c=.o)
AOBJS = $(ASRCS:.S=.o)

# Default target	
all: $(TARGETNAME)

$(TARGETNAME): $(COBJS)	$(AOBJS)
	@ echo
	@ echo Linking: $@.elf
	$(CC) -T $(LINKFILE) $(LFLAGS) $^ -o $@.elf -Wl,-Map,$@.map,-lgcc,-L$(LSEARCHGCC)
	$(CP) $(CPFLAGS) $@.elf $@.hex
	$(OD) $(ODFLAGS) $@.elf > $@.dmp


# Assemble: create object files from assembler source files.
$(AOBJS) : %.o : %.S
	@echo
	@echo Assembling: $<
	$(CC) $(ASFLAGS) $< -o $@

# dependency checking
depend: $(CSRCS)
	@echo "make depend"
	$(CC) $(CFLAGS) -MM $^ > .depend || rm -f .depend

# Target: clean project.
clean:
	@ echo
	@ echo Cleaning project:
	$(RM) -f *.hex *.elf *.o *.lst *.dmp *.map .depend
	cd $(TARGETDIR);$(RM) -f *.hex *.elf *.o *.lst *.dmp *.map .depend

# Listing of phony targets.
.PHONY : all clean

-include .depend