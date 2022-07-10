/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                         A P P L I C A T I O N                             */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* The Application class defines the (only) application for OOStuBS.         */
/*****************************************************************************/

/* INCLUDES */

#include "user/appl.h"
#include "device/cgastr.h"
#include "machine/cgascr.h"
#include "machine/cpu.h"
#include "guard/secure.h"
#include "thread/scheduler.h"
#include "thread/dispatch.h"
#include "user/loop.h"
#include "syscall/guarded_scheduler.h"
#include "syscall/guarded_buzzer.h"
#include "syscall/guarded_organizer.h"
#include "syscall/guarded_semaphore.h"
#include "syscall/guarded_keyboard.h"

/* GLOBAL VARIABLES */
extern CGA_Screen scr;
extern CGA_Stream kout;
extern CPU cpu;
extern Guarded_Scheduler guarded_scheduler;
extern Guarded_Organizer guarded_organizer;
extern Guarded_Semaphore guarded_semaphore;
extern Guarded_Keyboard guarded_keyboard;
extern Scheduler scheduler;



#define STACK_SIZE 512

unsigned char stack5[STACK_SIZE];
unsigned char stack6[STACK_SIZE];

void Application::action()
{
    //--------------------TASK4/5---------------------//
    // Loop loop1(stack5 + STACK_SIZE);
    // loop1.set_num(1);
    // Loop loop2(stack6 + STACK_SIZE);
    // loop2.set_num(2);
    //------------------------------------------------//

    //---------------------TASK 4---------------------//
    // scheduler.ready(loop1);
    // scheduler.ready(loop2);
    // while(1) {
    //     Secure secure;
    //     kout.setpos(0, 18);
    //     kout << "in the application";
    //     kout.flush();
    //     scheduler.resume();
    // }
    //------------------------------------------------//

    //---------------------TASK5----------------------//
    // guarded_scheduler.ready(loop1);
    // guarded_scheduler.ready(loop2);
    // while(1) {
    //     Secure secure;
    //     kout.setpos(0, 18);
    //     kout << "in the application";
    //     kout.flush();
    // }
    //------------------------------------------------//

    //---------------------TASK6----------------------//
    // int wait = 200;
    // int count = 0;
    // Guarded_Buzzer buzzer;
    // unsigned short x, y;

    // while (1){
    //     buzzer.set(wait);
    //     // kout <<"appl sleep" <<endl;
    //     buzzer.sleep();
    //     // kout <<"appl wake" <<endl;  
    //     guarded_semaphore.wait();
    //     kout.getpos(x, y);
    //     kout.setpos(0,18);
    //     kout << "Appl: Doing stuff(" << count++ << ")";
    //     kout.flush();
    //     kout.setpos(x,y);
    //     guarded_semaphore.signal();
    for(;;){
    Key key = guarded_keyboard.getkey();
    guarded_semaphore.p();
    kout<<key<<endl;
    guarded_semaphore.v();
    }
    
    //------------------------------------------------//
}