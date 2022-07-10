/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                        W A I T I N G R O O M                              */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Implements a list of processes (Customer objects) that are all waiting    */
/* for a specific event.                                                     */
/*****************************************************************************/

#include "waitingroom.h"
#include "syscall/guarded_organizer.h"

extern Guarded_Organizer guarded_organizer;

Waitingroom::~Waitingroom (){
	Customer* temp = (Customer*)(Queue::dequeue());
	while(temp){
		temp = (Customer*)(Queue::dequeue());
		guarded_organizer.Organizer::wakeup(*temp);
	}
}

void Waitingroom::remove(Customer* customer) {
    if(!customer) return;
    this->Queue::remove(customer);
}

