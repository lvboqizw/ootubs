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
    bool queue;

public:
    Gate();
    ~Gate();

    virtual void trigger() = 0;

    virtual bool prologue() = 0;

   virtual void epilogue() = 0;

   void queued(bool q){
       queue = q;
   }

   bool queued() const{//read only
	   return queue;
   }
};

#endif
