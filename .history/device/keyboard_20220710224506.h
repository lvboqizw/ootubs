/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                            K E Y B O A R D                                */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Keyboard driver.                                                          */
/*****************************************************************************/

#ifndef __Keyboard_include__
#define __Keyboard_include__

#include "guard/gate.h"
#include "machine/keyctrl.h"
#include "machine/key.h"
#include "meeting/semaphore.h"
#include "syscall/guarded_semaphore.h"
 
class Keyboard : public Gate, public Keyboard_Controller
/* Add your code here */ 
//:public Gate, public Keyboard_Controller
{
private:
	Keyboard(const Keyboard &copy); // prevent copying
/* Add your code here */ 
    Key buffer[1024];
	unsigned int length;
	Key key;
	Key last_key;
	char data;
	//Semaphore keySemaphore;

	bool tooken = true;
	Guarded_Semaphore semaphore;

public:
/* Add your code here */ 
 
    Keyboard():semaphore(0){};
	// PLUGIN: "Plugs in" the keyboard (driver). From now on, keypresses are handled.
	void plugin();

// void trigger() override;		

	bool prologue();

	void epilogue();

	Key getkey();

};

#endif
