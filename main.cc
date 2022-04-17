
#include "machine/cgascr.h"
#include "device/cgastr.h"
#include "object/o_stream.h"


int main()
{
/* Add your code here */ 
CGA_Screen scr;
scr.show(0, 0, 'q', 0x0f);

CGA_Stream kout;

int a = 2147483647;

kout << "a = " << dec << a << " ist hexadezimal " << hex << a << endl;

int b = -1;

kout << "b = " << oct << b << " ist hexadezimal " << hex << b << endl;

kout.flush();


char* text = "abcdefghijklmnopqrstuvwxyz";

//scr.print(text, 27, 0x0f);



	return 0;
}
