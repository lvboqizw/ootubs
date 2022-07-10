/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              W A T C H                                    */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Handles timer interrupts by managing a time slice and triggering a        */
/* process switch if necessary.                                              */
/*****************************************************************************/

#include "device/watch.h"
#include "machine/plugbox.h"
#include "machine/pic.h"
#include "syscall/guarded_scheduler.h"
#include "meeting/bellringer.h"
//#include "syscall/guarded_organizer.h"

 
extern Plugbox plugbox;
extern PIC pic;
extern Guarded_Scheduler guarded_scheduler;
//extern Guarded_Organizer guarded_organizer;
extern Bellringer bellringer;


void Watch::windup() {
    plugbox.assign(plugbox.timer, *this);
    pic.allow(PIC::timer);   // allow the interrupts from timer
}

bool Watch::prologue(){
    return true;            
}

void Watch::epilogue(){
    bellringer.check();
    guarded_scheduler.Scheduler::resume();  //can't directly call the resume from guarded_scheduler: if simply call the resume from the guard, it will run the guard.enter() and guard.leave()
                                            // it will enter the guard twice and leave twice
}

