
#include "sound.h"


int play_sound(char *freq) 
{
	char *ep;
    note_t tone;  //tone, struct of the type note_t
    
    tone.freq = strtol(freq, &ep, 10); //first atribute of tone...frequency of the sound
                                      

    if( *ep != 0 ) //invalid argument
	return 1;    

    tone.dur = 3*1000;  //second atribute of tone...duration of the sound

    timer_init(TIMER_2, LSBMSB | MODE3);  //initialize timer 2

    play_note_delay(&tone);    //plays the sound


    return 0;
}