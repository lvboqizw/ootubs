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

#include "meeting/bell.h"
#include "meeting/waitingroom.h"
#include "syscall/thread.h"

class Buzzer : public Waitingroom, public Bell

{
private:
	Buzzer(const Buzzer &copy); // prevent copying

	//int timer;

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
