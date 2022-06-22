/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                          S C H E D U L E R                                */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Scheduler implementation.                                                 */
/*****************************************************************************/

#ifndef __schedule_include__
#define __schedule_include__

#include "thread/dispatch.h"
/* Add your code here */ 
#include "thread/entrant.h"
#include "thread/coroutine.h"
#include "object/queue.h"
#include "machine/cpu.h"

class Scheduler : public Dispatcher
/* Add your code here */ 
{
private:
	Scheduler (const Scheduler &copy); // prevent copying
/* Add your code here */ 
	Queue list;
public:
	Scheduler(){};

	// This method registers the process that with the scheduler. It is appended to the end of the ready list.
	void ready(Entrant &that);
	// This method starts up scheduling by removing the first process from the ready list and activating it.
	void schedule();
	// With this method a process can terminate itself.
	void exit();
	// With this method a process can terminate another one (that).
	void kill(Entrant &that);
	 /** This method allows to trigger a context switch without the calling
	  *  Entrant having to know which other Entrant objects exist in the system, 
	  * and which of these should be activated. 
	  * */
	void resume();
 
};

#endif
