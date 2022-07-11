#include "user/write.h"

#include "syscall/guarded_organizer.h"
extern Guarded_Organizer guarded_organizer;


void Write::action() {
    // kout << "current aktiv thread is:"<<guarded_organizer.active() << endl;
    while(1){
        Key key =  guarded_keyboard.getkey();
        guarded_semaphore.wait();
        kout.setpos(5, 5);
        kout << key ;
        kout.flush();
        guarded_semaphore.signal();
    }
}