/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                             C G A _ S C R E E N                           */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* This class allows accessing the PC's screen.  Accesses work directly on   */
/* the hardware level, i.e. via the video memory and the graphic adapter's   */
/* I/O ports.                                                                */
/*****************************************************************************/

#include "machine/cgascr.h"

/* Add your code here */ 
/* PRIVATE METHODS */
char* get_addr(int x, int y) {
    return (char *)CGA_START + 2 * (x + y * 80);
}

/* PUBLIC METHODS */

void CGA_Screen::show(int x, int y, char c, unsigned char attrib){
    pos = get_addr(x, y);
    *pos = c;
    *(pos + 1) = attrib;
}

void CGA_Screen::setpos(int x, int y) {
    cur_x = x;
    cur_y = y;
}

void CGA_Screen::getpos(int &x, int &y) {
    x = cur_x;
    y = cur_y;
}

void CGA_Screen::print(char* text, int length, unsigned char attrib) {}

