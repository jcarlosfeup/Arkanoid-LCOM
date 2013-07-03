#include "mouse.h"
#include "main.c"

void mouse_isr(void);

int set_prev_mouse_conf(_go32_dpmi_seginfo *prev_isr)
{
	restore_isr(MOUSE_IRQ, prev_isr);
    return 0;
}

int mouse_init(void(*isr)(void), _go32_dpmi_seginfo *prev_isr)
{
	disable_irq(KBD_IRQ);
	disable_irq(MOUSE_IRQ);
	int sucesso = kbc_init(1);
	_go32_dpmi_lock_code(mouse_isr, (end_mouse_isr - mouse_isr));
	_go32_dpmi_lock_data((void*) &b3, sizeof(b3));
	set_isr(MOUSE_IRQ, mouse_isr, prev_isr);
	enable_irq(KBD_IRQ);
	enable_irq(MOUSE_IRQ);
	
	return sucesso;
}