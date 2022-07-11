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


// Calculate the address of the cursor
char* CGA_Screen::get_addr(int x, int y) {
    return (char *)CGA_START + 2 * (x + y * ROW);
}

/* PUBLIC METHODS */
// initialization the screen
CGA_Screen::CGA_Screen() {
    this->attrib = DEFAULT_SCREEN_ATTRIB;   // default color : white
    clear();
}

// show one character on the given position
void CGA_Screen::show(unsigned short x, unsigned short y, char c, unsigned char attrib){
    pos = get_addr(x, y);
    *pos = c;
    *(pos + 1) = attrib;
}

void CGA_Screen::setpos(unsigned short x, unsigned short y) {
    IO_Port indexreg(INDEXREGITSER);                //indirect access
    IO_Port datareg(DATAREGISTER);

    int pos = (x+(y*80));                   //calculate the position

    indexreg.outb(15);
    datareg.outb(pos & 0xff);               //write first half (8bit)
    indexreg.outb(14);
    datareg.outb((pos >> 8) & 0xff);        //wirte second half (3bit)
}

void CGA_Screen::getpos(unsigned short &x, unsigned short &y) {
    IO_Port indexreg(INDEXREGITSER);                //indirect access
    IO_Port datareg(DATAREGISTER);

    indexreg.outb(15);
    char cursor1 = datareg.inb();           //fetch first half
    indexreg.outb(14);
    char cursor2 = datareg.inb();           //fetch second half

    int pos = (cursor1 & 0xff) | ((cursor2 & 0xff) << 8);    //put them together to one position

    x = (pos)%80;                         //write the positionparameters back to the given addresses
    y = (pos)/80;
}

void CGA_Screen::print(char* text, int length, unsigned char attrib) {
    unsigned short curpos_x;
    unsigned short curpos_y;
    getpos(curpos_x, curpos_y);                                 //here I am right now
    for (int i = 0;i<length;i++){
        if(text[i]=='\n'){
            curpos_x=0;
            ++curpos_y;
        } else {
            show(curpos_x, curpos_y, text[i], attrib);   //each char for it's own
            ++curpos_x;
        }
        if(curpos_x>=79){                                       //don't go over the edge
            ++curpos_y;                                         //next line
            curpos_x=0;                                         //start from the beginning
        }
        if(curpos_y>24){
            scroll();
            curpos_y=24;
        }
    }
    setpos(curpos_x,curpos_y);
}

void CGA_Screen::scroll() {
    char* pos = (char*) 0xB80A0;            //start from the second line
    for(unsigned int i=0;i<24;i++){         //cycle through lines
        for(unsigned int j=0;j<80;j++){     //cycle thorugh columns
            show(j,i,*pos,*(pos+1));
            pos+=2;
        }
    }
    char att = this->attrib;
    for(int k=0;k<80;k++){
        show(k,24,' ',att);                 //fill the last line with spaces
    }
    setpos(0,24);
}

void CGA_Screen::clear() {
    char* CGA = (char*) 0xb8000;
    char att = this->attrib;
    for(unsigned int i=0;i<80*2*25;i++){
        CGA[i]=' ';                 //set space
        i++;
        CGA[i]=att;                 //set attribute
    }
    setpos(0,0);                    //start from the beginning
}

void CGA_Screen::setcolor(color frontcolor, color backcolor){
    this->attrib = (((backcolor << 4) & 0xf0) | (frontcolor & 0xf));
}

void CGA_Screen::changOneLineColor(unsigned short y, unsigned char new_attrib) {
    for(int i = 0; i < 40; i++) {
        char* tmpad = get_addr(i, y);
        *(tmpad + 1) = new_attrib;
    }
}