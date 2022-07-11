/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                           S E M A P H O R E                               */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* The class Semaphore implements the synchronization concept of the         */
/* counting semaphore.                                                       */
/*****************************************************************************/

#include "semaphore.h"
#include "syscall/guarded_organizer.h"

extern Guarded_Organizer guarded_organizer;

Semaphore::Semaphore(int c) {
    counter = c;
}

void Semaphore::p() {
    Customer *act = static_cast<Customer*>(guarded_organizer.active());   // Get the actual process;
    if(counter > 0) {
        counter -= 1;
    } else {
        guarded_organizer.block(*act, *this);
    }
}

void Semaphore::v() {
    Chain *chain = this->dequeue();                 //use a minus counter to varify if there is more than one customer are waitin

    if(chain) {
        guarded_organizer.wakeup(*static_cast<Customer*>(chain));
    } else {
        counter += 1;
    }
}

void Semaphore::wait() {
    p();
}

void Semaphore::signal() {
    v();
}