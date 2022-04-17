
#include "machine/cgascr.h"
#include "device/cgastr.h"


int main()
{
/* Add your code here */ 
CGA_Screen scr;
scr.show(0, 0, 'q', 0x0f);

CGA_Stream kout;

// kout << "a" << endl;

// kout.flush();


char* text = "abcdefghijklmnopqrstuvwxyz";

//scr.print(text, 27, 0x0f);



	return 0;
}
