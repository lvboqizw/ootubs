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
	char* pointer=buffer;		// pointer point at the right now readed character
	char* flag=buffer;   		// flag point at the begin of the buffer
	int x,y;
	char out;
	while(pointer != buf_end) {
		out = *pointer; 

		if(out == '\n') {       // if get the '\n', set the cursor at the beginning of the line bellow
			print(flag, pointer - flag, WHITE);
			getpos(x,y);
			x = 0;
			++ y;
			if(y > 24)
			{
				y = 24;
				scroll();
			}
			setpos(x,y);
			flag = pointer;
		}
		++ pointer;	
	}
	if(out != '\n')
		print(flag,(buf_end - flag),WHITE);
	buf_end = buffer;
}