#include "timer.h"
#include "int.h"
#include <pc.h>
#include <dos.h>
#include <dpmi.h>
#include <go32.h>

_go32_dpmi_seginfo prev_isr;

void setup_timer0() 
{
	disable_irq(0);
	timer_init(TIMER_0, MODE2|LSBMSB);
	timer_load(0, TIMER_CLK/1000);
	set_isr(0,t0_isr, & prev_isr);
	enable_irq(0);
}

void restore_timer0() 
{
	restore_isr(0,& prev_isr);
}

void timer_init(int timer, int mode)
{
	outportb(TIMER_CTRL, mode | (timer << 6));
	
	if(timer == 2)
	{
		char val = inportb(SPEAKER_CTRL);
		outportb(SPEAKER_CTRL, val | TIMER2_ENABLE);
	}
}

void timer_load(int timer, int value)
{
	outportb(0x40 | timer, LSB(value));
	outportb(0x40 | timer, MSB(value));
}

void msleep(int ms)
{
	int valor=millis;
	while(millis-valor<ms){}
}





