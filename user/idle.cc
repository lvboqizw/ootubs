#include "idle.h"

void Idle::action(){
    while (true){
        cpu.idle();
    }
}