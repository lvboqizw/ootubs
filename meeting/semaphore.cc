/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                           S E M A P H O R E                               */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* The class Semaphore implements the synchronization concept of the         */
/* counting semaphore.                                                       */
/*****************************************************************************/

#include "semaphore.h"

Semaphore::Semaphore(int c) {
    counter = c;
}

void Semaphore::p() {

}

void Semaphore::v() {

}

void Semaphore::wait() {
    p();
}

void Semaphore::signal() {
    v();
}