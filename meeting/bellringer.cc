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
   
    Bell* temp = (Bell*) first();
	Bell* del;	
	while(temp){
		temp->tick();
		if(temp->run_down()){		
			temp->ring();
			del = temp;
			temp = (Bell*)temp->next;
			remove(del);
		}else{
			temp = (Bell*)temp->next;
		}
	}
}

void Bellringer::job(Bell* bell, int ticks) {
    bell->wait(ticks);
	enqueue(bell);
}

void Bellringer::cancel(Bell* bell) {
    remove(bell);
}

