#include<conio.h>

/** Format of a xpm-like (there is a real xpm format) pic:
 * <pre>
 * static char *picture_name[] = {
 * "number_of_x_pixels number_of_y_pixels number_of_colors",
 * "one_char_symbol the_char_symbol_color",
 * ... exactly number_of_colors lines as above
 * "any of the above one_char_symbol, exactly number_of_x_pixels times",
 * ... exactly number_of_y_pixels lines as above
 * };
 * 0   BLACK
 * 1   BLUE
 * 2   GREEN
 * 3   CYAN
 * 4   RED
 * 5   MAGENTA
 * 6   BROWN
 * 7   LIGHTGRAY
 * 8   DARKGRAY
 * 9   LIGHTBLUE
 * 10  LIGHTGREEN
 * 11  LIGHTCYAN
 * 12  LIGHTRED
 * 13  LIGHTMAGENTA
 * 14  YELLOW
 * 15  WHITE
 * Example:
 *
 * static char *pic1[] = {  // the name os the picture, "pic1" in this case
 * "32 13 4",               // number of pixels in the x and y dimension,
 *                          //   and the number of colors, which follows.
 * ". 0",                   // mapping between symbols and colors; in this
 *                          //   case, the "." will be mapped to color 0
 * "x 2",                   // and the "x" to color 2
 * ...                      // the next symbol/color pairs
 * "................................", // first row, exactly 32 pixels, 
 *                                     // all color 0, BLACK
 * "..............xxx...............", // next row has three GREEN pixels
 *                                     // at the center
 * </pre>
 * Colors names/colors number equivalence are at c:/djgpp/include/conio.h
 *
 * Any real xpm picture can be read, as long as there are only 16
 * colors on it, and the colors are the ones available in conio.h.
 *
 *  To use other/more colors than the basic ones, the graphic card
 *  pallete must be programmed.
 */


 static char *pic_brick1[]={
 "33 18 4",
 ". 1",
 "x 15",
 "+ 9",
 "p 0",
 "pxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxp",
 "xxx+++++++++++++++++++++++++++xxx",
 "xx+++++++++++++++++++++++++++++xx",
 "xx+++.......................+++xx",
 "xx++.........................++xx",
 "xx++....................++...++xx",
 "xx++...................++++..++xx",
 "xx++.....................++..++xx",
 "xx++.....................+...++xx",
 "xx++.........................++xx",
 "xx++.........................++xx",
 "xx++.........................++xx",
 "xx++.........................++xx",
 "xx++.........................++xx",
 "xx+++.......................+++xx",
 "xx+++++++++++++++++++++++++++++xx",
 "xxx+++++++++++++++++++++++++++xxx",
 "pxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxp" };
 
 
 static char *pic_brick2[]={
 "33 18 4",
 ". 2",
 "x 15",
 "+ 10",
 "p 0",
 "pxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxp",
 "xxx+++++++++++++++++++++++++++xxx",
 "xx+++++++++++++++++++++++++++++xx",
 "xx+++.......................+++xx",
 "xx++.........................++xx",
 "xx++....................++...++xx",
 "xx++...................++++..++xx",
 "xx++.....................++..++xx",
 "xx++.....................+...++xx",
 "xx++.........................++xx",
 "xx++.........................++xx",
 "xx++.........................++xx",
 "xx++.........................++xx",
 "xx++.........................++xx",
 "xx+++.......................+++xx",
 "xx+++++++++++++++++++++++++++++xx",
 "xxx+++++++++++++++++++++++++++xxx",
 "pxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxp" };
 
 
 static char *pic_brick3[]={
 "33 18 4",
 ". 6",
 "x 15",
 "+ 14",
 "p 0",
 "pxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxp",
 "xxx+++++++++++++++++++++++++++xxx",
 "xx+++++++++++++++++++++++++++++xx",
 "xx+++.......................+++xx",
 "xx++.........................++xx",
 "xx++....................++...++xx",
 "xx++...................++++..++xx",
 "xx++.....................++..++xx",
 "xx++.....................+...++xx",
 "xx++.........................++xx",
 "xx++.........................++xx",
 "xx++.........................++xx",
 "xx++.........................++xx",
 "xx++.........................++xx",
 "xx+++.......................+++xx",
 "xx+++++++++++++++++++++++++++++xx",
 "xxx+++++++++++++++++++++++++++xxx",
 "pxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxp" };
 
 static char *pic_brick4[]={
 "33 18 4",
 ". 4",
 "x 15",
 "+ 12",
 "p 0",
 "pxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxp",
 "xxx+++++++++++++++++++++++++++xxx",
 "xx+++++++++++++++++++++++++++++xx",
 "xx+++.......................+++xx",
 "xx++.........................++xx",
 "xx++....................++...++xx",
 "xx++...................++++..++xx",
 "xx++.....................++..++xx",
 "xx++.....................+...++xx",
 "xx++.........................++xx",
 "xx++.........................++xx",
 "xx++.........................++xx",
 "xx++.........................++xx",
 "xx++.........................++xx",
 "xx+++.......................+++xx",
 "xx+++++++++++++++++++++++++++++xx",
 "xxx+++++++++++++++++++++++++++xxx",
 "pxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxp" };
 
 
