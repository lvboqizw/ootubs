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
/* FUNCTIONS */

extern "C" void guardian (unsigned int slot);

extern Plugbox plugbox;
extern CPU cpu;

// //from where??
extern Plugbox plugbox;
extern CPU cpu;

/* GUARDIAN: Low-level interrupt handling. We will extend this function at */
/*           a later point in time.                                        */

void guardian (unsigned int slot)
{
    Gate& g = plugbox.report(slot);           //use slot get an interup from the table,
    g.trigger();                              // trigger the interup or panic(if the slot is out of range)
    cpu.enable_int();                         //after the interup is triggered, enable the cpu to get a new interup
}
