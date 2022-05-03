/* Add your code here */ 

#include "machine/cgascr.h"
#include "machine/keyctrl.h"
#include "machine/key.h"
#include "machine/cpu.h"
#include "machine/plugbox.h"
#include "device/cgastr.h"
#include "device/panic.h"
#include "object/o_stream.h"
#include "user/appl.h"

//machine
CGA_Screen scr;

// Keyboard_Controller kc;
CPU cpu;
Plugbox plugbox;
//device
Panic panic;
//object
CGA_Stream kout;
//user
Application appl;


int main()
{
	kout<<"funktioniert!"<<endl;
	appl.action();
	// plugbox.report(300).trigger();

	return 0;
}