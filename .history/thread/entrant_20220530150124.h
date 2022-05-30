/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                            E N T R A N T                                  */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* A coroutine that is managed by the Scheduler.                             */
/*****************************************************************************/

#ifndef __entrant_include__
#define __entrant_include__

/* Add your code here */ 
#include"thread/coroutine.h"
#include"object/chain.h"
#include"device/cgastr.h"

class Entrant : public Coroutine, public Chain
/* Add your code here */ 
{
private:
	Entrant(const Entrant &copy); // prevent copying
/* Add your code here */ 
public:
	Entrant(void *tos):Coroutine(tos){}
};

#endif
