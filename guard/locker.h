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

class Locker {
private:
	Locker(const Locker &copy); // prevent copying
/* Add your code here */ 
	bool lock;
public:
	Locker() : lock(false) {};
	//call the method to enter the  critical section
	inline void enter() {lock = true;};
	//call the method to leave the critical section
	inline void retene() {lock = false;};
	//indicates whether the critical section is free
	inline bool avail() {return !lock;};
};

#endif
