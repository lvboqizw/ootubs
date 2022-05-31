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
extern Scheduler scheduler;

#define STACK_SIZE 512

unsigned char stack2[STACK_SIZE];

void Application::action()
{
/* Add your code here */ 
    Loop loop(stack2 + STACK_SIZE);
    scheduler.ready(loop);
    int i = 0;
    while(1) {
        Secure secure;
        kout.setpos(0, 5);
        kout << "in the application";
        kout.flush();
        ++ i;
        if(i == 100) {
            kout << "end of appli" << endl;
            scheduler.exit();
        }
        scheduler.resume();
    }
}