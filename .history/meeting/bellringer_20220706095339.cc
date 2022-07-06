/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                          B E L L R I N G E R                              */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* The "bell ringer" (Bellringer) is activated periodically and checks if    */
/* any "bells" (Bell objects) need to ring. The bells are in a list that the */
/* bellringer manages.                                                       */
/*****************************************************************************/

#include "bellringer.h"

void Bellringer::check() {//遍历BELL列表,查看是否到期，然后每个都调用tick
    Bell* bell;
    bell = (Bell*)first();
    if(!bell) return;
    if(bell->run_down()) {
        //dequeue();                  // get the time outed bell out
        bell->ring();
    }
}

void Bellringer::job(Bell* bell, int ticks) {
    bell->wait(ticks);
    // while(!bell->run_down())
    //     bell->tick();
    
    // remove(bell);
    // bell->ring();
}

void Bellringer::cancel(Bell* bell) {
    remove(bell);
}

