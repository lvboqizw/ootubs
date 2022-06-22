/* Add your code here */ 

#include "machine/cgascr.h"
#include "machine/keyctrl.h"
#include "machine/key.h"
#include "machine/cpu.h"
#include "machine/plugbox.h"
#include "machine/pic.h"
#include "device/cgastr.h"
#include "device/keyboard.h"
#include "device/panic.h"
#include "object/o_stream.h"
#include "guard/guard.h"
#include "user/appl.h"

#define STACK_SIZE 1024

CGA_Screen scr;
CPU cpu;
Plugbox plugbox;
PIC pic;
Panic panic;
CGA_Stream kout;
Guard guard;
Keyboard keyboard;

unsigned char stack1[STACK_SIZE];

int main()
{
	cpu.enable_int();
	kout<<"Running"<<endl;
	//keyboard.plugin();
	Application appl(stack1);
	appl.action();
	kout << "return in main" << endl;
	

	return 0;
}