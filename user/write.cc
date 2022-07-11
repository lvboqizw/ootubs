#include "user/write.h"

void Write::action() {
    while(1){
        Key key =  guarded_keyboard.getkey();
        kout_semaphore.wait();
        kout << key.ascii();
        kout.flush();
        kout_semaphore.signal();
    }
}