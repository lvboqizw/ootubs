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

#include "user/loop.h"
#include "device/cgastr.h"

extern CGA_Stream kout;

void Loop::action() {
    // int i = 0;
    // while(i < 10) {
    //     kout.setpos(0, 5);
    //     kout<< "Loop for " << i << " times";
    //     kout.flush();
    //     ++i;
    // }
    kout<< "output from loop" << endl;
}


