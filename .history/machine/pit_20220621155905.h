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

<<<<<<< HEAD
class PIT {
private:
	PIT(const PIT &copy); // prevent copying
/* Add your code here */ 
public:
	PIT(int us) {
		interval (us);
	}
	int interval() {
/* Add your code here */ 
	}
=======
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
>>>>>>> b45b96f7f63bc21cda9c395bee0aa3af01f8c910
	void interval(int us);
};

#endif
