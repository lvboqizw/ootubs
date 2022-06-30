/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                           S E M A P H O R E                               */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* The class Semaphore implements the synchronization concept of the         */
/* counting semaphore.                                                       */
/*****************************************************************************/

#ifndef __Semaphore_include__
#define __Semaphore_include__


#include "waitingroom.h"

class Semaphore: public Waitingroom

{
private:
	Semaphore(const Semaphore &copy); // prevent copying

public:
	Semaphore(int c);

	/**
	 * @brief Wait operation: If the semaphore counter is 
	 * greater than zero, it is decremented by one only. 
	 * Otherwise, the currently running process (a Customer 
	 * object) is added to the waiting list and is blocked.
	 */
	void p();

	/**
	 * @brief Release operation: If there is at least one 
	 * customer on the waiting list, the first of them will 
	 * be woken up. Otherwise, the semaphore counter is 
	 * incremented by one.
	 */
	void v();

	///	Another name for the method p()
	void wait();

	/// Another name for the method v()
	void signal();
};

#endif
