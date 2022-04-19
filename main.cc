
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
	char* text = "in order to test the print funktion, i must write a sentence with more than 80 characters, and now i think that's enough.\n";
	scr.print(text, 123, WHITE);

}

void test_SetCursor() {
	scr.setpos(0, 4);
}

void test_blick() {
	scr.show(0,0,'a',WHITE);
}

void test_O_Stream() {
	unsigned short unsign = 65535;
	kout << "unsigned number : " << unsign << endl;
	kout << "Bin of the number: " << bin << unsign << endl;
	kout << "Octal of the number: " << oct << unsign << endl;
}

void test_signedNumber() {
	long a = -1;

	kout << "a = " << oct << a << endl;
}

int main()
{
	// test_PrintString();
	// test_PrintAChar();
	test_O_Stream();
	// test_SetCursor();
	// test_signedNumber();

	return 0;
}

