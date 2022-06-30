/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                         C U S T O M E R                                   */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* The Customer class extends the Entrant class with the ability to record   */
/* and retrieve an event that the process in question is waiting for.        */
/*****************************************************************************/

#ifndef __customer_include__
#define __customer_include__

/* Add your code here */ 
#include "entrant.h"
#include "meeting/waitingroom.h"

class Customer : public Entrant
/* Add your code here */ 
{
private:
	Customer (const Customer &copy); // prevent copying

public:
	/// The constructor passes the tos parameter to the constructor of the base class Entrant.
	Customer(void* tos): Entrant(tos){};

	/// This method is used to note in the Customer that it is currently waiting for an event in the Waitingroom w.
	void waiting_in (Waitingroom *w);

	/** This can be used to determine in which Waitingroom object the customer is registered.
	 * 0 means the process is not waiting for any event
	*/
	Waitingroom waiting_in();
};

#endif
