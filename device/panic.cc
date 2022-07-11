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
#include "machine/cpu.h"
#include "device/cgastr.h"

extern CPU cpu;
extern CGA_Stream kout;

void Panic::trigger() {
    kout << "A Panic triggred" << endl;   
    cpu.halt();                           
}

bool Panic::prologue () {
	return false;
}

void Panic::epilogue () {
    cpu.disable_int();
    
    kout << "kernel panic" << endl;
    
	cpu.halt();
}
