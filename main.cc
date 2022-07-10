/* Add your code here */ 

#include "device/cgastr.h"
#include "device/keyboard.h"
#include "device/panic.h"
#include "device/watch.h"
#include "machine/cgascr.h"
#include "machine/keyctrl.h"
#include "machine/key.h"
#include "machine/cpu.h"
#include "machine/plugbox.h"
#include "machine/pic.h"
#include "meeting/bellringer.h"
#include "object/o_stream.h"
#include "syscall/guarded_scheduler.h"
#include "syscall/guarded_organizer.h"
#include "syscall/guarded_semaphore.h"
#include "syscall/guarded_keyboard.h"
#include "syscall/guarded_buzzer.h"
#include "thread/scheduler.h"
#include "thread/dispatch.h"
#include "user/appl.h"
#include "user/loop.h"
#include "user/idle.h"


#define STACK_SIZE 512

unsigned char stack1[STACK_SIZE];
unsigned char stack2[STACK_SIZE];
unsigned char stack3[STACK_SIZE];
unsigned char stack4[STACK_SIZE];

CPU cpu;
CGA_Screen scr;
Plugbox plugbox;
PIC pic;
Panic panic;
CGA_Stream kout;
Guard guard;
Bellringer bellringer;
Idle idle(stack4 + STACK_SIZE);
Guarded_Keyboard keyboard;
Guarded_Scheduler guarded_scheduler;
Guarded_Organizer guarded_organizer;
Guarded_Semaphore guarded_semaphore(2);

// Guarded_Buzzer guarded_buzzer;
Watch watch(1000);


// void task3test() {								// question: why without this loop, the keyboard interput will not work?
// 	while(1) {									// the cpu is disabled from somewhere?
// 		Secure secure;
// 		kout.setpos(10, 10);
// 		kout << "test taks 3";
// 		kout.flush();
// 	}
// }

// void task4test() {
// 	Secure secure;
// 	Application appl(stack1+STACK_SIZE);			// the address start at a high address
// 	scheduler.ready(appl);
// 	scheduler.schedule();								
// }

// void task5test() {
// 	Application appl(stack1+STACK_SIZE);			// the address start at a high address
// 	guarded_scheduler.ready(appl);
// 	guard.enter();									//
// 	watch.windup();								// resume (located in watch epilogie should run after the guard Because after the PIT been set, )
// 	guarded_scheduler.schedule();
// }

void task6test() {
	Application appl(stack1+STACK_SIZE);
	Loop loop(stack2+STACK_SIZE);
	guarded_organizer.ready(appl);
	guarded_organizer.ready(loop);
	guard.enter();
	watch.windup();
	guarded_organizer.schedule();
}

int main()
{
	cpu.enable_int();
	keyboard.plugin();							//after plugin, the keyboard's prologue will be called once and return 0
	// task3test();
	// task4test();
	// task5test();
	task6test();   
	
	// guarded_scheduler.ready(appl);
	// scheduler.ready(appl);
	
	// watch.windup(); 
	// guard.enter();				 
	// watch.windup();               
	// for(int i=0;i < 1000000;i++);
	// guarded_scheduler.schedule();
	// scheduler.schedule();
	kout << "return to main" << endl;
	while(1);
	return 0;
}
