/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                         A P P L I C A T I O N                             */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* The Application class defines the (only) application for OOStuBS.         */
/*****************************************************************************/

#ifndef __application_include__
#define __application_include__

#include "thread/entrant.h"
#include "syscall/thread.h"

class Application : public Thread
{
private:
	Application (const Application &copy); // prevent copying

public:

	Application(void *tos) : Thread(tos) {};

	void action ();
};

#endif
