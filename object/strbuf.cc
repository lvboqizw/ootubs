/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                       S T R I N G B U F F E R                             */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* The Stringbuffer class provides a buffer for collecting characters to be  */
/* printed to an output device, in our case the PC screen. The actual output */
/* occurs once the buffer is full, or when the user explicitly calls         */
/* flush().                                                                  */
/* As Stringbuffer is intended to be device independent, flush() is a        */
/* (pure) virtual method that must be defined by derived classes.            */
/*****************************************************************************/

#include "object/strbuf.h"


Stringbuffer::Stringbuffer() {
    used_capacity = 0;
}

void Stringbuffer::put(char c) {
    if(used_capacity >= size){    //used_capactiy show the number of characters in the buffer,
        this->flush();
        used_capacity = 0;
    }
    buffer[used_capacity] = c;    
    ++ used_capacity;
}

