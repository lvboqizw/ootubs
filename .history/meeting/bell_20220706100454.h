/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                                 B E L L                                   */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Bell is an abstract base class that allows the time-controlled triggering */
/* of an activity. For this purpose, it has an internal counter that is      */
/* managed by the Bellringer.                                                */
/*****************************************************************************/

#ifndef __Bell_include__
#define __Bell_include__

#include "object/chain.h"

class Bell: public Chain
/* Add your code here */ 
{
private:
	Bell(const Bell &copy); // prevent copying

	int counter = 0;
public:
	Bell() {}

	/// Set the counter
	inline void wait(int value) {
		counter = value;
	};

	/// Get the counter
	inline int wait() {return counter;};

	/// Decrements the counter
	void tick(){counter -= 1;};

	/// Returns true, when the time has expired
	bool run_down() {
		if(counter <= 0)
			return true;
		return false;};

	/// Called by the bell ringer when it is the right time
	virtual void ring() = 0;
};

#endif
