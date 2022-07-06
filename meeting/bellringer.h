/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                          B E L L R I N G E R                              */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* The "bell ringer" (Bellringer) is activated periodically and checks if    */
/* any "bells" (Bell objects) need to ring. The bells are in a list that the */
/* bellringer manages.                                                       */
/*****************************************************************************/

#ifndef __Bellringer_include__
#define __Bellringer_include__

#include "bell.h"
#include "object/list.h"

class Bellringer: public List
/* Add your code here */ 
{
private:
	Bellringer(const Bellringer &copy); // prevent copying

public:
	Bellringer() {};

	/// Checks whether bells are to be rung and does so if necessary
	void check();

	/// The bell is given to the bell ringer. It should be rung after ticks time units
	void job (Bell* bell, int ticks);

	/// The bell should not be rung after all
	void cancel (Bell* bell);
};

#endif
