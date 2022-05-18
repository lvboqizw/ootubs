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
#include "guard/guard.h"
#include "user/appl.h"

CGA_Screen scr;
CPU cpu;
Plugbox plugbox;
PIC pic;
Panic panic;
CGA_Stream kout;
Guard guard;
Application appl;

Keyboard keyboard;

int main()
{
	cpu.enable_int();
	kout<<"funktioniert!"<<endl;
	keyboard.plugin();
	appl.action();
	

	return 0;
}