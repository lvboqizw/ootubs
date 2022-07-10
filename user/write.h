#ifndef __write_include__
#define __write_include__

#include "syscall/guarded_keyboard.h"
#include "syscall/guarded_semaphore.h"
#include "machine/key.h"
#include "syscall/thread.h"

extern Guarded_Keyboard guarded_keyboard;
extern Guarded_Semaphore guarded_semaphore;

class Write : public Thread{
private:
    Write(const Write &copy);

public:
    Write(void *tos) : Thread(tos){}

    void action();
};

#endif