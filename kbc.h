#ifndef _KBC_H_
#define _KBC_H_

#include <dpmi.h>
#include "int.h"

_go32_dpmi_seginfo prev_isr;
/** @defgroup KeyboardController KeyboardController
 * @{
 *
 * Keyboard and Mouse related functions
 */

/** @name The hardware register addresses */
/*@{*/ 
#define CTRL_REG  0x64  ///< control register (write only)
#define STAT_REG  0x64  ///< status register  (read only)
#define DATA_REG  0x60  ///< data register    (read/write)
/*@}*/ 

/** @name Bit meanings in the status register */
/*@{*/ 
#define OBF     (1 << 0) ///< Output Buffer Full
#define IBF     (1 << 1) ///< Input Buffer Full
#define AUX     (1 << 5) ///< 1 if data at DATA_REG came from mouse interface
#define PAR_ERR (1 << 7) ///< Parity Error
#define TO_ERR  (1 << 6) ///< Timeout Error
/*@}*/ 

/** @name "Historical" commands to send to DATA_REG, response in DATA_REG */
/*@{*/ 
#define ResetKBC   0xFF ///< Reset the KBC interface
#define DefaultKBD 0xF6 ///< Set default scancode and repeat rate
#define DisableKBD 0xF5 ///< Historical Disable keyboard
#define EnableKBD  0xF4 ///< Historical clear buffer and enable keyboard
#define KBDRate    0xF3 ///< Keyboard repeat rate, one arg, bits 0-4 repeat rate, bits 5-6 start delay
#define WriteLEDS  0xED ///< Turn on/off KBD LEDS, one arg, one bit per led, bits 0-2, 0-off, 1-on
#define SCROLL_LOCK (1 << 0) ///< SCROLL_LOCK led for WriteLEDS command
#define NUM_LOCK    (1 << 1) ///< NUM__LOCK led for WriteLEDS command
#define CAPS_LOCK   (1 << 2) ///< CAPS_LOCK led for WriteLEDS command
/*@}*/ 

/** @name Response codes to commands/data written in DATA_REG */
/*@{*/ 
#define ACK        0xFA ///< Acknowledge OK response
#define Resend     0xFE ///< Resend error response; on multibyte commands the whole command must be resent from the beginning
#define Error      0xFC ///< Error
/*@}*/ 

/** @name Command codes to send to CMD_REG, args, if exists, to DATA_REG, return values in DATA_REG */
/*@{*/ 
#define ReadCommand   0x20 ///< Read Command_Byte
#define WriteCommand  0x60 ///< Write Command_Byte, one arg
#define DisableMouse  0xA7 ///< Disable Mouse Interface 
#define EnableMouse   0xA8 ///< Enable Mouse Interface 
#define TestMouse     0xA9 ///< Test Mouse Interface, returns 0 if OK
#define Test8042      0xAA ///< Test KBC, returns 0x55 if sucess, 0xFC on error
#define TestKBD       0xAB ///< Test mouse, returns 0 if OK
#define NDisableKBD   0xAD ///< New (versus historical) Disable keyboard
#define NEnableKBD    0xAE ///< New (versus historical) Enable keyboard
#define WriteMouse    0xD4 ///< Write Mouse, one arg, see "Commands for the Mouse"
#define ResetPC       0xFE ///< Reset PC (reboot)
/*@}*/ 

/** @name Bit meanings in the Command_Byte
 * (read/write with command ReadCommand/WriteCommand)
*/
/*@{*/ 
#define INT_1    (1 << 0)  ///< Enable generation of interrupts from keyboard
#define INT_12   (1 << 1)  ///< Enable generation of interrupts from mouse
#define EN_KBD   (1 << 4)  ///< Enable keyboard interface
#define EN_MOUSE (1 << 5)  ///< Enable mouse interface
/*@}*/

/** @name Timout for KBC response */
/*@{*/ 
#define KBC_TIMEOUT 50 ///< maximum amount of milliseconds to wait for KBC response/availability
/*@}*/ 

 void kbd_isr(void);
 
 volatile unsigned char scancode;
 
/**
 * Sets ISR for the keyboard.
 * Initializes _go32_dpmi_seginfo structure passed as an address with
 *  the information on the ISR that was installed, so that it can be
 *  restored later
 * 
 * @name set_kbd_isr
 * @param prev_isr address of _go32_dpmi_seginfo structure which is initialized
with the information on the ISR that was installed
 */
void set_kbd_isr(_go32_dpmi_seginfo *prev_isr);

unsigned char keyPress();
/** 
 * Sets previous mouse configuration, i.e. the one before the call to init_mouse()
 * @param _go32_dpmi_meminfo *prev_isr -- pointer to struct with the info on the ISR installed before the current one. NULL if there was none
 * @return 0, on success if there was no previous ISR
 * @return -1, on failure
 */ 
/** @} end of KeyboardController */

#endif
