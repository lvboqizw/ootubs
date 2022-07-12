#include "device/cgastr.h"
#include "device/keyboard.h"
#include "device/panic.h"
#include "device/watch.h"
#include "machine/cgascr.h"
#include "machine/keyctrl.h"
#include "machine/key.h"
#include "machine/cpu.h"
#include "machine/plugbox.h"
#include "machine/speaker.h"
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
#include "user/write.h"
#include "user/system.h"
#include "global.h"


unsigned char stack_idle[STACK_SIZE];
unsigned char stack_sys[STACK_SIZE];
unsigned char stack_appl[STACK_SIZE];
unsigned char stack_loop[STACK_SIZE];
unsigned char stack_write[STACK_SIZE];

CPU cpu;
CGA_Screen scr;
Plugbox plugbox;
PIC pic;
Panic panic;
CGA_Stream kout;
Guard guard;
Bellringer bellringer;
Idle idle(stack_idle + STACK_SIZE);
Guarded_Keyboard guarded_keyboard;
Guarded_Scheduler guarded_scheduler;
Guarded_Organizer guarded_organizer;
Guarded_Semaphore kout_semaphore(1);
Guarded_Semaphore process_sem(0);


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
// 	Application appl(stack_appl+STACK_SIZE);			// the address start at a high address
// 	scheduler.ready(appl);
// 	scheduler.schedule();								
// }

// void task5test() {
// 	Application appl(stack_appl+STACK_SIZE);			// the address start at a high address
// 	guarded_scheduler.ready(appl);
// 	guard.enter();									//
// 	watch.windup();								// resume (located in watch epilogie should run after the guard Because after the PIT been set, )
// 	guarded_scheduler.schedule();
// }

// void task6test() {
// 	Application appl(stack_appl+STACK_SIZE);
// 	Loop loop(stack_loop+STACK_SIZE);
// 	Write write(stack_write + STACK_SIZE);

// 	guarded_organizer.ready(appl);
// 	guarded_organizer.ready(loop);
// 	guarded_organizer.ready(write);
// 	guard.enter();
// 	watch.windup();
// 	guarded_organizer.schedule();
// }

void task7test() {
	System sys(stack_sys + STACK_SIZE);
	guarded_organizer.ready(sys);
	guard.enter();
	watch.windup();
	guarded_organizer.schedule();
}

int main()
{
	cpu.enable_int();
	guarded_keyboard.plugin();							//after plugin, the keyboard's prologue will be called once and return 0
	// task3test();
	// task4test();
	// task5test();
	// task6test();  
	task7test();

	// while(1);
	return 0;
}
