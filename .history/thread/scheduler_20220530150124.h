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
	Scheduler(){}

	void ready(Entrant &that);
	void schedule();
	void exit();
	void kill(Entrant &that);
	void resume();
 
};

#endif
