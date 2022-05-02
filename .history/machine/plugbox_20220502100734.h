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

#ifndef __Plugbox_include__
#define __Plugbox_include__

#include "guard/gate.h"
#include "device/panic.h"

extern Panic panic;

class Plugbox {
private:
	Plugbox(const Plugbox &copy); // prevent copying
/* Add your code here */ 

	Gate* map[64];

public:
	int timer = 32;
	
	int keyboard = 33;

	Plugbox();

	void assign(unsigned int slot, Gate& gate);

	Gate& report(unsigned int slot);
};

#endif
