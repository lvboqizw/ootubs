/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                                G U A R D                                  */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Using this class, we can synchronize activities with a critical section   */
/* with interrupt handlers that also access this critical section. This      */
/* synchronization takes place along the prologue/epilogue model.            */
/*****************************************************************************/

#ifndef __Guard_include__
#define __Guard_include__
#include "guard/locker.h"
#include "guard/gate.h"
#include "object/queue.h"

/* Add your code here */ 

class Guard : public Locker {
private:
	Guard (const Guard &copy); // prevent copying

	Queue epiQ; //The queue to save the accumulated epilogues
public:
	Guard () {}
/* Add your code here */ 
	//Regular control flow leaves the critical section. another accumulated epilohies can be processed
	void leave();

	/* Is called by guardian() if the prviously executed prologue has indicated by a return value of true
	*  that its epilogue should be executed. Depends on whether the critical section is free or occupied, 
	*  the epilogue will be handled or added to the queue.
	*/
	void relay(Gate* item);
};

#endif
