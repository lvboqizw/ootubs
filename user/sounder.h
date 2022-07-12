#ifndef __sounder_include__
#define __sounder_include__

#include "device/bee.h"
#include "syscall/thread.h"
#include "syscall/guarded_buzzer.h"
#include "syscall/guarded_keyboard.h"
#include "syscall/guarded_semaphore.h"
#include "syscall/guarded_organizer.h"

extern Guarded_Keyboard guarded_keyboard;
extern Guarded_Semaphore process_sem;
extern Guarded_Organizer guarded_organizer;

class Sounder: public Thread 
{
private:
    Sounder (const Sounder &copy); 
    Bee bee;
    Key key;
    Guarded_Buzzer buzzer;

    enum piano {
        A = 440, //000,
        B_ = 466, //164,
        B = 493, //833,
        C = 261, //626,
        C_ = 277, //183,
        D = 293, //665,
        Eb = 311, //127,
        E = 329, //629,
        F = 349, //228,
        F_ = 369, //994,
        G = 391, //995,
        G_ = 415, //305,
    };

public:
    Sounder(void *tos) : Thread(tos) {};

    void action();
};

#endif