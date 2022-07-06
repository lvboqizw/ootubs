/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                          S C H E D U L E R                                */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Scheduler implementation.                                                 */
/*****************************************************************************/


#include "thread/scheduler.h"
#include "user/idle.h"
#include "guard/guard.h"
#include "device/cgastr.h"


extern Guard guard;
extern CPU cpu;
extern Idle idle;


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
        this->dispatch(idle);
    }
    
}

void Scheduler::kill(Entrant &that){
    // Einfach aus der Liste löschen... fertig
    Entrant *active = static_cast<Entrant *>(this->active());
    if(active == &that) exit();
    this -> list.remove(&that);
}

void Scheduler::resume(){
    if((Idle *)(this -> active()) != &idle){                    //if the running thread is not the idle, put the running thread back to ready list
        this -> list.enqueue((Entrant *)(this -> active()));
    }
    Entrant *next = (Entrant *)(this -> list.dequeue());

    if(next){
        this -> dispatch(*next);
    } else{
        this -> dispatch(idle);
    }
}