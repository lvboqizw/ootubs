
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
	char long_text[] = "Wait for control to return from inferior to debugger. If inferior gets a signal, we may decide to start it up again instead of returning. That is why there is a loop in this function. When this function actually returns it means the inferior should be left stopped and GDB should read more commands\n";
   	char eighty_text[] = "one two three four five six seven eight nine ten eleven twelf thirteen fourteen.";
	char sev_nine[] = "one two three four five six seven eight nine ten eleven twelf thirteen fourtee";
	scr.print(long_text, sizeof(long_text)/sizeof(char), WHITE);
	// scr.print(eighty_text, sizeof(eighty_text)/sizeof(char), RED);
	// scr.print(sev_nine, sizeof(sev_nine)/sizeof(char), WHITE);
	// scr.print(text, sizeof(text)/sizeof(char), WHITE);
	// scr.print(text, sizeof(text)/sizeof(char), BLUE);
}

void test_SetCursor() {
	scr.setpos(0, 23);        // work fine with 0, 1, 4, 7, 10, 11, 13, 14, 16, 17, 20; error with 2, 3, 5, 6, 8, 9, 12, 15, 18, 19, 21, 22, 23, 24
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
	scr.clear();
	// test_PrintAChar();
	// test_O_Stream();
	// test_SetCursor();
	// for (int i = 0; i < 6; ++ i) {
	// 	test_PrintString();
	// }
	// scr.scroll();
	// test_signedNumber();
	test_O_Stream();

	return 0;
}