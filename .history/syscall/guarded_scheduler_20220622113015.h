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

#include "thread/scheduler.h"
#include "syscall/thread.h"
#include "guard/secure.h"

class Guarded_Scheduler::Public Scheduler
/* Add your code here */ 
{
private:
	Guarded_Scheduler(const Guarded_Scheduler &copy); // prevent copying
public:
	Guarded_Scheduler () {}

	// Registers the process 'that' with the scheduler
	void ready(Thread& that);

	// A process call this method to terminate itself
	void exit();

	// A prcess call this method to terminate another process 'that'
	void kill(Thread& that);

	// Used to trigger a process switch
	void resume();
};

#endif
