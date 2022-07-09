/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                               B U Z Z E R                                 */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* An "alarm clock" is a synchronization object that allows one or more      */
/* threads to put themselves to sleep for a specified time.                  */
/*****************************************************************************/

/* INCLUDES */
#include "meeting/buzzer.h"
#include "meeting/bellringer.h"
#include "syscall/guarded_organizer.h"

extern CGA_Stream kout;


extern Guarded_Organizer guarded_organizer;
extern Bellringer bellringer;

Buzzer::~Buzzer() {
    bellringer.cancel(this);
    Thread *thread = (Thread*)dequeue();

    while(thread)
    {
        thread -> waiting_in(0);
        guarded_organizer.ready(*thread);
        thread = (Thread*)dequeue();
    }
}

void Buzzer::set(int ms){
    this->Bell::wait(ms);
}

void Buzzer::sleep(){//放进waitingroom,直到铃响
    Thread *act = (Thread*)(guarded_organizer.active());
    bellringer.job(this, this->Bell::wait());
    guarded_organizer.block(*act, *this);
}

void Buzzer::ring(){
    // //-----------------------------------------------------------
    // kout << "been ringed";
    // kout.flush();
    // //-----------------------------------------------------------

    Thread *next =(Thread*) this->dequeue();
    guarded_organizer.wakeup(*next);

}