static char *pic_racket[]={
"62 8 4",
". 8",
"x 15",
"p 0",
"i 7",
"pppxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxppp",
"pxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxp",
"xxxxxxiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiixxxxxx",
"xxxxxiii..............................................iiixxxxx",
"xxxxxiii..............................................iiixxxxx",
"xxxxxxiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiixxxxxx",
"pxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxp",
"pppxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxppp"};

static char *pic_ball[]={
"19 12 4",
". 0",
"x 1",
"+ 15",
"o 9",
".....+++++++++.....",
"...++xxxxxxxxx++...",
"..+xxxxxxxxxxxxx+..",
".+xxxxxxxxxxxxxxx+.",
"+xxxxxxxxxxoooxxxx+",
"+xxxxxxxxxxooooxxx+",
"+xxxxxxxxxxxoooxxx+",
"+xxxxxxxxxxxxxxxxx+",
".+xxxxxxxxxxxxxxx+.",
"..+xxxxxxxxxxxxx+..",
"...++xxxxxxxxx++...",
".....+++++++++....."

};

static char *gif_arkanoid[]={
"102 14 3",
"/ 4",
"+ 15",
". 0",
"//////////////////////////////////////////////////////////////////////////////////////////////////////",
"//////////////////////////////////////////////////////////////////////////////////////////////////////",
"//..................................................................................................//",
"//.......+..........++++++....++......++........+........+++........++....++++++.....++...++++++....//",
"//......+++........+++...++...++.....++........+++.......++++.......++...+++..+++....++...++..+++...//",
"//.....++.++.......++.....++..++...++.........++.++......+++++......++..+++....+++........++....++..//",
"//....++...++......+++...++...++..++.........++...++.....++..+++....++..++......++...++...++.....++.//",
"//...+++++++++.....+++++++....+++++.........+++++++++....++....+++..++..++......++...++...++.....++.//",
"//..++.......++....++...++....++...++......++.......++...++.....++++++..+++....+++...++...++....++..//",
"//.++.........++...++....++...++.....++...++.........++..++.......++++...+++..+++....++...++..+++...//",
"//++...........++..++.....++..++......++.++...........++.++........+++....++++++.....++...++++++....//",
"//..................................................................................................//",
"//////////////////////////////////////////////////////////////////////////////////////////////////////",
"//////////////////////////////////////////////////////////////////////////////////////////////////////"};
 
 static char *frameh[]={
 "640 7 3",
 ". 0",
 "+ 8",
 "c 7",
 "..++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++..",
 ".cccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc.",
 "cccc....cccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc++cccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc++cccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc++cccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc++ccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc++ccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc....cccc",
 "ccc......ccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc++cccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc++cccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc++cccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc++ccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc++cccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc......ccc",
 "cccc....cccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc++cccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc++cccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc++cccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc++ccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc++ccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc....cccc",
 ".cccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc.",
 "..++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++.."};
 
 static char *framev[]={
 "7 476 3",
 ". 0",
 "+ 8",
 "c 7",
 ".......", "+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+",
 "+ccccc+", "+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+",
 "+ccccc+", "+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+",
 "+ccccc+", "+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+",
 "+ccccc+", "+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+",
 "+ccccc+", "+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+",
 "+ccccc+", "+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","+ccccc+","......."
 };
 

 
 static char *game_over[]={
"120 14 3",
"/ 4",
"+ 15",
". 0",
"////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////",
"////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////",
"//....................................................................................................................//",
"//..++++++++++.........+........++..........++..++++++++++..........++++++...++.............++..++++++++++...++++++...//",
"//.+++++++++++........+++.......++++......++++..++.................+++..+++..+++...........+++..++..........+++...++..//",
"//.++................++.++......++.+++..+++.++..+++++++...........+++....+++..++...........++...+++++++.....++.....++.//",
"//.++..++++++.......++...++.....++...++++...++..+++++++...........++......++...++.........++....+++++++.....+++...++..//",
"//.++..+++++++.....+++++++++....++....++....++..++................++......++....++.......++.....++..........+++++++...//",
"//.++.......++....++.......++...++..........++..++................+++....+++.....++.....++......++..........++...++...//",
"//.+++++++++++...++.........++..++..........++..++++++++++.........+++..+++.......+++.+++.......++++++++++..++....++..//",
"//..+++++++++...++...........++.++..........++..++++++++++..........++++++.........++++++.......++++++++++..++.....++.//",
"//....................................................................................................................//",
"////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////",
"////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////"
};


