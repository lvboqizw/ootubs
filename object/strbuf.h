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

#ifndef __strbuf_include__
#define __strbuf_include__
#include <stddef.h>


class Stringbuffer {
protected:
	Stringbuffer(const Stringbuffer &copy); // prevent copying

	char buffer[66];
	size_t size = sizeof(buffer);
	char* buf_end;

/* Add your code here */ 
public:
	Stringbuffer();

	void put (char c);

	virtual void flush() = 0;
};

#endif
