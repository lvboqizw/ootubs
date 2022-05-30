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

#include "pic.h"
#include "cpu.h"

// initializ the pic chip
PIC::PIC() : master_1(0x20), slave_1(0xa0), master_2(0x21), slave_2(0xa1)
{

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

    //initialise OCW1
    master_2.outb(0xFB);    //PIC1 (master) - allow only D2 -> slave
    slave_2.outb(0xFF);    //PIC2 (slave) - allow none
}


void PIC::allow(int interupt_device) {
    unsigned char ocw1;

    if(interupt_device < 8) {             // use the first PIC
        ocw1 = master_2.inb();            //get current state to ensure previous bits stay set
        ocw1 &= ~(1 << interupt_device);  //set the corresponding bit to 0 so that it's allowed
        master_2.outb(ocw1);              
    } else {                              // use the second PIC
        ocw1 = slave_2.inb();             //get current state to ensure previous bits stay set
        ocw1 &= ~(1<<(interupt_device-8));  //set the corresponding bit to 0 so that it's allowed
        slave_2.outb(ocw1);  
    }
}

void PIC::forbid(int interupt_device) {
    unsigned char ocw1;

    if(interupt_device < 8) {             // use the first PIC
        ocw1 = master_2.inb();            //get current state to ensure previous bits stay set
        ocw1 |= (1 << interupt_device);   //set the corresponding bit to 1 so that it's not allowed
        master_2.outb(ocw1);              
    } else {                              // use the second PIC
        ocw1 = slave_2.inb();             //get current state to ensure previous bits stay set
        ocw1 |= (1<<(interupt_device-8)); //set the corresponding bit to 1 so that it's not allowed
        slave_2.outb(ocw1);  
    }
}

bool PIC::is_masked(int interupt_device) {
    unsigned char ocw1;
    bool is_masked;

    if(interupt_device < 8) {
        ocw1 = master_2.inb();               //get current state
        if((ocw1>>interupt_device) & 0x01) { //check if the corresponding bit is 1
            is_masked = true;                //if it's 1, the device is masked
        } else {
            is_masked = false;               //otherwise is not masked
        }
    } else {
        ocw1 = master_2.inb();               //get current state
        interupt_device -= 8;              
        if((ocw1>>interupt_device) & 0x01) {
            is_masked = true;
        } else {
            is_masked = false;
        }
    }
    return is_masked;
}
