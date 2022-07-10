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
#include "syscall/guarded_scheduler.h"
/* Add your code here */ 
 
/* GLOBAL VARIABLES */

extern CGA_Stream kout;
extern Guarded_Scheduler guarded_scheduler;
extern Secure secure;
extern Scheduler scheduler;

 
void Loop::action()
{
    unsigned short x, y;
    kout.getpos(x, y);
    kout << endl;
    while(1) {
        Secure secure;
        kout.setpos(x, y);
        kout << "in the loop" << endl ;
        // kout.flush();
        // scheduler.resume();              // TASK 4
    }
}

void Loop::set_num(int i) {
    num = i;
}
