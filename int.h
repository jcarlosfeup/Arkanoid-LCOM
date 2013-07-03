#ifndef _INT_H_
#define _INT_H_

#include <pc.h>
#include <dos.h>
#include <dpmi.h>
#include <go32.h>

#define IRQ_MASK(irq) ((irq)< 8 ? 1 << (irq) : (1 << (irq)) >> 8)
#define IRQ_VECTOR ((irq)< 8 ? (irq)+ 0x08 : ((irq)+0x70-8))

/** @defgroup interrupts Interrupts
 * @{
 *
 * functions, macros and constants related to interrupts 
 */

/** @name Port numbers for PIC registers */
/*@{*/ 
#define EOI       0x20  ///< EOI command */
#define PIC1_CMD  0x20  ///< PIC1 register address for EOI */
#define PIC2_CMD  0xA0  ///< PIC2 register address for EOI*/
#define PIC1_MASK 0x21  ///< PIC1 interrupt mask register */
#define PIC2_MASK 0xA1  ///< PIC2 interrupt mask register */
/*@}*/ 

/** @name PC IRQ lines */
/*@{*/
#define T0_IRQ    0  ///< Timer 0       
#define KBD_IRQ   1  ///< Keyboard       
#define COM2_IRQ  3  ///< Serial port 2 (COM2) 
#define COM1_IRQ  4  ///< Serial port 1 (COM1)
#define RTC_IRQ   8  ///< Realtime Clock 
#define MOUSE_IRQ 12 ///<Rato

/*@}*/ 

/** Sets the 'isr' written in assembly as the ISR for IRQ line 'irq'. 
 * Updates struct 'prev_isr' with the info on the current ISR, so that it
 * can be restored later.
 *     @name   set_isr
 *     @param  int irq interrupt line
 *     @param void (*isr)(void) ISR written in assembly to set
 *     @param _go32_dpmi_seginfo *prev_isr struct to update with info on the current isr
 *     @return 0 if successful or -1 in case of error. In the latter case the current handler remains in place 
 */      
 
int irq_vector(int irq);
 
int set_isr(int irq, void (*isr)(void), _go32_dpmi_seginfo *prev_isr);

/** Restore assembly ISR specified in 'isr' for IRQ line 'irq'
 *     @name  restore_isr
 *     @param int irq IRQ line, _go32_dpmi_seginfo *isr struct with the info on
the ISR to restore
 */

void restore_isr(int irq, _go32_dpmi_seginfo *isr);

/** Disables the IRQ line specified in 'isr' by setting the corresponding bit
 *   of the mask of the appropriate PIC.
 *      @name  disable_irq  
 *      @param int irq IRQ line
 */
void disable_irq(int irq);

/** Enables the IRQ line specified in 'isr' by resetting the corresponding bit
 *   of the mask of the appropriate PIC.
 *      @name  enable_irq  
 *      @param int irq IRQ line
 */
void enable_irq(int irq);

/** @} enf of interrupts */

#endif
