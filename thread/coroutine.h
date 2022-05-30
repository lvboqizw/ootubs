/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                          C O R O U T I N E                                */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Represents the abstraction of a coroutine.                                */
/* In the constructor, we set up the initial context of the coroutine. go()  */
/* activates the first coroutine. All further coroutine switches should be   */
/* initiated by resume().                                                    */
/* To be able to save the context at a couroutine switch, every Coroutine    */
/* object contains a struct toc that stores the values of all non-volatile   */
/* registers.                                                                */
/*****************************************************************************/

#ifndef __Coroutine_include__
#define __Coroutine_include__

#include "machine/toc.h"

class Coroutine {
private:
	Coroutine(const Coroutine &copy); // prevent copying

public:
	toc toc1;

	/** Initializ the register values, make the stack pointer pointe to tos
	 * and first activation execution begins with the kickoff function
	*/
	Coroutine (void* tos);

	/**For the first activation of the first coroutine in the system*/
	void go ();

	/** Trigger a coroutine switch*/
	void resume (Coroutine& next);

	/**The method action represents the actual job of the coroutine*/
	virtual void action () = 0;
};

#endif
