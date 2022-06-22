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
 
extern Plugbox plugbox;
extern PIC pic;
extern Guarded_Scheduler guarded_scheduler;

void Watch::windup() {
    plugbox.assign(plugbox.timer, *this);
    pic.allow(PIC::timer);   // allow the interrupts from timer
}

bool Watch::prologue(){
    return true;            // ???????
}

void Watch::epilogue(){
    guarded_scheduler.Scheduler::resume();
}

