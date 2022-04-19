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



void CGA_Stream::flush()
{
	char* start=buffer;
	char* pointer=buffer;
	int x,y;
	char out;
	while(pointer < buf_end)
	{
		out = *pointer; 	

		if(out == '\n')
		{
			print(start,pointer - start,WHITE);
			getpos(x,y);
			x = 0;
			++ y;
			if(y > 24)
			{
				y = 24;
				scroll();
			}
			setpos(x,y);
			start = pointer;
		}
		++ pointer;	
	}
	if(out != '\n') {
		print(start,buf_end - start,WHITE);
	}
	buf_end = buffer;
}