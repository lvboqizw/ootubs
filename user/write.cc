#include "user/write.h"

#include "syscall/guarded_organizer.h"
extern Guarded_Organizer guarded_organizer;


void Write::action() {
    while(1){
        Key key =  guarded_keyboard.getkey();
        guarded_semaphore.wait();
        kout << key;
        kout.flush();
        guarded_semaphore.signal();
    }
}