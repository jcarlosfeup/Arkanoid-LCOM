#include "speaker.h"
#include "timer.h"
#include <pc.h>
#include <dos.h>
#include <dpmi.h>

void speaker_on()
{
	char val= inportb(SPEAKER_CTRL);
	outportb(SPEAKER_CTRL, val | SPEAKER_ENABLE | TIMER2_ENABLE);
}

void speaker_off()
{
	char val= inportb(SPEAKER_CTRL);
	outportb(SPEAKER_CTRL, val & ~SPEAKER_ENABLE & ~TIMER2_ENABLE);
}

void play_note_delay(note_t *note)
{
	timer_load(TIMER_2, (1193181/note->freq));
	speaker_on();
	delay(note->dur);
	speaker_off();
}

/*
void play_note(note_t *note)
{
	timer_load(TIMER_2, note->freq);
	speaker_on();
	msleep(note->dur);
	speaker_off();
}
*/

