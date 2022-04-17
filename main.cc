
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
	kout << "a = " << bin << a;
	scr.print(kout.buffer,65, WHITE);
}

void test_O_Stream() {
	unsigned short unsign = 65535;

	kout << "unsigned number: (bin)" << bin << unsign << endl;
	kout << "(oct)" << oct << unsign << endl;
	kout << "(dec)" << dec << unsign << endl;
	// // scr.print(kout.buffer,3, WHITE);
	// kout << 'a' << endl;
	// kout << "(hex)" << hex << unsign << endl;
}

void test_signedNumber() {
	signed long a = -1;

	kout << "a = " << oct << a << endl;
}

int main()
{
	// test_SetCursor();
	//test_PrintString();
	// test_PrintAChar();
	// test_StrBuf();
	test_O_Stream();
	// test_signedNumber();


	return 0;
}

