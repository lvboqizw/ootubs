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

/* GLOBAL VARIABLES */
extern CGA_Screen scr;
extern CGA_Stream kout;
extern CPU cpu;
extern Guarded_Scheduler guarded_scheduler;
extern Guarded_Organizer guarded_organizer;
extern Guarded_Semaphore guarded_semaphore;
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
    int wait = 1000;
    int count = 0;
    Guarded_Buzzer buzzer;

    while (1){
        buzzer.set(wait);
        buzzer.sleep();
        kout <<"sleep" <<endl;
        guarded_semaphore.wait();
        kout <<"wait" <<endl;
        kout.setpos(0,10);
        kout << "Appl: Doing important stuff(" << count++ << ")";
        kout.flush();
        guarded_semaphore.signal();
    }
    //------------------------------------------------//
}