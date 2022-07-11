#include "device/cgastr.h"
#include "syscall/thread.h"
#include "syscall/guarded_keyboard.h"
#include "user/appl.h"

extern CGA_Stream kout;
extern Guarded_Keyboard guarded_keyboard;
extern int stack_size;


class System: public Thread
{
private:
    System(const System &copy);

public:
    System(void* tos): Thread(tos){};

    void action();
};
