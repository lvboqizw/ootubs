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
extern CGA_Stream kout;


Scheduler::Scheduler(const Scheduler &copy){}

void Scheduler::ready (Entrant &that){
    //--------------------------------------------
        kout << "scheduler ready: " << &that << endl;

    list.enqueue(&that);
    //--------------------------------------------
        kout << "ready list: " << list.len() << endl;
}

void Scheduler::schedule(){
    Entrant *next = static_cast<Entrant*>(list.dequeue());
        //--------------------------------------------
        kout << "ready list/schedule: " << list.len() << endl;
    if(next){
        go(*next);
    } else {
        this->dispatch(idle);
    }
}

void Scheduler::exit(){
    Entrant *next = static_cast<Entrant *>((this -> list.dequeue()));
    //--------------------------------------------
        kout << "ready list/exit: " << list.len() << endl;

    if(next){
        //-----------------------------
        kout<<"exit write, has next"<<&next<<endl;
        this -> dispatch(*next);
    } else {
        //-----------------------------
        kout<<"exit write ,has idle"<<&idle<<endl;
        this -> dispatch(idle);
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
        //--------------------------------------------
        kout << "ready list/resume en: " << list.len() << endl;
    }
    Entrant *next = (Entrant *)(this -> list.dequeue());
    if(next){
        //--------------------------------------------
        kout << "scheduler resume: " << &next << endl;
        this -> dispatch(*next);
    } else{
        this -> dispatch(idle);
    }
}