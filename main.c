#include "sprite.h"
#include "pixmap.h"
#include "Menu.h"
#include "sound.h"
#include "kbc.h"
#include "video-graphics.h"
#include <stdlib.h>
#include <time.h>
#include <dos.h>
#include <stdio.h>

int main(){
	__dpmi_meminfo v_ram;
	char *bas = enter_graphics(MODE_640X480,&v_ram);
	
	create_static_sprite(gif_arkanoid,bas,280,240);
	
	delay(3*1000);
	create_static_sprite(novo_jogo, bas, 280, 240);  //menu
	create_static_sprite(sair_jogo, bas, 280, 270);
	
	play_sound(10);  //plays a sound
	
	delay(10*1000);
	
	leave_graphics(v_ram); 
	
	enter_graphics(MODE_640X480,&v_ram);
	create_static_sprite(framev, bas, 0, 7);
	create_static_sprite(framev, bas, 633, 7);
	create_static_sprite(frameh, bas, 0, 0);
	create_static_sprite(frameh, bas, 0, 473);
	create_static_sprite(pic_brick1, bas, 580, 10);
	create_static_sprite(pic_brick2, bas, 540, 10);
	create_static_sprite(pic_brick3, bas, 500, 10);
	create_static_sprite(pic_brick4, bas, 460, 10);
	create_static_sprite(pic_brick1, bas, 420, 10);
	create_static_sprite(pic_brick2, bas, 380, 10);
	create_static_sprite(pic_brick3, bas, 340, 10);
	create_static_sprite(pic_brick4, bas, 300, 10);
	create_static_sprite(pic_brick1, bas, 260, 10);
	create_static_sprite(pic_brick2, bas, 220, 10);
	create_static_sprite(pic_brick3, bas, 180, 10);
	create_static_sprite(pic_brick4, bas, 140, 10);
	create_static_sprite(pic_brick1, bas, 100, 10);
	create_static_sprite(pic_brick2, bas, 60, 10);
	create_static_sprite(pic_brick3, bas, 20, 10);
	create_static_sprite(pic_brick4, bas, 580, 40);
	create_static_sprite(pic_brick1, bas, 540, 40);
	create_static_sprite(pic_brick2, bas, 500, 40);
	create_static_sprite(pic_brick3, bas, 460, 40);
	create_static_sprite(pic_brick4, bas, 420, 40);
	create_static_sprite(pic_brick1, bas, 380, 40);
	create_static_sprite(pic_brick2, bas, 340, 40);
	create_static_sprite(pic_brick3, bas, 300, 40);
	create_static_sprite(pic_brick4, bas, 260, 40);
	create_static_sprite(pic_brick1, bas, 220, 40);
	create_static_sprite(pic_brick2, bas, 180, 40);
	create_static_sprite(pic_brick3, bas, 140, 40);
	create_static_sprite(pic_brick4, bas, 100, 40);
	create_static_sprite(pic_brick1, bas, 60, 40);
	create_static_sprite(pic_brick2, bas, 20, 40);
	create_static_sprite(pic_brick3, bas, 580, 70);
	create_static_sprite(pic_brick4, bas, 540, 70);
	create_static_sprite(pic_brick1, bas, 500, 70);
	create_static_sprite(pic_brick2, bas, 460, 70);
	create_static_sprite(pic_brick3, bas, 420, 70);
	create_static_sprite(pic_brick4, bas, 380, 70);
	create_static_sprite(pic_brick1, bas, 340, 70);
	create_static_sprite(pic_brick2, bas, 300, 70);
	create_static_sprite(pic_brick3, bas, 260, 70);
	create_static_sprite(pic_brick4, bas, 220, 70);
	create_static_sprite(pic_brick1, bas, 180, 70);
	create_static_sprite(pic_brick2, bas, 140, 70);
	create_static_sprite(pic_brick3, bas, 100, 70);
	create_static_sprite(pic_brick4, bas, 60, 70);
	create_static_sprite(pic_brick1, bas, 20, 70);
	create_static_sprite(pic_brick2, bas, 580, 100);
	create_static_sprite(pic_brick3, bas, 540, 100);
	create_static_sprite(pic_brick4, bas, 500, 100);
	create_static_sprite(pic_brick1, bas, 460, 100);
	create_static_sprite(pic_brick2, bas, 420, 100);
	create_static_sprite(pic_brick3, bas, 380, 100);
	create_static_sprite(pic_brick4, bas, 340, 100);
	create_static_sprite(pic_brick1, bas, 300, 100);
	create_static_sprite(pic_brick2, bas, 260, 100);
	create_static_sprite(pic_brick3, bas, 220, 100);
	create_static_sprite(pic_brick4, bas, 180, 100);
	create_static_sprite(pic_brick1, bas, 140, 100);
	create_static_sprite(pic_brick2, bas, 100, 100);
	create_static_sprite(pic_brick3, bas, 60, 100);
	create_static_sprite(pic_brick4, bas, 20, 100);
	Sprite* bola = create_sprite_racket(pic_ball, bas);
	Sprite* raquete = create_sprite_racket(pic_racket, bas);
	
	play_sound(9);
	
	if(raquete == NULL)
	return 1;
	
	raquete->x = 271;
	raquete->y = 450;
	raquete->xspeed = 10;
	
	if(bola == NULL) return 1;
	
	bola->x = 320;
	bola->y = 440;
	bola->xspeed = 5;
	bola->yspeed = 5;
	
	set_kbd_isr(&prev_isr);	
	while(1){
		delete_sprite(bola, bas);
		delete_sprite(raquete, bas);
		unsigned char c = keyPress();
			if(c==0x01)
				break;	
			if(c==0x4d){
			if(raquete->x + raquete->xspeed < 578)
				raquete->x = raquete->x +raquete->xspeed;	
			}else if(c == 0x4b){
				if(raquete->x + raquete->xspeed > 21)
					raquete->x = raquete->x - raquete->xspeed;
			}
		
		draw_sprite(raquete,bas);
		draw_sprite(bola, bas);
		move_ball(bola, raquete, bas);
		delay(50);
	
	}
	restore_isr(KBD_IRQ,& prev_isr);
	leave_graphics(v_ram);   //sai do modo grafico   

	
	return 0;
}
