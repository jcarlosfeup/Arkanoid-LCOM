#ifndef _MOUSE_H_
#define _MOUSE_H_

#include <dpmi.h>
#include "int.h"

void mouse_isr(void);

int set_prev_mouse_conf(_go32_dpmi_seginfo *prev_isr);

int mouse_init(void(*isr)(void), _go32_dpmi_seginfo *prev_isr);
