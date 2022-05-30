/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                                G U A R D                                  */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Using this class, we can synchronize activities with a critical section   */
/* with interrupt handlers that also access this critical section. This      */
/* synchronization takes place along the prologue/epilogue model.            */
/*****************************************************************************/

/* Add your code here */ 
#include "guard/guard.h"
#include "machine/cpu.h"
#include "device/cgastr.h"
#include "guard/secure.h"

extern CPU cpu;
extern CGA_Stream kout;

void Guard::leave() {
    while (true) {
        cpu.disable_int();
        Gate* current = (Gate*)(epiQ.dequeue());  //get a gate which at the first position of queue
        if (!current)                       //if current is null
            break;
        current->queued(false);
        cpu.enable_int();
        current->epilogue();                //run the epilogue part of the interrupt
    }
    retne();                            // set up that the critical section is left
    cpu.enable_int();
}

void Guard::relay(Gate* item) {
    if(avail()){                            //check whether the critical section is free
        Secure secure;                           //set up that the critical section is entered
        cpu.enable_int();
        item-> epilogue();

    } else {                                //if the critical section is not free
        if(!item->queued()) {                //check whether the gate is already been queued
            item->queued(true);             //set the flag as ture: the gate is queued
            epiQ.enqueue(item);
            //cpu.enable_int();             //will be done auto
        }
    }
}
