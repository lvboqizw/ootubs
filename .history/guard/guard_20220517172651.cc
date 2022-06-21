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

extern CPU cpu;
extern CGA_Stream kout;

Gate* Guard::remove_epilogue() {
    cpu.disable_int();
    Chain* head = epiQ.dequeue();           //get the at the first position qpilogue in the queue
    Gate* g = static_cast<Gate*>(head);     //transform the type from chain to the gate
    cpu.enable_int();
    return g;
}

void Guard::leave() {
        Gate* current = remove_epilogue();
        while(current) {                    //if geted current gate is not NULL
            current-> queued(false);        //set the flag as false: the gate is now moved out of the queue
            cpu.enable_int();  
            current-> epilogue();           //run the epilogue part of the interrupt
            cpu.disable_int();
            current = remove_epilogue();    //get next gate from the queue
        }

        retne();                            // set up that the critical section is left
}

void Guard::relay(Gate* item) {
    if(avail()){                            //check whether the critical section is free
        enter();                            //set up that the critical section is entered
        cpu.enable_int();
        item-> epilogue();
        leave();
    } else {                                //if the critical section is not free
        if(!item->queued()) {                //check whether the gate is already been queued
            cpu.disable_int();
            item->queued(true);             //set the flag as ture: the gate is queued
            epiQ.enqueue(item);
            cpu.enable_int();
        }
    }
}
