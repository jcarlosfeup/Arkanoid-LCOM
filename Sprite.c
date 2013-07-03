#include "sprite.h"
#include "pixmap.h"
#include "video-graphics.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>

extern int HRES;
extern int VRES;

char *read_xpm(char *map[], int *wd, int *ht)
{
  __attribute__((unused)) static char read_xpm_jcard;

  int width, height, colors;
  char sym[256];
  int  col;
  int i, j;
  char *pix, *pixtmp, *tmp, *line;
  char symbol;

  int cenas;
  // read width, height, colors
  if ((cenas=sscanf(map[0],"%d %d %d", &width, &height, &colors)) != 3) {
    printf("read_xpm: incorrect width, height, colors\n");
	printf("wid: %d,heig: %d,color: %d,cenas: %d",width,height,colors,cenas);
    return NULL;
  }
#ifdef DEBUG
  printf("%d %d %d\n", width, height, colors);
#endif
  if (width > HRES || height > VRES || colors > 256) {
    printf("read_xpm: incorrect width, height, colors\n");
	printf("VRES: %d, HRES: %d, wid: %d,heig: %d,color: %d,cenas: %d",VRES,HRES,width,height,colors,cenas);
    return NULL;
  }

  *wd = width;
  *ht = height;

  for (i=0; i<256; i++)
    sym[i] = 0;

  // read symbols <-> colors 
  for (i=0; i<colors; i++) {
    if (sscanf(map[i+1], "%c %d", &symbol, &col) != 2) {
      printf("read_xpm: incorrect symbol, color at line %d\n", i+1);
      return NULL;
    }
#ifdef DEBUG
    printf("%c %d\n", symbol, col);
#endif
    if (col > 256) {
      printf("read_xpm: incorrect color at line %d\n", i+1);
      return NULL;
    }
    sym[col] = symbol;
  }
  
  // allocate pixmap memory
  pix = pixtmp = malloc(width*height);

  // parse each pixmap symbol line
  for (i=0; i<height; i++) {
    line = map[colors+1+i];
#ifdef DEBUG
    printf("\nparsing %s\n", line);
#endif
    for (j=0; j<width; j++) {
      tmp = memchr(sym, line[j], 256);  // find color of each symbol
      if (tmp == NULL) {
	printf("read_xpm: incorrect symbol at line %d, col %d\n", colors+i+1, j);
	return NULL;
      }
      *pixtmp++ = tmp - sym; // pointer arithmetic! back to books :-)
#ifdef DEBUG
      printf("%c:%d ", line[j], tmp-sym);
#endif
    }
  }

  return pix;
}



Sprite *create_static_sprite(char *pic[], char *base, int pos_x, int pos_y)
{
	Sprite *new_brick = (Sprite *) malloc (sizeof(Sprite));
	int comp, alt;
	if(new_brick == NULL) return NULL;
	new_brick->map = read_xpm(pic, &comp, &alt);
	
	if(new_brick->map == NULL){
		free(new_brick);
		return NULL;}
		
	new_brick->width = comp;
	new_brick->height = alt;
	
	new_brick->xspeed = 0;
	new_brick->yspeed = 0;
	new_brick->x = pos_x;
	new_brick->y = pos_y;
	
	int i,j;
	for(i = 0;i < alt ;i++)	{
		for(j = 0; j < comp;j++)
			set_pixel(new_brick->x + j,new_brick->y+i, *(new_brick->map+j+i*new_brick->width),base);   
			//esta função vai fazer que o ecra seja preenchido com pixels 
			//(os argumentos vamos retirá-los do objecto do tipo sprite que criamos em cima
	}
	free(new_brick);
	return new_brick;
	
}

Sprite * create_sprite_ball(char *pic[], char *base){
	
	Sprite *new_brick = (Sprite *) malloc (sizeof(Sprite));
	int comp, alt;
	if(new_brick == NULL) return NULL;
	new_brick->map = read_xpm(pic, &comp, &alt);
	
	if(new_brick->map == NULL){
		free(new_brick);
		return NULL;}
		
	new_brick->width = comp;
	new_brick->height = alt;
	
	new_brick->xspeed = 0;
	new_brick->yspeed = 0;
	new_brick->x = 294;
	new_brick->y = 437;
	
	int i,j;
	for(i = 0;i < alt ;i++)	{
		for(j = 0; j < comp;j++)
			set_pixel(new_brick->x + j,new_brick->y+i, *(new_brick->map+j+i*new_brick->width),base);   
			//esta função vai fazer que o ecra seja preenchido com pixels 
			//(os argumentos vamos retirá-los do objecto do tipo sprite que criamos em cima
	}
	free(new_brick);
	return new_brick;
}


