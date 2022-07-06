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
    if(!bell->run_down()) {
        return;
    }
    dequeue();                  // get the time outed bell out
    bell->ring();
}

void Bellringer::job(Bell* bell, int ticks) {
    if(!ticks) {
        return;
    }
    int sum = 0;
    Bell* old = (Bell*)first();
    sum = old->wait();
    if (sum > ticks) {          //if the ticks smaller than the first bell's time, insert at the beginning of the list
        insert_first(bell);
    }
    Bell* tmp = (Bell*) old->next;
    while(tmp) {
        if (tmp->wait() > ticks) {      //if the ticks from the bell next to the old is greater than given, 
                                        //insert the given one after the old bell and minus the ticks of the old
            ticks -= sum;
            bell->wait(ticks);
            insert_after(old, bell);
        }
        old = tmp;                      //if is smaller, set the next of old as old
        sum += old->wait();             //sum the ticks together
        tmp = (Bell*) old->next;        //set the tmp as the next one
    }
}

void Bellringer::cancel(Bell* bell) {
    remove(bell);
}

