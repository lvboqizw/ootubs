/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                                 P A N I C                                 */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Default interrupt handler.                                                */
/*****************************************************************************/
/* Add your code here */ 
/* Add your code here */ 
#include "panic.h"



void Panic::trigger() {
    kout << "A Panic triggred" << endl;   
    cpu.halt();                           
}

bool Panic::prologue () {
    
    cpu.disable_int();
    
    kout << "kernel panic" << endl;
    
	cpu.halt();
	
	return false;
}
