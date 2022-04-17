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
	while(start != buf_end)
	{
		out = *start; 	

		if(out == '\n')
		{
			print(pointer,start - pointer,WHITE);
			getpos(x,y);
			x = 0;
			y++;
			if(y>24)
			{
				y = 24;
				scroll();
			}
			setpos(x,y);
			pointer = start;
		}

		start++;	
	}
	if(out != '\n')
		print(pointer,(buf_end - pointer),WHITE);
	buf_end = buffer;
}