/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                          S C H E D U L E R                                */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Scheduler implementation.                                                 */
/*****************************************************************************/

/* Add your code here */ 
 
/* Add your code here */ 
/* Add your code here */ 
#include "thread/scheduler.h"
#include "guard/guard.h"
#include "device/cgastr.h"


extern Guard guard;
extern CPU cpu;


Scheduler::Scheduler(const Scheduler &copy){}

void Scheduler::ready (Entrant &that){
    list.enqueue(&that);
}

void Scheduler::schedule(){
    Entrant *next = static_cast<Entrant*>(list.dequeue());
    if(next){
        go(*next);
    }
}

void Scheduler::exit(){
    Entrant *next = static_cast<Entrant *>((this -> list.dequeue()));

    if(next){
        this -> dispatch(*next);
    } else {
        cpu.idle();
    }
    
}

void Scheduler::kill(Entrant &that){
    // Einfach aus der Liste löschen... fertig
    Entrant *active = static_cast<Entrant *>(this->active());
    if(active == &that)exit();
    this -> list.remove(&that);
}

void Scheduler::resume(){
    
    Entrant *active = static_cast<Entrant *>(this->active());
    this -> list.enqueue(active);
    Entrant *next = static_cast<Entrant *>((this -> list.dequeue()));

    if(next){
        this -> dispatch(*next);
    }
}