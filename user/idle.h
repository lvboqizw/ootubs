#ifndef __idle_include__
#define __idle_include__

#include "syscall/thread.h"
#include "machine/cpu.h"

extern CPU cpu;


class Idle : public Thread{

private:
    Idle(const Idle &copy); // Verhindere Kopieren

public:
    Idle(void *tos) : Thread(tos){

    }

    void action();
};

#endif