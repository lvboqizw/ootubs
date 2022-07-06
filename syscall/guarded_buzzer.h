/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                         G U A R D E D _ B U Z Z E R                       */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* The Guarded_Buzzer class implements the system call interface to the      */
/* Buzzer class.                                                             */
/*****************************************************************************/

#ifndef __Guarded_Buzzer_include__
#define __Guarded_Buzzer_include__

/* Add your code here */ 
#include "meeting/buzzer.h"
class Guarded_Buzzer : public Buzzer
/* Add your code here */ 
{
private:
	Guarded_Buzzer(const Guarded_Buzzer &copy); // prevent copying
public:
	Guarded_Buzzer() {}
/* Add your code here */ 
	virtual ~Guarded_Buzzer(){};

	void set(int ms);

	void sleep();
};

#endif
