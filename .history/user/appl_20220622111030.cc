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
#include "user/loop.h"

/* GLOBAL VARIABLES */
extern CGA_Screen scr;
extern CGA_Stream kout;
extern CPU cpu;
extern Guarded_Scheduler scheduler;

#define STACK_SIZE 512

unsigned char stack1[STACK_SIZE];
unsigned char stack2[STACK_SIZE];

void Application::action()
{
/* Add your code here */ 
    Loop loop1(stack1 + STACK_SIZE);
    loop1.set_num(1);
    Loop loop2(stack2 + STACK_SIZE);
    loop2.set_num(2);

    scheduler.ready(loop1);
    scheduler.ready(loop2);
    int i = 0;
    int j = 0;
    while(1) {
        Secure secure;
        kout.setpos(0, 5);
        kout << "in the application";
        kout.flush();
        ++ i;
        ++ j;
        if(i == 40000) {
            kout << endl;
            scheduler.kill(loop1);                   //kill the loop application
            kout << "kill the loop1" << endl;
        }
        if(j == 80000) {
            kout << endl;
            kout << "end of the application" << endl;
            scheduler.exit();                        //terminate the application itself
        }
       // scheduler.resume();
    }
}