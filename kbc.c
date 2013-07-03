#include "kbc.h"
#include <pc.h>
#include <dos.h>
#include "utypes.h"


void kbd_isr(void);
void mouse_isr(void);

uchar c;

void set_kbd_isr(_go32_dpmi_seginfo *prev_isr) {
	set_isr(KBD_IRQ, kbd_isr, prev_isr);
}

uchar keyPress()
{
	c=0;
	
	c=scancode;
	return c;
}