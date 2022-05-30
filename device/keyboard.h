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

#include "machine/keyctrl.h"
#include "guard/gate.h"
#include "machine/key.h"
 
class Keyboard : public Gate, public Keyboard_Controller
/* Add your code here */ 
//:public Gate, public Keyboard_Controller
{
private:
	Keyboard(const Keyboard &copy); // prevent copying
/* Add your code here */ 
    Key buffer[1024];
	unsigned int length;
	char data;
	Key key;
	char data;
public:
/* Add your code here */ 
 
    Keyboard(){}
	// PLUGIN: "Plugs in" the keyboard (driver). From now on, keypresses are handled.
	void plugin();

	void trigger() override;

	bool prologue();

	void epilogue();

/* Add your code here */ 

};

#endif
