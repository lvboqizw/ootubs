#ifndef __screen_include__
#define __screen_include__

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

#include "machine/io_port.h"

#define CGA_START 0xb8000

#define INDEXREGITSER 0x3d4
#define DATAREGISTER 0x3d5

#define BLACK 0x00
#define BLUE 0x01
#define GREEN 0x02
#define CYAN 0x03
#define RED 0x04
#define MAGENTA 0x05
#define BROWN 0x06
#define LIGHT_GRAY 0x07
#define DARK_GRAY 0x08
#define LIGHT_BLUE 0x09
#define LIGHT_GREEN 0x0a
#define LIGHT_CYAN 0x0b
#define LIGHT_RED 0x0c
#define LIGHT_MAGENTA 0x0d
#define YELLOW 0x0e
#define WHITE 0x0f

class CGA_Screen {
private:
/* Add your code here */ 
	unsigned char attrib;
	char *pos;
	
	char* get_posion(int x, int y);
	void set_attrib();
	char* get_addr(int x, int y);

	CGA_Screen(const CGA_Screen &copy); // prevent copying
public:
	CGA_Screen() {};
	// show a character on the screen
	void show(int x, int y, char c, unsigned char attrib);
	
	//set a new position to the cursor
	void setpos(int x, int y);

	//get the cursor's position
	void getpos(int &x, int &y);

	//print a string of charcaters
	void print (char* text, int length, unsigned char attrib);

	// scroll the information on the screen up forword
	void scroll();
};

// The struct of cursor, to save the characters saved in the two register of cursor
// The high_reg is the 14. register and the low is pointed to the 15. register
struct Cursor
{
	unsigned short position;
	char high_reg;
	char low_reg;
};


#endif
