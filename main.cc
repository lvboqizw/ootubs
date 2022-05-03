/* Add your code here */ 

#include "machine/cgascr.h"
#include "machine/keyctrl.h"
#include "machine/key.h"
#include "machine/cpu.h"
#include "machine/plugbox.h"
#include "device/cgastr.h"
#include "device/panic.h"
#include "object/o_stream.h"
#include "user/appl.h"

//machine
CGA_Screen scr;
Key key;
Keyboard_Controller kc;
CPU cpu;
Plugbox plugbox;
//device
Panic panic;
//object
CGA_Stream kout;
//user
Application appl;


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

void test_O_Stream() {
	unsigned long unsign = 1ul << 31;//4294967295;

	kout << "unsigned number: (bin)" << bin << unsign << endl;
	kout << "(oct)" << oct << unsign << endl;
	kout << "(dec)" << dec << unsign << endl;
	// // scr.print(kout.buffer,3, WHITE);
	// kout << 'a' << endl;
	kout << "(hex)" << hex << unsign << endl;
}

void test_signedNumber() {
	signed long a = -1;

	kout << "a = " << oct << a << endl;
}


void ktrl_test(){

	Keyboard_Controller kc;
	Key key;
	char a;

	kc.set_repeat_rate(30,2);
	kc.set_led(1,1);
	kc.set_led(2,1);
	kc.set_led(4,1);
	while (true){
		key=kc.key_hit();
		if(key.valid()){
			a=key.ascii();
			kout <<a<< '\0';
		}
		kout.flush();
	}
	
}


int main()
{
	kout<<"funktioniert!"<<endl;
	appl.action();
	plugbox.report(300);

	return 0;
}