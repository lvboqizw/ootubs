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
#include "syscall/guarded_organizer.h"
#include "meeting/bellringer.h"

extern Bellringer bellringer;
extern Guarded_Organizer guarded_organizer;


void Buzzer::set(int ms){
    this->Bell::wait(ms);
}

Buzzer::~Buzzer(){
    bellringer.cancel(this);//don't need to ring
	Customer* customer = (Customer*)Queue::dequeue();//wake up all customers
	while(customer){	
		guarded_organizer.wakeup(*customer);
		customer = (Customer*)Queue::dequeue();
	}
}

void Buzzer::sleep(){//put in the waitingroom untill the bell ring 
    if(this->wait()>0){//if counter is 0,then direkt ring,
        Customer *act = (Customer*)(guarded_organizer.active());
        this->enqueue(act);
            guarded_organizer.block(*act, *this);
    }
}

void Buzzer::ring(){
    Customer *next =(Customer*) this->dequeue();
    while(next)
        guarded_organizer.wakeup(*next);

}