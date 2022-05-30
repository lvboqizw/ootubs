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
        scr.setpos(30,18);
        kout << text;
        kout.flush();
        cpu.enable_int();

        for(int i=0;i<10000;i++){}
    }
}
