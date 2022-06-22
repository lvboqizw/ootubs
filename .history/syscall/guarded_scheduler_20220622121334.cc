/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                    G U A R D E D _ S C H E D U L E R                      */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Implements the system-call interface to the Scheduler.                    */
/*****************************************************************************/


#include "syscall/guarded_scheduler.h"
#include "device/cgastr.h"

extern CGA_Screen kout;

void Guarded_Scheduler::ready(Thread& that) {
    {
        Secure secure;
        kout << "guard ready" << endl;
        this->Scheduler::ready(that);
    }
}

void Guarded_Scheduler::exit() {
    {
        Secure secure;
        this->Scheduler::exit();
    }
}

void Guarded_Scheduler::kill(Thread& that) {
    {
        Secure secure;
        this->Scheduler::kill( that);
    }
}

void Guarded_Scheduler::resume() {
    {
        Secure secure;
        this->Scheduler::resume();
    }
}

