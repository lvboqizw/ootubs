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

void Bellringer::check() {
    Bell* bell;
    bell = (Bell*)first();
    if(!bell) return;
    if(bell->run_down()) {
        dequeue();                  // get the time outed bell out
        bell->ring();
    }
}

void Bellringer::job(Bell* bell, int ticks) {
    
}

void Bellringer::cancel(Bell* bell) {
    this->dequeue(bell);
}