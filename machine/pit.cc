/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                                  P I T                                    */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Programmable Interval Timer.                                              */
/*****************************************************************************/

#include "machine/pit.h"

void PIT::interval(int us) {
    this -> us = us;

    long tmp = this -> us;

   tmp *= 1000; // how many steps are needed to reach us microseconds 

    tmp /= 838; // intieger division , :837
 
    unsigned short steps = (unsigned short) tmp; //reduce the result to the 2 Byte size

    /** Set up the control register:
     * 6-7 -> 00 : Counter 0 for periodic interrupts
     * 4-5 -> 11 : read/write least significant byte first, then most significant byte
     * 1-3 -> 010 : periodic interrupt
     * 0 : binary counting of 16 bits
     * => 0b00110100 = 0x34
    */
    this -> crtl_register.outb(0x34);

    this -> counter.outb((char)steps);
    this -> counter.outb((char)(steps >> 8)); 
}
