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
#include "machine/cpu.h"
#include "guard/gate.h"

/* Functions */
extern CGA_Stream kout;
extern PIC pic;
extern Plugbox plugbox;
extern CPU cpu;


void Keyboard::plugin (){
	//Keyboard in der Plugbox anmelden
	plugbox.assign(Plugbox::keyboard, *this);
	//interrupts für tastatur erlauben
	pic.allow(PIC::keyboard);
}

void Keyboard::trigger(){
	kout.setpos(0,0);
	kout<<"V";
	kout.flush();
	Key key = key_hit();
	if(key.valid()){
		//ctrl + alt + del
		if(key.ctrl() && key.alt() && key.scancode()== 0x53){
			reboot();
		}else{
			//tastendruck
			unsigned short x,y;
			kout.getpos(x,y);
			kout.setpos(5,5);
			kout <<(char) key.ascii();
			kout.flush();
			kout.setpos(x,y);
		}
	}
}

bool Keyboard::prologue ()
{
	// cpu.disable_int();
	Key key = this->key_hit();
	// char data;
	// //for debug
	// kout.setpos(5,5);
	// kout<<"b";
	// kout.flush();
	// //

	if(key.valid()){
		//CTRL + ALT + DEL abfragen
		if((key.ctrl()==true) && (key.alt()==true) && (key.scancode()==0x53))
		{	
			this->epilogue();
			this->reboot();
		}else{
			// if(length != 1023)//buffer is not full
			// 	buffer[length++] = key;
			this->data = (char)key.ascii();
			return key.valid();

		}

	}
	return key.valid();
}
    

void Keyboard::epilogue ()
{
	kout.setpos(5,5);
	// while(length > 0)
	// 	kout<<(char)buffer[--length].ascii();
	kout<<this->data;
	kout.flush();	
}
/* Add your code here */ 
 
