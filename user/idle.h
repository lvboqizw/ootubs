#ifndef __idle_include__
#define __idle_include__

#include "syscall/thread.h"
#include "machine/cpu.h"

#include "device/cgastr.h"

extern CPU cpu;


class Idle : public Thread{

private:
    Idle(const Idle &copy); // Verhindere Kopieren

public:
    Idle(void *tos) : Thread(tos){}

    inline void action(){

		while(1){
			cpu.idle();
		}
    }
};

#endif