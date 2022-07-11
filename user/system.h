#include "device/cgastr.h"
#include "./global.h"
#include "syscall/thread.h"
#include "syscall/guarded_keyboard.h"
#include "syscall/guarded_semaphore.h"
#include "syscall/guarded_organizer.h"
#include "user/appl.h"
#include "user/loop.h"


extern CGA_Stream kout;
extern Guarded_Keyboard guarded_keyboard;
extern Guarded_Semaphore process_sem;
extern Guarded_Organizer guarded_organizer;


class System: public Thread
{
private:
    System(const System &copy);

    unsigned short applnum;
    unsigned char SELECTED_COLOR = (((WHITE << 4) & 0xf0) | (BLACK & 0xf));
    unsigned char ORIGIN_COLOR = (((BLACK << 4) & 0xf0) | (WHITE & 0xf));

    unsigned char stack1[STACK_SIZE];
    bool from_other = true;

    void select();

public:
    System(void* tos): Thread(tos){};

    void action();
};
