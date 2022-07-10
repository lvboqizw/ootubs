#ifndef __idle_include__
#define __idle_include__

#include "syscall/thread.h"
#include "machine/cpu.h"

#include "device/cgastr.h"

extern CPU cpu;
extern CGA_Stream kout;


class Idle : public Thread{

private:
    Idle(const Idle &copy); // Verhindere Kopieren

public:
    Idle(void *tos) : Thread(tos){}

    inline void action(){
        kout << "idle" << endl;
		while(1){

			cpu.idle();
			// kout << "idle" << endl;
			kout.flush();
		}
    }
};

#endif