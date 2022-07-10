/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                    G U A R D E D _ O R G A N I Z E R                      */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* The Guarded_Organizer implements the system call interface to the         */
/* Organizer.                                                                */
/*****************************************************************************/

#include "syscall/guarded_organizer.h"

#include "device/cgastr.h"



void Guarded_Organizer::ready(Thread& that) {
    {
        Secure secure;
        Organizer::ready(that);
    }
}

void Guarded_Organizer::exit() {
    {
        Secure secure;
        Organizer::exit();
    }
}

void Guarded_Organizer::kill(Thread& that) {
    {
        Secure secure;
        Organizer::kill(that);
    }
}

void Guarded_Organizer::resume() {
    {
        Secure secure;
        this->Scheduler::resume();
    }
}