/*Pixmaps do menu*/

static char *novo_jogo[]={
"120 14 3",
"/ 4",
"+ 15",
". 0",
"////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////",
"////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////",
"//....................................................................................................................//",
"//.++.......++......++++++..++...............++....++++++.......+++++++++++....++++++....++++++++++....++++++.........//",
"//.+++......++.....+++..+++..++.............++....+++..+++...............++...+++..+++..+++++++++++...+++..+++........//",
"//.++++.....++....+++....+++..++...........++....+++....+++..............++..+++....+++.++...........+++....+++.......//",
"//.++.++....++....++......++...++.........++.....++......++..............++..++......++.++..++++++...++......++.......//",
"//.++..++...++....++......++....++.......++......++......++....++++......++..++......++.++..+++++++..++......++.......//",
"//.++...++..++....+++....+++.....++.....++.......+++....+++.....++.......++..+++....+++.++.......++..+++....+++.......//",
"//.++....++.++.....+++..+++.......+++.+++.........+++..+++......++.......++...+++..+++..+++++++++++...+++..+++........//",
"//.++......+++......++++++.........++++++......... ++++++.......+++++++++++....++++++....+++++++++.....++++++.........//",
"//....................................................................................................................//",
"////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////",
"////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////"
};

static char *sair_jogo[]={
"120 14 3",
"/ 4",
"+ 15",
". 0",
"////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////",
"////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////",
"//....................................................................................................................//",
"//.......................+++++++++++...........+............+++.....++++++++..........................................//",
"//.......................++...................+++...................++.....++.........................................//",
"//.......................++..................++.++..........+++.....++.....++.........................................//",
"//.......................++.................++...++.........+++.....+++...++..........................................//",
"//.......................+++++++++++.......+++++++++........+++.....+++++++...........................................//",
"//................................++......++.......++.......+++.....++...++...........................................//",
"//.......................+++++++++++.....++.........++......+++.....++....++..........................................//",
"//.......................+++++++++++....++...........++.....+++.....++.....++.........................................//",
"//....................................................................................................................//",
"////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////",
"////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////"
};



