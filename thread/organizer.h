/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                          O R G A N I Z E R                                */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* The Organizer is a special scheduler that additionally allows processes   */
/* (Customer objects) to wait for events (Waitingroom objects).              */
/*****************************************************************************/

#ifndef __organizer_include__
#define __organizer_include__

#include "scheduler.h"
#include "customer.h"
#include "meeting/waitingroom.h"

class Organizer : public Scheduler
{
private:
	Organizer(const Organizer &copy); // prevent copying
public:
	Organizer() {};
	
	/**
	 * @brief Blocks the running process and gives the processor to the next ready process.
	 * 
	 * @param customer The running process
	 * @param waitingroom 
	 */
	void block(Customer& customer, Waitingroom& waitingroom);

	/**
	 * @brief To wake up a sleeping process, i.e. put it back to the ready list.
	 * 
	 * @param customer 
	 */
	void wakeup(Customer& customer);

	/**
	 * @brief The method allows one process to kill another(that).
	 * 
	 * @param that 
	 */
	void kill(Customer& that);
};

#endif
