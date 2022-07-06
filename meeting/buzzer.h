/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                               B U Z Z E R                                 */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* An "alarm clock" is a synchronization object that allows one or more      */
/* threads to put themselves to sleep for a specified time.                  */
/*****************************************************************************/

#ifndef __Buzzer_include__
#define __Buzzer_include__

/* Add your code here */ 
#include "meeting/bell.h"
#include "meeting/waitingroom.h"

class Buzzer : public Waitingroom, public Bell
/* Add your code here */ 
{
private:
	Buzzer(const Buzzer &copy); // prevent copying
/* Add your code here */ 

public:
	Buzzer(){}

	virtual ~Buzzer();

	/// Called by the Bellringer when the waiting time has expired. Wakes up sleeping threads if necessary.
	virtual void ring();

	/// Setting the alarm clock.
	void set(int ms);

	/// Sleep until the alarm clock rings.
	void sleep();

};

#endif
