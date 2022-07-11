/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                        G U A R D E D _ B U Z Z E R                        */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* The Guarded_Buzzer class implements the system call interface to the      */
/* Buzzer class.                                                             */
/*****************************************************************************/

/* INCLUDES */

#include "syscall/guarded_buzzer.h"
#include "guard/secure.h"

void Guarded_Buzzer::set(int ms){
    Secure secure;
    this->Buzzer::set(ms);
}

void Guarded_Buzzer::sleep(){
    Secure secure;
    this->Buzzer::sleep();
}

Guarded_Buzzer::~Guarded_Buzzer(){
    Secure secure;
    this->Buzzer::~Buzzer();
}