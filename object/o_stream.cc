/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                            O _ S T R E A M                                */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* The O_Stream class defines the << operator for several pre-defined data   */
/* types and thereby realizes output functionality similar to C++'s iostream */
/* library. By default, this class supports printing characters, strings and */
/* integer numbers of various bit sizes. Another << operator allows to use   */
/* so-called 'manipulators'.                                                 */
/*                                                                           */
/* Besides class O_Stream this file also defines the manipulators hex, dec,  */
/* oct and bin for choosing the basis in number representations, and endl    */
/* for implementing an (implicitly flushing) line termination.               */
/*****************************************************************************/

#include "object/o_stream.h"


int ulong_to_char_stack(unsigned long n, char* stack, int base)
{
	char characters[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
	int i = 66; 
	do
	{
		int reminder = n%base;
		n /= base;
		stack[i] = (characters[reminder]); 
		--i;
	} while(n > 0);
	if(base == 16) {
		stack[i] = 'x';
		--i;
	}
	if(base == 8 or base == 16) {
		stack[i] = '0';
		--i;
	}
	if(base == 2) {
		stack[i] = 'b';
		--i;
	}
	return i;
}


O_Stream& O_Stream::operator << (unsigned long n) {
    char stack[65];
    int i = ulong_to_char_stack(n,stack, this->b);

    for (int j = i+1; j < 66; ++ j) {
        this -> put(stack[j]);
    }

    return *this;
}

O_Stream& O_Stream::operator << (long n) 
{
	char stack[66];
	int i = ulong_to_char_stack((unsigned long) n, stack, this->b);

	if(n < 0)
	{
		stack[i]='-';
		--i;
	}

	for(int j = i+1; j < 66; ++j)
	{
		this->put(stack[j]);
	}

	return *this;
}

O_Stream& O_Stream::operator << (char c) {
    this->put(c);
    return *this;
}

O_Stream& O_Stream::operator << (short n) {
	return operator<<((long)n);
}

O_Stream& O_Stream::operator << (unsigned short n) 
{
	return operator<<((unsigned long)n);
}
O_Stream& O_Stream::operator << (int n) 
{
	return operator<<((long)n);
}

O_Stream& O_Stream::operator << (unsigned int n) 
{
	return operator<<((unsigned long)n);
}

O_Stream& O_Stream::operator << (unsigned char n) 
{
	return operator<<((unsigned long)n);
}

O_Stream& O_Stream::operator << (void* pointer){
	Base tmp = this->b;
	this->b = HEX;
	operator << ((unsigned long)pointer);
	this->b = tmp;
	return *this; 
}

O_Stream& O_Stream::operator << (char* text){
	while(*text != '\0')
	{
		this->put(*text);
		text++;
	}
	return *this;
}

O_Stream& O_Stream::operator << (O_Stream& (*fkt) (O_Stream&)){
	return fkt(*this);
}

O_Stream& end(O_Stream& stream) {
    stream.put('\n');
    stream.flush();
    return stream;
}

O_Stream& bin(O_Stream& stream)
{
    stream.b = O_Stream::Base::BIN;
    return stream;
}

O_Stream& hex(O_Stream& stream)
{
    stream.b = O_Stream::Base::HEX;
    return stream;
}

O_Stream& dec(O_Stream& stream)
{
    stream.b = O_Stream::Base::DEC;
    return stream;
}

O_Stream& oct(O_Stream& stream)
{
    stream.b = O_Stream::Base::OCT;
    return stream;
}