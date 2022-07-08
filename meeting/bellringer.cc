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
#include "device/cgastr.h"

extern CGA_Stream kout;

void Bellringer::check() {//遍历BELL列表,查看是否到期，然后每个都调用tick
    Bell* bell;
    bell = (Bell*)first();
    if(!bell) return;
    if(!bell->run_down()) {
        bell->tick();
        return;
    }
    bell = (Bell*)dequeue();                  // get the time outed bell out
    // //--------------------------------------------------------
    // kout << "run_down";
    // kout.flush();
    // //---------------------------------------------------------
    bell->ring();
}

void Bellringer::job(Bell* bell, int ticks) {
    if(!ticks) {
        return;
    }
    int sum = 0;
    Bell* now = (Bell*)first();
    if(!now) {                             //if there is no bell yet
        bell->wait(ticks);                 //put the bell at the first of the list
        this->enqueue(bell);
        return;
    }

    sum = now->wait();
    while(sum < ticks) {                    //if the ticks bigger than the old one's
        Bell* next = (Bell*)now->next;      //the bell which in the list and after 'now' one
        if(next) {
            int next_tk = next->wait();     //get the ticks num from the next bell
            if(ticks < next_tk) {           //if the next bell takes more time to ring
                bell->wait(ticks - sum);    //set the time for the new added one
                insert_after(now, bell);    //add the new one after the 'now' bell
                now = next;                 //move the pointer to the 'next' bell, right now 'now' point to the bell after new one
                while (now){          
                    int tmp = now->wait();
                    now->wait(tmp - ticks); //decrease the tick number after new added bell
                    now = (Bell*)now->next;
                }
                return;                     //finish the situation (sum < ticks, next exist and ticks < next_ticks) 
            } else {                        //situation (sum < ticks, next exist and ticks >= next_ticks)
                sum += next_tk;             //add the next_ticks to the sum
                now = next;                 //point to the next bell as'now'
            }
        } else {
            bell->wait(ticks - sum);    
            insert_after(now, bell);
            return;                         //finish the situation (sum < ticks and next do not exist)
        }
    }
    bell->wait(ticks);                 //if the sum, which is the ticks of the first bell, bigger than ticks
    this->enqueue(bell);
}

void Bellringer::cancel(Bell* bell) {
    remove(bell);
}

