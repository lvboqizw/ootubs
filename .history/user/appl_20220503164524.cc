/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                         A P P L I C A T I O N                             */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* The Application class defines the (only) application for OOStuBS.         */
/*****************************************************************************/

/* INCLUDES */

#include "user/appl.h"
#include "device/cgastr.h"
#include "machine/cgascr.h"
#include "machine/cpu.h"
/* Add your code here */ 
 
/* GLOBAL VARIABLES */
extern CGA_Screen scr;
extern CGA_Stream kout;
extern CPU cpu;
/* Add your code here */ 
 
void Application::action()
{
/* Add your code here */ 
    char text[] = "Application";
    while(1) {
        cpu.disable_int();   // for atomic instruction
        scr.set(30,18);
        kout << text;
        kout.flush();
        cpu.enable_int();
    }
}
