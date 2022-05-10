/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                                 P A N I C                                 */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Default interrupt handler.                                                */
/*****************************************************************************/

#ifndef __panic_include__
#define __panic_include__

/* INCLUDES */

#include "guard/gate.h"
#include "machine/cpu.h"
#include "device/cgastr.h"

class Panic : public Gate
/* Add your code here */ 
{
private:
	CPU cpu;
	CGA_Stream kout;                   

	Panic (const Panic &copy); // prevent copying
public:
	Panic () {}
/* Add your code here */ 
	void trigger ();

	bool prologue();
};

#endif
