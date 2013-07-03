#ifndef _TIMER_H_
#define _TIMER_H_

/** @defgroup Counter/Timer Counter/Timer
 * @{
 *
 * Definitions/declarations for Counter/Timer
 */

/** @name Timer port numbers */
/*@{*/
#define TIMER_0      0x40 ///< Timer0 address
#define TIMER_1      0x41 ///< Timer1 address
#define TIMER_2      0x42 ///< Timer2 address
#define TIMER_CTRL   0x43 ///< Timer control register address 
/*@}*/

/** @name Speaker and Timer2 control */
/*@{*/
#define SPEAKER_CTRL    0x61    ///< Port number of PC register whose bits 0 and 1 control TIMER_2  and the output to the speaker
#define TIMER2_ENABLE  (1 << 0) ///< Enable Timer2, bit 0 to 1
#define SPEAKER_ENABLE (1 << 1) ///< Enable output to speaker, bit 1 to 1
/*@}*/

/** @name Some useful definitions for timer programming */
/*@{*/
#define TIMER_CLK    1193181 	///< Frequência de entrada dos timers

#define LSBMSB       0x30       ///< LSB followed by MSB
#define MODE2	     0x04       ///< Counting mode 2: freq. div (impulse)
#define MODE3        0x06       ///< Counting mode 3: freq. div (square wave)
#define BCD          0x01       ///< BCD counter
#define LSB(i) ((i) & 0xFF)
#define MSB(i) ((i) >> 8)

#define HLT __asm__ __volatile__ ("HLT")
/*@}*/

/** Program timer 0, 1, 2 with specified mode
 */
void timer_init(int timer, int mode);

/** Load timer 0, 1, 2 with initial couting value
 */
void timer_load(int timer, int value);

/** Variable updated by timer 0 ISR to measure time  */

extern int millis;

/** Timer 0 ISR */

void t0_isr(void);  

/** Setup timer 0 to count time in ms
 *     @name setup_timer0
 */
void setup_timer0();

/** Restore timer 0 initial configuration
 *     @name restore_timer0
 */
void restore_timer0();

/** Wait for milli ms
 *     @name msleep
 *     @params int ms
*/
void msleep(int ms);

/** @} end of  */

#endif
