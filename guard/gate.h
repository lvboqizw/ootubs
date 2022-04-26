/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                                  G A T E                                  */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Class of objects that handle interrupts.                                  */
/*****************************************************************************/

#ifndef __Gate_include__
#define __Gate_include__

/* Add your code here */ 
class Gate
{
private:
    /* data */
public:
    Gate();
    ~Gate();

    virtual void trigger() = 0;
};

#endif
