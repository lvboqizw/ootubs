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
    return (char *)CGA_START + 2 * (x + y * ROW);
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
    cur.position = x + y * ROW;
    index.outb(14);
    data.outb((unsigned char)(cur.position >> 8) & 0xff);
    index.outb(15);
    data.outb((unsigned char) cur.position & 0xff);
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
        if(text[i] == '\n'){
            x = 0;
            if(y >= COLUMN) {
                scroll();
            } else {
                ++y;
            }
        } else {
            if(x >= ROW) {
                x = 0;
                if(y >= COLUMN) {
                    y = COLUMN - 1;
                    scroll();
                }else {
                    ++y;
                }
            }
            show(x, y, text[i], attrib);
            ++x;
        }
		// if(x > 79 || text[i] == '\n') {
		// 	x = 0;
		// 	if(y == 24)
		// 		scroll();
		//  	else
		// 		++y;
		// }
        // if(text[i] != '\n') {
		//     show(x, y, text[i], attrib);
        //     ++ x;
        // }
	}
	setpos(x,y);
}

void CGA_Screen::scroll() {
    int y = COLUMN - 1;
    for(int j = 1; j < COLUMN - 1; ++j) {
        copy_to_pre_line(j);
    }
    for(int i = 0; i < ROW; ++i) {
        show(i, y, ' ', WHITE);
    }
    setpos(0, y);
}

void CGA_Screen::copy_to_pre_line(int j) {
    char* this_line = get_addr(0, j);
    char* pre_line = get_addr(0, j-1);
    for(int i = 0; i < ROW ; ++i) {
        *(pre_line + i*2) = *(this_line + i*2);
    }
}

