/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                               B U Z Z E R                                 */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* An "alarm clock" is a synchronization object that allows one or more      */
/* threads to put themselves to sleep for a specified time.                  */
/*****************************************************************************/

/* INCLUDES */
#include "meeting/buzzer.h"
/* Add your code here */ 
Buzzer::Buzzer(){
    alarmClock = false;
}

void Buzzer::set(int ms){
    this->Bell::wait(ms);
}

void Buzzer::sleep(){
    
}