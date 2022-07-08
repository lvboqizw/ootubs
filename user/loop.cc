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
#include "syscall/guarded_semaphore.h"
#include "syscall/guarded_buzzer.h"
/* Add your code here */ 
 
/* GLOBAL VARIABLES */

extern CGA_Stream kout;
extern Secure secure;
extern Scheduler scheduler;
extern Guarded_Scheduler guarded_scheduler;
extern Guarded_Semaphore guarded_semaphore;

 
void Loop::action()
{
//---------------------TASK4/5----------------------------//
    // while(1) {
    //     Secure secure;
    //     kout.setpos(0, 19 + num);
    //     kout << "in the loop" << num ;
    //     kout.flush();
    //     // scheduler.resume();              // TASK 4
    // }
//-------------------------------------------------------//

//---------------------TASK6-----------------------------//
int wait = 2000;
    int count = 0;
    Guarded_Buzzer buzzer;

    //Endlosschleife
    while(1) {
        buzzer.set(wait);
        buzzer.sleep();
        guarded_semaphore.wait();
        kout.setpos(0,3);
        kout << "Loop: Doing stuff("<< count++ << ")";
        kout.flush();
        guarded_semaphore.signal();

        //while (wait-- > 0);
        //wait = 10000;
        //buzzer.set(2000);
        //buzzer.sleep();
    }
//-------------------------------------------------------//
}

void Loop::set_num(int i) {
    num = i;
}
