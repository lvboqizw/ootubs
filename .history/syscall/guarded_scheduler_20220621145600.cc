/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                    G U A R D E D _ S C H E D U L E R                      */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Implements the system-call interface to the Scheduler.                    */
/*****************************************************************************/

<<<<<<< HEAD
/* Add your code here */ 
=======

#include "syscall/guarded_scheduler.h"

void Guarded_Scheduler::ready(Thread& that) {
    {
        Secure secure;
        Scheduler::ready((Entrant&) that);
    }
}

void Guarded_Scheduler::exit() {
    {
        Secure secure;
        Scheduler::exit();
    }
}

void Guarded_Scheduler::kill(Thread& that) {
    {
        Secure secure;
        Scheduler::kill((Entrant&) that);
    }
}

void Guarded_Scheduler::resume() {
    {
        Secure secure;
        Scheduler::resume();
    }
}

>>>>>>> b45b96f7f63bc21cda9c395bee0aa3af01f8c910
