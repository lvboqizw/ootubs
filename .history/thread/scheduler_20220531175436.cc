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


extern Guard guard;
extern CPU cpu;


Scheduler::Scheduler(const Scheduler &copy){}

void Scheduler::ready (Entrant &that){
    list.enqueue(&that);
}

void Scheduler::schedule(){
    // Hole nächstes
    Entrant *next = static_cast<Entrant*>(list.dequeue());

    if(!next) return;

    // dispatchen
    go(*next);
}

void Scheduler::exit(){
    Entrant *next = static_cast<Entrant *>((this -> list.dequeue()));

    if(next){
        this -> dispatch(*next);
    }
    
}

void Scheduler::kill(Entrant &that){
    // Einfach aus der Liste löschen... fertig
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