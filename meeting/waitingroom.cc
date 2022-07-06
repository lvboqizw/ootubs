/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                        W A I T I N G R O O M                              */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Implements a list of processes (Customer objects) that are all waiting    */
/* for a specific event.                                                     */
/*****************************************************************************/

#include "waitingroom.h"

void Waitingroom::remove(Customer* customer) {
    if(!customer) return;
    this->Queue::remove(customer);
}

