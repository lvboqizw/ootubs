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
#include "thread/scheduler.h"
#include "user/appl.h"
#include "user/loop.h"
<<<<<<< HEAD
=======
#include "thread/scheduler.h"
>>>>>>> jing

#define STACK_SIZE 512

CGA_Screen scr;
CPU cpu;
Plugbox plugbox;
PIC pic;
Panic panic;
CGA_Stream kout;
Guard guard;
Scheduler scheduler;
Keyboard keyboard;
Scheduler scheduler;



unsigned char stack1[STACK_SIZE];
unsigned char stack2[STACK_SIZE];

int main()
{
	cpu.enable_int();
	kout<<"Running"<<endl;
	//keyboard.plugin();
	Application appl(stack1+STACK_SIZE);
	Loop loop1(stack2+STACK_SIZE);
	scheduler.ready(appl);
	//scheduler.ready(loop1);
	scheduler.schedule();
	//scheduler.resume();
	// appl.action();
	kout << "return in main" << endl;
	

	return 0;
}