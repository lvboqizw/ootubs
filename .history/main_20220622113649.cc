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
#include "syscall/guarded_scheduler.h"
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
Guarded_Scheduler scheduler;
Watch watch(1000);
Keyboard keyboard;


unsigned char stack[STACK_SIZE];


int main()
{
	cpu.enable_int();
	watch.windup();
	kout<<"Running"<<endl;
	Application appl(stack+STACK_SIZE);      // the address start at a high address
	scheduler.ready(appl);
	guard.enter();
	scheduler.Scheduler::schedule();

	return 0;
}
