/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                                 T O C                                     */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* The toc struct is used to save the values of the non-volatile registers   */
/* in case of a context switch. toc_settle prepares the initial stack and    */
/* the toc struct for the first activation.                                  */
/*****************************************************************************/

#include "machine/toc.h"

// TOC_SETTLE: Prepares a coroutine context for its first activation.
void toc_settle(struct toc *regs, void *tos,
		void (*kickoff)(void *, void *, void *, void *, void *, void *,
				void *),
		void *object)
{
	void **tos_p = tos;		    // a void pointer point to a void pointer
	*(--tos_p) = object;		// put the object in the stack
	*(--tos_p) = 0;				// return point for kickoff, kickoff has no return value so set up as 0
	*(--tos_p) = kickoff;		// return point for resume
	regs->rsp = tos_p; 			// save the stack pointer
}
