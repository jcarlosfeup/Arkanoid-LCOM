#include "video-graphics.h"


/** Enter graphics mode, enabling near pointers and mapping video physical memory
 * to program virtual address.
 *
 * Returns a generic pointer pointing to video memory address or NULL on error. 
 * "mode" specifies the VESA graphics mode to use, and
 * the mapping information is returned through "map".
 *
 * Also initializes two global variables, VRES and HRES,
 */
 
 
 int HRES =0, VRES=0;
 ulong VID_MEM = 0;
 
 ulong  get_adress(mode)
 {
	__dpmi_regs regs;
	ulong dosbuf, address = 0;
	dosbuf = __tb & 0xFFFFF; 
	regs.x.ax = 0x4F01; 
	regs.x.es = (dosbuf >> 4) & 0xFFFF; 
	regs.x.di = dosbuf & 0xF; 
	regs.x.cx = mode; 
	__dpmi_int (0x10, &regs); 
	if(regs.h.ah) //modo nao suportado;
		return 0; 
	dosmemget(dosbuf + 40, 4, &address); 
	return address;
}



char * enter_graphics(int mode, __dpmi_meminfo *map){
	
	__dpmi_regs regs;
	regs.x.ax = 0x4F02; 
	regs.x.bx = 0x4000 + mode; 
	__dpmi_int(0x10, &regs); 

	VID_MEM = get_adress(mode);

	if(	mode == MODE_640X480){
		HRES = 640;
		VRES = 480;
	} else if( mode == MODE_800X600){
		HRES = 800;
		VRES = 600;
	} else if( mode == MODE_1024X768){
		HRES=1024;
		VRES=768;
	} else if( mode  == MODE_1280X1024){
		HRES=1280;
		VRES = 1024;
	}

	__djgpp_nearptr_enable(); 
	map->address = VID_MEM; //usando os apontadores sabemos o endereço de memoria
	map->size = HRES * VRES; //calcula-se o tamanho
	__dpmi_physical_address_mapping(map); 
	return (char*)(map->address + __djgpp_conventional_base); 
}

void leave_graphics(__dpmi_meminfo map){
	__dpmi_free_physical_address_mapping(&map); 
	__djgpp_nearptr_disable(); 
	__dpmi_regs regs;
	regs.x.ax = 0x0003;
	__dpmi_int(0x10, &regs); //volta ao modo texto
}

void set_pixel(int x, int y, int color, char *base)
{
if(x < 0 || x >= HRES || y < 0 || y >= VRES)	
 return;
 else
	*(base + y*HRES + x) = color;
}
	
 int get_pixel(int x, int y, char *base)
{
	if(x < 0 || x >= HRES || y < 0 || y >= VRES) 
		return -1;
	else
		return (int)(*(base + y*HRES + x));
}

void clear_screen(char color, char *base)
{
	int x, y;
	for(y = 0; y < VRES; y++)
		for(x = 0; x < HRES; x++)
			set_pixel(x, y, color, base);
}
	


void draw_line(int xi, int yi, int xf, int yf, int color, char *base)
{
	
	int x_size = xf - xi; //comprimento da linha em x
	if(x_size < 0) x_size = -x_size;
	int y_size = yf - yi; //comprimento da linha em y
	if(y_size < 0) y_size = -y_size;
	
	int i;
	if(x_size > y_size)
	{
		if(xf - xi < 0) 
		{
			int aux = xi;
			xi = xf;
			xf = aux;
			aux = yi;
			yi = yf;
			yf = aux;
		}
		
		for(i = 0; i <= x_size; i++)
		{
			
			double y_point = (double)y_size * (double)i / (double)x_size;
			
			
			if(yf - yi < 0) set_pixel(xi + i, yi - (int)(y_point + 0.5), color, base); //desenha um pixel
			else set_pixel(xi + i, yi + (int)(y_point + 0.5), color, base);
		}
	}
		
	else 
	{
		if(yf - yi < 0) 
		{
			int aux = xi;
			xi = xf;
			xf = aux;
			aux = yi;
			yi = yf;
			yf = aux;
		}
		
		for(i = 0; i <= y_size; i++)
		{
			//regra de 3 simples; se y_size esta para x_size, entao i esta para x_point
			double x_point = (double)x_size * (double)i / (double)y_size;
			
			//desenhar pixel
			if(xf - xi < 0) set_pixel(xi - (int)(x_point + 0.5), yi + i, color, base);
			else set_pixel(xi + (int)(x_point + 0.5), yi + i, color, base);
		}
	}		
}


void drawCharAt(char c, int x, int y, int fore_color, int back_color,
				int char_scale, char* video_base, char* table)
{
	// posição do carácter “c” em “table” (lida de po.dat)
	char* char_def = table + c * x;

	int i, j;
	Byte mask = 0x80;
	int color;
	int x_act, y_act, sx, sy;
	// usar operadores bitwise para isolar e testar cada um dos bits
	for (j = 0, y_act = y; j < x; j++, y_act += char_scale) // for each character row
	{
		for (i = 0, x_act = x; i < 8; i++, x_act += char_scale)		// for each pixel in row
		{
			color = (*char_def & (mask >> i)) ? fore_color : back_color;
			for(sx = 0; sx < char_scale; sx++)
					for(sy = 0; sy < char_scale; sy++)
						set_pixel(x_act + sx, y_act + sy, color, video_base);
		}
		char_def++;
	}
}	


void drawStringAt(char* str, int x, int y, int fore_color, int back_color,
				int char_scale, char *video_base, char *table)
{
	int i = 0;
	while(str[i] != 0)
	{
		drawCharAt(str[i], x + 8 * char_scale * i, y, fore_color, back_color, char_scale, video_base, table);
		i++;
	}
}
		
		
void drawIntAt(int num, int x, int y, int fore_color, int back_color,
				int char_scale, char *video_base, char *table)
{
	int i = 0;
	
	//se o numero for negativo, imprimir '-'
	if(num < 0)
	{
		drawCharAt('-', x, y, fore_color, back_color, char_scale, video_base, table);
		i++;
		num = 0 - num;
	}
	
	//descobrir a ordem de grandeza do numero
	int ordem = 1;
	while(num / ordem >= 10) ordem *= 10;
	
	//da esquerda para a direita, imprimir os algarismos
	while(true)
	{
		int digito = num / ordem;
		drawCharAt(digito + '0', x + 8 * char_scale * i, y, fore_color, back_color, char_scale, video_base, table);
		num -= digito * ordem;
		if(ordem == 1) break;
		ordem /= 10;
		i++;
	}
}

/** @} end of video */ 




