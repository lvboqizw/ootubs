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

#include "io_port.h"
#include "pic.h"

PIC::PIC() {

    IO_Port master_1(0x20), slave_1(0xa0), master_2(0x21), slave_2(0xa1);

    //initialising the PIC's registers
    //Set ICW1
    master_1.outb(0x11);
    slave_1.outb(0x11);

    //Set ICW2
    master_2.outb(0x20);
    slave_2.outb(0x28);

    //Set ICW3
    master_2.outb(0x04);
    slave_2.outb(0x02);

    //Set ICW4
    master_2.outb(0x03);
    slave_2.outb(0x03);
}
