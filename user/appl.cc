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
/* Add your code here */ 
 
/* GLOBAL VARIABLES */
extern CGA_Screen scr;
extern CGA_Stream kout;
/* Add your code here */ 
 
void Application::action()
{
/* Add your code here */ 
    char text[] = "Application";

    scr.setpos(30, 18);
    scr.print(text, sizeof(text)/sizeof(char), WHITE);
}
