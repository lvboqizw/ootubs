#include "speaker.h"

void Speaker::interval(int fq) {
    this -> fq = fq;

    // int div = 1193180 / fq;
    int div = fq;

    /** Set up the control register:
     * 6-7 -> 10 : Counter 2 for speaker signal
     * 4-5 -> 11 : read/write least significant byte first, then most significant byte
     * 1-3 -> 011 : Square wave signal generator
     * 0 : binary counting of 16 bits
     * => 0b10110110 = 0xb6
    */
    this -> crtl_register.outb(0xb6);

    this -> counter.outb((char)div);
    this -> counter.outb((char)(div >> 8)); 
}

void Speaker::speak() {
    int tmp = speaker.inb();
    speaker.outb(tmp | 3);
}

void Speaker::stop() {
    int tmp = speaker.inb();
    speaker.outb(tmp & 0xfc);
}