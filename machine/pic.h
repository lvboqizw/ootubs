/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                                  P I C                                    */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Programmable Interrupt Controller.                                        */
/* By using the PIC, hardware interrupts can be enabled or suppressed        */
/* individually. This way we can control whether interrupts of a specific    */
/* device are forwarded to the CPU at all. Even then, the interrupt handler  */
/* gets only activated if the CPU is ready to react to interrupts. This can  */
/* be controlled by using class CPU.                                         */
/*****************************************************************************/

#ifndef __pic_include__
#define __pic_include__

class PIC {
private:
	PIC(const PIC &copy); // prevent copying

	CPU cpu;

	enum {
    	timer    = 0,
    	keyboard = 1
	};

public:
	PIC();

	void allow(int interupt_device);

	void forbid(int interupt_device);

	bool is_masked(int interupt_device);
};

#endif
