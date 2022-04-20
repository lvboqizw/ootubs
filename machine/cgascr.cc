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
        if(text[i] == '\n'){        // check if the inputed character is '\n'?
            x = 0;                  // get '\n', move the cursor to the beginning of the next line
            if(y >= COLUMN) {       // is the cursor on the last line?
                scroll();           // the cursor on the last line, scroll up the screen
            } else {
                ++y;                // not on the last line, add one to the y
            }
        } else {                    // get a character expect '\n'
            if(x >= ROW) {          // is the cursor on the last position of a line?
                x = 0;              // the cursor is on the last position of a line
                if(y >= COLUMN) {   // is the cursor on the last line?
                    y = COLUMN - 1; // the cursor is on the last line, set the y = 24(the last line)
                    scroll();       // scroll up the screen
                }else {
                    ++y;            // the cursor is not on the last line, add one to the y
                }
            }
            show(x, y, text[i], attrib);    // show the character on the right now position
            ++x;                            // move cursor to the next position
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
	setpos(x,y);                    // set the cursor position on the last
}

void CGA_Screen::scroll() {
    int y = COLUMN - 1;             // set y at the last line(24)
    for(int j = 1; j <= COLUMN - 1; ++j) {       // in loop copy each line to the previous line, start with the second line(begin with 1)
        copy_to_pre_line(j);
    }
    for(int i = 0; i < ROW; ++i) {              // set the character on the last line to the ' ' 
        show(i, y, ' ', WHITE);
    }
    setpos(0, y);
}

void CGA_Screen::copy_to_pre_line(int j) {
    char* this_line = get_addr(0, j);           // get the first character's address of the given line
    char* pre_line = get_addr(0, j-1);          // get the first character's address of the previous line of the given line
    for(int i = 0; i < ROW ; ++i) {
        *(pre_line + i*2) = *(this_line + i*2); // copy each character for the given line to the previous line
    }
}

