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

	Gate* map[64];

public:
	enum {
		timer = 32,
		keyboard = 33,
	};

	Plugbox();

	// Plug in a handler routine at the interrupt number slot, provided in the form of a Gate object.
	void assign(unsigned int slot, Gate& gate);

	// Retrieve the Gate object for the specified slot.
	Gate& report(unsigned int slot);
};

#endif
