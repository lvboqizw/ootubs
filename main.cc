/* Add your code here */ 
#include "machine/cgascr.h"

int main()
{
/* Add your code here */ 
CGA_Screen scr;
scr.show(0, 0, 'q', 0x0f);
char* text = "abcdefghigklmnopqrstuvwxyz";

scr.print(text, 26, 0x0f);
/* Add your code here */ 

/* Add your code here */ 

	return 0;
}
