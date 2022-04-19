/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                         C G A _ S T R E A M                               */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* The CGA_Stream class allows to print different data types as text strings */
/* to a PC's CGA screen.                                                     */
/* For attributes/colors and cursor positioning use the methods of class     */
/* CGA_Screen.                                                               */
/*****************************************************************************/

#include "device/cgastr.h"

CGA_Stream::CGA_Stream() {
	for(int y=0; y<25; ++y) {
        for(int x=0; x<80; ++x) {
            show(x,y,' ',15);
        }
    }
    setpos(0,0);
}

void CGA_Stream::flush() {
	int x, y;
	print(buffer, capacity, WHITE);
	capacity = 0;
}