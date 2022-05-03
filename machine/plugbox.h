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



class Plugbox {
private:
	Plugbox(const Plugbox &copy); // prevent copying
/* Add your code here */ 

	Gate* map[256];

	Panic panic;

public:
	enum {
		timer = 32,
		keyboard = 33,
	};

	Plugbox();

	void assign(unsigned int slot, Gate& gate);

	Gate& report(unsigned int slot);
};

#endif
