/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                   G U A R D E D _ S C H E D U L E R                       */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Implements the system-call interface to the Scheduler.                    */
/*****************************************************************************/

#ifndef __guarded_scheduler_include__
#define __guarded_scheduler_include__

<<<<<<< HEAD
/* Add your code here */ 
=======
#include "thread/scheduler.h"
#include "syscall/thread.h"
#include "guard/secure.h"
>>>>>>> b45b96f7f63bc21cda9c395bee0aa3af01f8c910

class Guarded_Scheduler
/* Add your code here */ 
{
private:
	Guarded_Scheduler(const Guarded_Scheduler &copy); // prevent copying
public:
	Guarded_Scheduler () {}
<<<<<<< HEAD
/* Add your code here */ 
=======

	// Registers the process 'that' with the scheduler
	void ready(Thread& that);

	// A process call this method to terminate itself
	void exit();

	// A prcess call this method to terminate another process 'that'
	void kill(Thread& that);

	// Used to trigger a process switch
	void resume();
>>>>>>> b45b96f7f63bc21cda9c395bee0aa3af01f8c910
};

#endif
