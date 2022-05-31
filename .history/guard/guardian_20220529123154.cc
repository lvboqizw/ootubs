/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              G U A R D I A N                              */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* The system's central interrupt handling routine.                          */
/* The parameter specifies the number of the interrupt that occurred.        */
/*****************************************************************************/

/* INCLUDES */
#include "machine/plugbox.h"
#include "machine/cpu.h"
#include "guard/guard.h"

#include "device/cgastr.h"
/* FUNCTIONS */

extern "C" void guardian (unsigned int slot);


extern Plugbox plugbox;
extern CPU cpu;
extern Guard guard;

//for debug
extern CGA_Stream kout;
//

/* GUARDIAN: Low-level interrupt handling. We will extend this function at */
/*           a later point in time.                                        */

void guardian (unsigned int slot)
{
    Gate& g = plugbox.report(slot);           //use slot get an interup from the table,
    bool flag = g.prologue();
    if (flag)
        guard.relay(& g);                 
}