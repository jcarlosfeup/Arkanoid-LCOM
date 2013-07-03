#include "int.h"
#include <go32.h>
#include <dpmi.h>

int irq_vector(int irq)
{
	if (irq< 8)
		irq= irq + 0x08;
	else
		irq=irq+0x70-8;
	return irq;
}

int set_isr(int irq, void (*isr)(void), 
			    _go32_dpmi_seginfo *prev_isr)
{ 
	int vector = irq_vector(irq);
	if(_go32_dpmi_get_protected_mode_interrupt_vector(vector, prev_isr)) return -1;
		_go32_dpmi_seginfo new_isr;
		new_isr.pm_selector = _go32_my_cs( );
		new_isr.pm_offset=(unsigned long) isr;
	if(_go32_dpmi_set_protected_mode_interrupt_vector(vector, &new_isr)) return -1;
	return 0;
}	

void restore_isr(int irq, _go32_dpmi_seginfo *isr)
{
	int vector = irq_vector(irq);
	_go32_dpmi_set_protected_mode_interrupt_vector(vector, isr);
}

void disable_irq(int irq)
{
	unsigned short pic;
	if(irq<8)
		pic=PIC1_MASK;
	else
		pic=PIC2_MASK;
	unsigned char mask = inportb(pic) | (IRQ_MASK(irq));
	outportb(pic,mask);
}

void enable_irq(int irq)
{
	unsigned short pic;
	if(irq<8)
		pic=PIC1_MASK;
	else
		pic=PIC2_MASK;
	unsigned char mask = inportb(pic) &(~IRQ_MASK(irq));
	outportb(pic, mask);
}

