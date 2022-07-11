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


#include "thread/entrant.h"
#include "syscall/thread.h"

class Loop : public Thread
{
private:
	Loop (const Loop &copy); // prevent copying
	int num = 0;

public:
	Loop(void *tos) : Thread(tos) {};

	void action ();

	void set_num(int i);
};
#endif
