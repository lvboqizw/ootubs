/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                   G U A R D E D _ K E Y B O A R D                         */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* The Guarded_Keyboard class provides the system call interface to the      */
/* keyboard.                                                                 */
/*****************************************************************************/

#include "guarded_keyboard.h"


Key Guarded_Keyboard::getkey() {
    Secure secure;
    Keyboard::getkey();
}