Sprite *create_sprite_racket(char *pic[], char *base)
{
	Sprite *new_brick = (Sprite *) malloc (sizeof(Sprite));
	int comp, alt;
	if(new_brick == NULL) return NULL;
	char *sp = read_xpm(pic, &comp, &alt);
	
	if(sp == NULL){
		return NULL;}
		
	if((new_brick->map = sp) == NULL){
		free(new_brick);
		return NULL;
	}
	
	new_brick->width = comp;
	new_brick->height = alt;
	new_brick->xspeed = 0;
	new_brick->yspeed = 0;
	new_brick->x = 0;
	new_brick->y = 0;
	new_brick->map = sp;

	return new_brick;
	
}

void draw_sprite(Sprite *fig, char *base){
	char *sp = fig->map;
	int i,j;
	for(i = 0;i < fig->height ;i++)	{
		for(j = 0; j < fig->width;j++){
			if(sp != 0)
			set_pixel(fig->x + j,fig->y+i, *sp ,base);  
			//set_pixel(fig->x + j,fig->y+i, *(sp+j+i*fig->width),base); 			
			//esta função vai fazer que o ecra seja preenchido com pixels 
			//(os argumentos vamos retirá-los do objecto do tipo sprite que criamos em cima
			sp++;
		}
	}

}

void delete_sprite(Sprite *fig, char *base){
	char *delSp = fig->map;
	int i, j;
	for(i = 0; i < fig->height; i++){
		for(j = 0; j < fig->width; j++){
			if(*delSp == get_pixel(fig->x + j, fig->y + i, base))
				set_pixel(fig->x + j, fig->y+i, 0 ,base);
			delSp++;
		}
	}
}

void destroy_sprite(Sprite *fig, char *base){
	if( fig == NULL )
		return;
	
	delete_sprite(fig, base);
	
	free(fig->map);
	free(fig);
	fig = NULL; // hopeless: pointer is passed by value
}

int sprite_colison(Sprite *sp1, Sprite *sp2){

	if((sp1->x >= sp2->x) && (sp1->x <= (sp2->x + sp2->width)) &&
	((sp1->y + sp1->height) >= sp2->y) && ((sp1->y + sp1->height) <= (sp2->y + sp2->height)))
		return 1;
	else if(((sp1->x+sp1->width) >= sp2->x) && ((sp1->x + sp1->width) <= (sp2->x + sp2->width)) &&
	((sp1->y + sp1->height) >= sp2->y) && ((sp1->y + sp1->height) <= (sp2->y + sp2->height)))
		return 1;
	else if((sp1->x >= sp2->x) && (sp1->x <= (sp2->x + sp2->width)) &&
	(sp1->y >= sp2->y) && (sp1->y <= (sp2->y + sp2->height)))
		return 1;
	else if(((sp1->x+sp1->width) >= sp2->x) && ((sp1->x + sp1->width) <= (sp2->x + sp2->width)) &&
	(sp1->y >= sp2->y) && (sp1->y <= (sp2->y + sp2->height)))
		return 1;
	else 
		return 0;
}

void move_ball(Sprite *fig1, Sprite *fig2, char *base){
	
	delete_sprite(fig1, base);
	int lose = 0;
	int newx = fig1->xspeed;
	int newy = fig1->yspeed;
	int x =1;
	int y =1;
	
		
	while(x <= abs(newx)){
		int xtest = fig1->x + x;
		if(xtest <= 7 || xtest >= 637){
			fig1->xspeed = -fig1->xspeed;
			break;}
			
		if(xtest == 608){
			fig1->xspeed = -fig1->xspeed;
			break;
		}
		
		if(sprite_colison(fig1, fig2) == 1){
		fig1->yspeed = -fig1->xspeed;
		break;}
		x++;
	}
	
	while(y <= abs(newy)){
		int ytest = fig1->y + y;
		if(ytest == 480 || ytest == 0){
			fig1->yspeed = -fig1->yspeed;
			break;
		}
		
		if(ytest == VRES-7){
			fig1->yspeed = -fig1->yspeed;
			fig1->x = 320;
			fig1->y = 420;
			lose = 1;
			break;
		}
		
		if(sprite_colison(fig1, fig2) == 1){
		fig1->xspeed = -fig1->yspeed;
		break;}
		y++;
	}
	
	delete_sprite(fig1, base);
	fig1->x += fig1->xspeed;
	fig1->y += fig1->yspeed;
	draw_sprite(fig1, base);
	if(lose == 1) delay(2500);
		
}