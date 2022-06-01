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
/* Add your code here */ 
 
/* GLOBAL VARIABLES */
extern CGA_Screen scr;
extern CGA_Stream kout;
extern CPU cpu;
/* Add your code here */ 
extern Scheduler scheduler;
void Application::action()
{
/* Add your code here */ 
    for(;;){
        kout << "first word from appl" << endl;
        kout << "second word from appl"<<endl;
        kout << "third word from appl"<<endl;
    }
    scheduler.resume();
}