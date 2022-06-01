/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                                 L O O P                                   */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Loop is a thread that does nothing else but count upwards and print this  */
/* on the screen. In between, it yields the CPU. The Scheduler then decides  */
/* which thread shall run next.                                              */
/*****************************************************************************/

#ifndef __loop_include__
#define __loop_include__

/* Add your code here */ 

#include "thread/entrant.h"

class Loop : public Entrant
{
private:
	Loop (const Loop &copy); // prevent copying
	int num = 0;

public:
/* Add your code here */ 
	Loop(void *tos) : Entrant(tos) {};

	void action ();

	void set_num(int i);
};
#endif
