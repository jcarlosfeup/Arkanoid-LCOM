# Makefile
# SIXTH LCOM lab

CC = gcc
AS = nasm
CFLAGS = -Wall -g -t
ASFLAGS = -t -g -f coff
OBJS_CC = main.o Sprite.o video-graphics.o int.o kbc.o sound.o speaker.o timer.o
OBJS_AS = isr.o isr_sound.o
EXTRAH = utypes.h
OUTFILE = arkanoid.exe

all: $(OUTFILE)

$(OUTFILE): $(EXTRAH) $(OBJS_CC) $(OBJS_AS)
	@echo Linking files ...
	@$(CC) $(CFLAGS) $(EXTRAH) $(OBJS_CC) $(OBJS_AS) -o $(OUTFILE)
	@echo Program ready to execute

%.o: %.c %.h
	@echo Compiling $< ...
	@$(CC) $(CFLAGS) -c $<
	@echo done

%.o: %.asm
	@echo Assembling $< ...
	@$(AS) $(ASFLAGS) $<
	@echo done

clean:
	@echo Cleaning up ...
	@rm -f *.o $(OUTFILE)
	@echo done

rebuild: clean all