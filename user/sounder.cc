#include "sounder.h"
#include "device/cgastr.h"

extern CGA_Stream kout;

void Sounder::action() {
    kout.clear();
    buzzer.set(200);
    kout << "play with lower case keybord: " << endl;
    kout << "a-Do w-Do# s-Re d-Mi e-Mib f-Fa t-Fa# h-So u-So# j-La i-La# k-Si" << endl;
    kout << "press 'q' to exit" << endl;
    while (1)
    {   
        buzzer.set(200);
        key = guarded_keyboard.getkey();
        switch (key)
        {
        case 'a':
            {
            bee.frequence(C);
            bee.noise();
            }
            break;
        case 'w':
            {
                bee.frequence(C_);
                bee.noise();
            }
            break;
        case 's':
            {
                bee.frequence(D);
                bee.noise();
            }
            break;
        case 'd':
            {
                bee.frequence(E);
                bee.noise();
            }
            break;
        case 'e': 
            {
                bee.frequence(Eb);
                bee.noise();
            }
            break;
        case 'f': 
            {
                bee.frequence(F);
                bee.noise();
            }
            break;
        case 't': 
            {
                bee.frequence(F_);
                bee.noise();
            }
            break;
        case 'h': 
            {
                bee.frequence(G);
                bee.noise();
            }
            break;
        case 'j': 
            {
                bee.frequence(A);
                bee.noise();
            }
            break;
        case 'i': 
            {
                bee.frequence(B_);
                bee.noise();
            }
            break;
        case 'k': 
            {
                bee.frequence(B);
                bee.noise();
            }
            break;
        case 'u': 
            {
                bee.frequence(G_);
                bee.noise();
            }
            break;
        case 'q': 
            {
                process_sem.signal();
                guarded_organizer.exit();
            }
            break;
        default:
            bee.stop();
            break;
        }
        
        key.ascii(0);
        buzzer.sleep();
        bee.stop();
    }
    
    
}