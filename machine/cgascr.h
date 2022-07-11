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

#define ROW 80
#define COLUMN 25

#define INDEXREGITSER 0x3d4
#define DATAREGISTER 0x3d5

// #define BLACK 0x00
// #define BLUE 0x01
// #define GREEN 0x02
// #define CYAN 0x03
// #define RED 0x04
// #define MAGENTA 0x05
// #define BROWN 0x06
// #define LIGHT_GRAY 0x07
// #define DARK_GRAY 0x08
// #define LIGHT_BLUE 0x09
// #define LIGHT_GREEN 0x0a
// #define LIGHT_CYAN 0x0b
// #define LIGHT_RED 0x0c
// #define LIGHT_MAGENTA 0x0d
// #define YELLOW 0x0e
// #define WHITE 0x0f

enum color {
	BLACK = 0x00,
	BLUE = 0x01,
	GREEN = 0x02,
	CYAN = 0x03,
	RED = 0x04,
	MAGENTA = 0x05,
	BROWN = 0x06,
	LIGHT_GRAY = 0x07,
	DARK_GRAY = 0x08,
	LIGHT_BLUE = 0x09,
	LIGHT_GREEN = 0x0a,
	LIGHT_CYAN = 0x0b,
	LIGHT_RED = 0x0c,
	LIGHT_MAGENTA = 0x0d,
	YELLOW = 0x0e,
	WHITE = 0x0f,
};

#define DEFAULT_SCREEN_ATTRIB WHITE

class CGA_Screen {
private:

	char *pos;
	
	char* get_addr(int x, int y);

	CGA_Screen(const CGA_Screen &copy); // prevent copying
protected:
	unsigned char attrib;
public:
	CGA_Screen();
	// show a character on the screen
	void show(unsigned short x, unsigned short y, char c, unsigned char attrib);
	
	//set a new position to the cursor
	void setpos(unsigned short x, unsigned short y);

	//get the cursor's position
	void getpos(unsigned short &x, unsigned short &y);

	//print a string of charcaters
	void print (char* text, int length, unsigned char attrib);

	// scroll the information on the screen up forword
	void scroll();

	// clean up the screen
	void clear();
	
	/**
	 * @brief Set up the screen and characters color.
	 * 
	 * @param frontcolor Character's color, from 0 to 15
	 * @param backcolor Background's color, from 0 to 7
	 * @param blink whether the screen blink or not
	 */
	void setcolor(color frontcolor, color backcolor);
};

#endif
