/* Add your code here */ 

#include "machine/cgascr.h"
#include "machine/keyctrl.h"
#include "machine/key.h"
#include "machine/cpu.h"
#include "machine/plugbox.h"
#include "machine/pic.h"
#include "device/cgastr.h"
#include "device/keyboard.h"
#include "device/panic.h"
#include "object/o_stream.h"
#include "user/appl.h"

//machine
CGA_Screen scr;
CPU cpu;
Plugbox plugbox;
PIC pic;
//device
Panic panic;
// Keyboard keyboard;
//object
CGA_Stream kout;
//user
Application appl;


int main()
{
	kout<<"funktioniert!"<<endl;
	// keyboard.plugin();
	appl.action();
	

	return 0;
}