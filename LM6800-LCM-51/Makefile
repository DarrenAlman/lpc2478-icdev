# ============================================================
# USBHostLite Makefile
# Yecunkui
# 2011/03/23
# Version 1.1
# ============================================================

# Target related
TARGETNAME	=	lcdtest
TARGETDIR	= 	./
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
CFLAGS  = -I./ -I$(TARGETDIR) -I/media/Program/Keil/C51/INC/SST -I/media/Program/Keil/C51/INC/ -c -W -Wall -g -mcpu=arm7tdmi
ASFLAGS = -c -g -Wa,-ahlms=$*.lst,-mapcs-32 -mcpu=arm7tdmi
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
LINKFILE	= 

# C source files
CSRCS = main.c lpc2478_lcd.c
		

# Assembler source files				
ASRCS = 

# Object files				
COBJS	= $(CSRCS:.c=.o)
AOBJS 	= $(ASRCS:.S=.o)

# Default target	
all: $(TARGETNAME)

$(TARGETNAME): $(AOBJS) $(COBJS)	
	@ echo
	@ echo Linking: $@.elf
	$(CC) -T $(LINKFILE) $(LFLAGS) $^ -o $@.elf -Wl,-Map,$@.map,-lgcc,-L$(LSEARCHGCC)
	$(CP) $(CPFLAGS) $@.elf $@.hex
	$(OD) $(ODFLAGS) $@.elf > $@.dmp


# Assemble: create object files from assembler source files.
$(AOBJS) : %.o : %.s
	@echo
	@echo Assembling: $<
	$(CC) $(ASFLAGS) $< -o  $@

# dependency checking
depend: $(CSRCS)
	@echo "make depend"
	$(CC) $(CFLAGS) -MM $^ > .depend || rm -f .depend

# Target: clean project.
clean:
	@ echo
	@ echo Cleaning project:
	$(RM) -f *.OBJ *.hex *.lnp *.LST *.dmp *.map .depend $(TARGETNAME) *.M51 *.plg *.bak

# Listing of phony targets.
.PHONY : all clean

-include .depend
