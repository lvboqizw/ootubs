/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                               L O C K E R                                 */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* The Locker class implements a lock that can be used to protect critical   */
/* sections. However, the variable only indicates whether the critical       */
/* section is free. Potentially necessary waiting, and protection for        */
/* counting functionality, must be implemented elsewhere.                    */
/*****************************************************************************/

#ifndef __Locker_include__
#define __Locker_include__

#include "device/cgastr.h"

extern CGA_Stream kout;

class Locker {
private:
	Locker(const Locker &copy); // prevent copying
/* Add your code here */ 
	bool lock;
public:
	Locker() : lock(false) {};
	//a critical section is entered and the locking variable has to be locked
	inline void enter() {
		if(lock==true) {
			kout << "already in the lock" << endl;
		}
		// kout << "in lock" << endl;
		lock = true;};
	//a critical section is left and the locking variable can be released
	inline void retne() {
		if(lock == false) {
			kout<<"there is no lock" << endl;
		}
		lock = false;};
	//indicates whether the critical section is free
	inline bool avail() {return !lock;};
};

#endif
