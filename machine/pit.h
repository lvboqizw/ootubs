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

class PIT {
private:
	PIT(const PIT &copy); // prevent copying

	int us;

public:
	PIT(int us) {
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
