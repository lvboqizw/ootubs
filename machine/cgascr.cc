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
#include "machine/io_port.h"

/* Add your code here */ 

// Calculate the address of the cursor
char* CGA_Screen::get_addr(int x, int y) {
    return (char *)CGA_START + 2 * (x + y * 80);
}

void copy(char *desti) {
    char *tmp = desti;
    while(desti <= tmp + 158) {
        *desti = *(desti + 160);
        *(desti + 1) = *(desti + 161);
        desti += 2; 
    }
}

/* PUBLIC METHODS */

void CGA_Screen::show(int x, int y, char c, unsigned char attrib){
    pos = get_addr(x, y);
    *pos = c;
    *(pos + 1) = attrib;
}

void CGA_Screen::setpos(int x, int y) {
    IO_Port index(INDEXREGITSER);
    IO_Port data(DATAREGISTER);

    Cursor cur;
    cur.position = x + y * 80;
    index.outb(14);
    data.outb((cur.position >> 8) & 0xff);
    index.outb(15);
    data.outb(cur.position & 0xff);
}

void CGA_Screen::getpos(int &x, int &y) {
    IO_Port index(INDEXREGITSER);
    IO_Port data(DATAREGISTER);

    Cursor cur;
    index.outb(15);
    cur.low_reg = data.inb();
    index.outb(14);
    cur.high_reg = data.inb();

    cur.position = (cur.high_reg << 8) | cur.low_reg;
    x = cur.position % 80;
    y = cur.position / 80;
}

void CGA_Screen::print(char* text, int length, unsigned char attrib) {
    int x, y;
    getpos(x, y);
    for(int i = 0; i < length; ++i)
	{
		if(x > 79) {
			x =  0;
			if(y == 24)
				scroll();
		 	else
				++y;
		}
		show(x, y, text[i], attrib);
		++x;
	}
	setpos(x,y);
}

void CGA_Screen::scroll() {
    for(int i = 0; i < 24; ++i){
        copy((char *)CGA_START + i * 160);
    }
    for(int i = 0; i<80; i++){
		*((char *)CGA_START + 24*160+i*2) = ' ';
	}

}

