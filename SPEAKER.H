#ifndef _SPEAKER_H_
#define _SPEAKER_H_

/** @defgroup Speaker Speaker
 * @{
 *
 * Functions related to the speaker
 */

/** Note definition
 */
typedef struct {
	int freq; 	/**< note frequency */
	int dur;	/**< note duration in miliseconds */
} note_t;

/** Switch on the speaker
 *     @name speaker_on
 */
void speaker_on();

/** Switch off the speaker
 *     @name speaker_off
 */
void speaker_off();

/** Play a note using delay()
 *     @name play_note_dealy
 */
void play_note_delay(note_t *note);

/** Play a note using msleep()
 *     @name play_note
 */
//void play_note(note_t *note);

/** @} End of Speaker */

#endif
