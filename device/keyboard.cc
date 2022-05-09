/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                            K E Y B O A R D                                */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Keyboard driver.                                                          */
/*****************************************************************************/

/* Add your code here */ 
/* INCLUDE */
#include "device/keyboard.h"
#include "machine/plugbox.h"
#include "device/cgastr.h"
#include "machine/pic.h"
#include "guard/gate.h"

/* Functions */
extern CGA_Stream kout;
extern PIC pic;
extern Plugbox plugbox;


void Keyboard::plugin (){
	//Keyboard in der Plugbox anmelden
	plugbox.assign(Plugbox::keyboard, *this);
		//interrupts für tastatur erlauben
	pic.allow(PIC::keyboard);
}

void Keyboard::trigger(){
	Key key = key_hit();
	if(key.valid()){
		//ctrl + alt + del
		if(key.ctrl() && key.alt() && key.scancode()== 53){
			reboot();
		}else{
			//tastendruck
			unsigned short x,y;
			kout.getpos(x,y);
			kout.setpos(10,10);
			kout << (char)key.ascii();
			kout.flush();
			kout.setpos(x,y);
		}
	}
}
/* Add your code here */ 
 
