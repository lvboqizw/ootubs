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
    // //--------------------------------------------
    //     kout << "scheduler ready: " << &that << endl;

    list.enqueue(&that);
    // //--------------------------------------------
    //     kout << "ready list:(in ready) " << list.len() << endl;
}

void Scheduler::schedule(){
    Entrant *next = static_cast<Entrant*>(list.dequeue());
        // //--------------------------------------------
        // kout<<&next<<"has been dequeued"<<endl;
        // kout << "ready list/afer schedule:  " << list.len() << endl;
    if(next){
        go(*next);
    } else {
        // //----------------------------------------------9
        // kout<<"has nothing to schedule, went to idle : "<<&idle<<endl;
        this->dispatch(idle);
    }
}

void Scheduler::exit(){
    Entrant *next = static_cast<Entrant *>((this -> list.dequeue()));
    // //--------------------------------------------
    //     kout << " length of ready list/(in exit): " << list.len() << endl;

    if(next){
        // //-----------------------------
        // kout<<"exit write, went next thread : "<<&next<<endl;
        this -> dispatch(*next);
    } else {
        // //-----------------------------
        // kout<<"exit write ,went to idle : "<<&idle<<endl;
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
        // //--------------------------------------------
        // kout<<"the aktuell customer has been enqueued"<<endl;
        // kout << "length of ready list/(in resume): " << list.len() << endl;
    }
    Entrant *next = (Entrant *)(this -> list.dequeue());
    if(next){
    //     //--------------------------------------------
    //    kout << "resume to next thread: " << &next << endl;
        this -> dispatch(*next);
    } else{
       // kout<<"has nothint to resume, went to idle"<<&idle<<endl;
        this -> dispatch(idle);
    }
}