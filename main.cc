/* Add your code here */ 

#include "machine/cgascr.h"
#include "machine/keyctrl.h"
#include "machine/key.h"
<<<<<<< HEAD
#include "machine/cpu.h"
#include "machine/plugbox.h"
#include "device/cgastr.h"
#include "device/panic.h"
#include "object/o_stream.h"
#include "user/appl.h"

//machine
CGA_Screen scr;
=======
#include "machine/pic.h"

// void test_set_led(){

CGA_Screen scr;
CGA_Stream kout;
Keyboard_Controller kc;
PIC pic;


// void test_PrintAChar() {
// 	char c = 'a';
// 	scr.print(&c, 1, WHITE);
// }

// void test_PrintString() {
// 	char* text = "in order to test the print funktion, i must write a sentence with more than 80 characters, and now i think that's enough.";
// 	scr.print(text, 119, WHITE);

// }

// void test_SetCursor() {
// 	scr.setpos(0, 4);
// }

// void test_blick() {
// 	scr.show(0,0,'a',WHITE);
// }

// void test_StrBuf() {
// 	int a = 7;
// 	kout << "a = " << bin << a;
// 	scr.print(kout.buffer,65, WHITE);
// }

// void test_O_Stream() {
// 	unsigned short unsign = 65535;

// 	kout << "unsigned number: (bin)" << bin << unsign << endl;
// 	kout << "(oct)" << oct << unsign << endl;
// 	kout << "(dec)" << dec << unsign << endl;
// 	// // scr.print(kout.buffer,3, WHITE);
// 	// kout << 'a' << endl;
// 	// kout << "(hex)" << hex << unsign << endl;
// }

// void test_signedNumber() {
// 	signed long a = -1;
>>>>>>> jing

// Keyboard_Controller kc;
CPU cpu;
Plugbox plugbox;
//device
Panic panic;
//object
CGA_Stream kout;
//user
Application appl;


int main()
{
	kout<<"funktioniert!"<<endl;
<<<<<<< HEAD
	appl.action();
	
=======
	// test_SetCursor();
	// test_PrintString();
	// test_PrintAChar();
	// test_StrBuf();
	// test_O_Stream();
	// test_signedNumber();
	// // test_key_hit();
	// // test_set_led();
	// // test_set_repeat_rate();
	ktrl_test();

/* Add your code here */ 

/* Add your code here */ 
>>>>>>> jing

	return 0;
}