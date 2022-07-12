#include "sounder.h"
#include "device/cgastr.h"

extern CGA_Stream kout;

void Sounder::action() {
    kout.clear();
    kout << "press 'q' to exit" << endl;
    while (1)
    {
        key = guarded_keyboard.getkey();

        if(key == 'a') {
            bee.frequence(A);
            bee.noise();
        }
        if(key == 'q') {
            process_sem.signal();
            guarded_organizer.exit();
        }
    }
    
    
}