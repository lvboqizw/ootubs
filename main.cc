
#include "machine/cgascr.h"
#include "device/cgastr.h"
#include "object/o_stream.h"


CGA_Screen scr;
CGA_Stream kout;

void test_PrintAChar() {
	char c = 'a';
	scr.print(&c, 1, WHITE);
}

void test_PrintString() {
	char* text = "in order to test the print funktion, i must write a sentence with more than 80 characters, and now i think that's enough.";
	scr.print(text, 119, WHITE);

}

void test_SetCursor() {
	scr.setpos(0, 4);
}

void test_blick() {
	scr.show(0,0,'a',WHITE);
}

void test_StrBuf() {
	int a = 7;
	kout << "a = " << a << endl;
	// scr.print(kout.buffer,65, WHITE);
	// kout << endl;
	int x,y;
	scr.getpos(x, y);
	scr.show(x, y,'c',WHITE);
	//scr.print(kout.buffer,65, WHITE);
}

void test_O_Stream() {
	unsigned short unsign = 65535;

	// kout << "(oct)" << oct << unsign << endl;
	// kout << "(dec)" << dec << unsign << endl;
	// // scr.print(kout.buffer,3, WHITE);
	kout << "unsigned number: (bin)" << bin << unsign << endl;
	//	scr.print(kout.buffer,65, WHITE);
	kout << "(bin)" << bin << unsign << endl;
	// 	scr.print(kout.buffer,3, WHITE);
	// kout << "unsigned" << bin << unsign << endl;
	// 	scr.print(kout.buffer,3, WHITE);
	// kout << "(hex)" << hex << unsign << endl;
}

void test_signedNumber() {
	int a = -1;

	kout << "a = " << hex << a << endl;
}

int main()
{
	test_SetCursor();
	// test_PrintString();
	test_PrintAChar();
	// test_StrBuf();
	// test_O_Stream();
	// test_SetCursor();
	// test_signedNumber();



	return 0;
}

