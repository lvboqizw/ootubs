/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                                 L O O P                                   */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Loop is a thread that does nothing else but count upwards and print this  */
/* on the screen. In between, it yields the CPU. The Scheduler then decides  */
/* which thread shall run next.                                              */
/*****************************************************************************/

/* Add your code here */ 
#include "user/loop.h"
#include "user/appl.h"
#include "device/cgastr.h"
#include "machine/cgascr.h"
#include "machine/cpu.h"
#include "guard/secure.h"
#include "thread/scheduler.h"
/* Add your code here */ 
 
/* GLOBAL VARIABLES */

extern CGA_Stream kout;
extern Scheduler scheduler;
extern Secure secure;

 
void Loop::action()
{
    while(1) {
        Secure secure;
        kout.setpos(0, 7);
        kout << "in the loop";
        kout.flush();
        scheduler.resume();
    }

}
