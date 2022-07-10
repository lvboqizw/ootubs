/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              P L U G B O X                                */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Abstracts an interrupt vector table. Allows to configure handler routines */
/* for every hardware and software interrupt and every CPU exception.        */
/*****************************************************************************/

/* Add your code here */ 
#include "machine/plugbox.h"


Plugbox::Plugbox() {                                        
    for(int i = 0; i < 64; ++ i) {
        assign(i, panic);
    }
}

void Plugbox::assign(unsigned int slot, Gate& gate) {       // check the slot, if the slot is in the range of the capacity
    if(slot < 64) {
        map[slot] = &gate;
    } else {
        panic.trigger();
    }
}

Gate& Plugbox::report(unsigned int slot) {                  
    if(slot < 64) {
        return *(map[slot]);
    } else {
        return panic;
    }
}