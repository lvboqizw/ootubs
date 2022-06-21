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
    Entrant *next = (Entrant*)list.dequeue();

    if(!next) return;

    // dispatchen
    go(*next);
}

void Scheduler::exit(){
    Entrant *next = (Entrant *)(this -> list.dequeue());

    if(next){
        this -> dispatch(*next);
    }
    
}

void Scheduler::kill(Entrant &that){
    // Einfach aus der Liste löschen... fertig
    this -> list.remove(&that);
}

void Scheduler::resume(){
    
    this -> list.enqueue((Entrant *)(this -> active()));
    Entrant *next = (Entrant *)(this -> list.dequeue());

    if(next){
       this -> dispatch(*next);
    }
}