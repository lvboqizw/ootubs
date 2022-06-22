/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                                  P I T                                    */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Programmable Interval Timer.                                              */
/*****************************************************************************/

#ifndef __pit_include__
#define __pit_include__

#include "machine/io_port.h"

class PIT {
private:
	PIT(const PIT &copy); // prevent copying

	IO_Port crtl_register;
	IO_Port counter;

	int us;

public:
	PIT(int us) : crtl_register(0x43), counter(0x40) { // counter0, 1.PIT
		interval (us);
	}

	// Indicates which interrupt interval was set
	int interval() {
	return this->us;
	}

	// Set a new interupt interval
	void interval(int us);
};

#endif
