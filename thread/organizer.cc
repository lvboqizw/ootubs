/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                          O R G A N I Z E R                                */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* The Organizer is a special scheduler that additionally allows processes   */
/* (Customer objects) to wait for events (Waitingroom objects).              */
/*****************************************************************************/

#include "organizer.h"
#include "machine/cgascr.h"

extern CGA_Stream kout;

void Organizer::block(Customer& customer, Waitingroom& waitingroom) {
    waitingroom.enqueue(&customer);         //put the customer in the waitingroom
    customer.waiting_in(&waitingroom);      //setup the waitingroom information of the customer

    kout<<"in block" << endl;
    if (&customer == active()) {             //if the customer now is running
        exit();                             //exit() performs a coroutine swicth from old to the new life pointer
    } else {
        kill(customer);                     //terminate the given customer
    }
}

void Organizer::wakeup(Customer& customer) {
    Waitingroom* w = customer.waiting_in();
    if(w) {
        w->remove(&customer);
    }
    customer.waiting_in(0);
    Scheduler::ready(customer);
}

void Organizer::kill(Customer& that) {
    Waitingroom* w = that.waiting_in();
    if(w) {
        w->remove(&that);
    } else {
        if(&that == active()) {
            exit();
        } else {
            Scheduler::kill(that);
        }
    }
}
