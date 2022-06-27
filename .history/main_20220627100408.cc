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
#include "syscall/guarded_scheduler.h"
#include "thread/scheduler.h"
#include "user/appl.h"
#include "user/loop.h"
#include "device/watch.h"

#define STACK_SIZE 512

CGA_Screen scr;

CPU cpu;
Plugbox plugbox;
PIC pic;
Panic panic;
CGA_Stream kout;
Guard guard;
Guarded_Scheduler guarded_scheduler;
Scheduler scheduler;
Watch watch(1000);
Keyboard keyboard;


unsigned char stack[STACK_SIZE];


int main()
{
	cpu.enable_int();

	Application appl(stack+STACK_SIZE);      // the address start at a high address
	// kout<<"Running1"<<endl;
	
	guarded_scheduler.ready(appl);
	//之前要确保没有epilogue在运行,有一个lock,guard went bevor windup.
	//scheduler.ready(appl);
	guard.enter();
	guarded_scheduler.schedule();
	//这之前不能运行resume
	//scheduler.schedule();
	watch.windup();
	return 0;
}
