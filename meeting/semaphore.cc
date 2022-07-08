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
    Customer *act = (Customer*)(guarded_organizer.active());   // Get the actual process;

    if(--counter < 0) {
        this->enqueue(act);
        guarded_organizer.block(*act, *this);
    }
}

void Semaphore::v() {
    Customer *next;
    //when more than one customer are waiting, then don't increase counter, direkt wakeup
    if(++ counter <= 0) {                                      //use a minus counter to varify if there is more than one customer are waiting
        next  =(Customer*) this->dequeue();
        if(next) {
            guarded_organizer.wakeup(*next);
        }
    }
}

void Semaphore::wait() {
    p();
}

void Semaphore::signal() {
    v();
}