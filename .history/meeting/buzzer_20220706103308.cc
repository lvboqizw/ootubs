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

extern Guarded_Organizer guarded_organizer;
/* Add your code here */ 
Buzzer::Buzzer(){
}

void Buzzer::set(int ms){
    this->Bell::wait(ms);
}

void Buzzer::sleep(){//放进waitingroom,直到铃响
    Customer *act = (Customer*)(guarded_organizer.active());
    this->enqueue(act);
        guarded_organizer.block(*act, *this);
}

void Buzzer::ring(){
    Customer *next =(Customer*) this->dequeue();
    while(next)
        guarded_organizer.wakeup(*next);

}