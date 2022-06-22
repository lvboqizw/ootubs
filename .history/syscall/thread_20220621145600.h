/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                             T H R E A D                                   */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Implements user interface of a thread.                                    */
/*****************************************************************************/

#ifndef __thread_include__
#define __thread_include__

<<<<<<< HEAD
/* Add your code here */ 
 
class Thread
/* Add your code here */ 
=======
#include "thread/entrant.h"
 
class Thread :: public Entrant

>>>>>>> b45b96f7f63bc21cda9c395bee0aa3af01f8c910
 
{
private:
	Thread(const Thread &copy); // prevent copying
<<<<<<< HEAD
/* Add your code here */ 
=======
public:
	Thread(void *tos):Entrant(tos){}
>>>>>>> b45b96f7f63bc21cda9c395bee0aa3af01f8c910
 
};

#endif
