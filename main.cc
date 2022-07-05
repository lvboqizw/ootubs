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
#include "syscall/guarded_organizer.h"
#include "syscall/guarded_semaphore.h"
#include "syscall/guarded_keyboard.h"
#include "thread/scheduler.h"
#include "thread/dispatch.h"
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
Watch watch(20000);
Guarded_Keyboard keyboard;
Guarded_Organizer guarded_organizer;

unsigned char stack[STACK_SIZE];


void task3test() {								// question: why without this loop, the keyboard interput will not work?
	while(1) {									// the cpu is disabled from somewhere?
		Secure secure;
		kout.setpos(10, 10);
		kout << "test taks 3";
		kout.flush();
	}
}

void task4test() {
	Secure secure;
	Application appl(stack+STACK_SIZE);			// the address start at a high address
	scheduler.ready(appl);
	scheduler.schedule();								
}

void task5test() {
	Application appl(stack+STACK_SIZE);			// the address start at a high address
	guarded_scheduler.ready(appl);
	guard.enter();
	watch.windup();								// resume (located in watch epilogie should run after the guard Because after the PIT been set, )
	guarded_scheduler.schedule();
}

void task6test() {

}

int main()
{
	cpu.enable_int();
	keyboard.plugin();							//after plugin, the keyboard's prologue will be called once and return 0
	// task3test();
	// task4test();
	// task5test();   
	
	// guarded_scheduler.ready(appl);
	// scheduler.ready(appl);
	
	// watch.windup(); 
	// guard.enter();				 
	// watch.windup();               
	// for(int i=0;i < 1000000;i++);
	// guarded_scheduler.schedule();
	// scheduler.schedule();
	while(1){};

	return 0;
}
