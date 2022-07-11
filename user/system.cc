#include "system.h"



void System::action() {
    select();
}

void System::select() {
    unsigned short x, y = 1;
    while (1) {
        if(from_other) {
            kout.clear();
            kout << "press 'w', 's' and 'enter' to select: "<< endl;
            kout << "   Application" << endl;
            kout << "   Loop" << endl;
            kout << "   Application 3" << endl;
            kout << "   Application 4" << endl;

            kout.getpos(x, applnum);                            // get the counts of the applications
            kout.setpos(0, 1);                                  // reset the cursor at the beginning
            kout.changOneLineColor(y, SELECTED_COLOR);          // change the line which now the cursor point at to the selected color

            from_other = false;
        }
        
        Key key = guarded_keyboard.getkey();            // wait for the keyboard input
        if(key == 'w') {                                // if w is pressed, move up
            kout.changOneLineColor(y, ORIGIN_COLOR);    // changed the current line to the origin color
            if(y != 1) {                                // if the current y is not 0
                y -= 1;                                 // y minus 1
                kout.setpos(x, y);                      // setup the new cursor
                kout.changOneLineColor(y, SELECTED_COLOR);  // set the new line at the selected color
            }else {
                y = applnum - 1;                        // y is 0, move to the end
                kout.setpos(x, y);                      
                kout.changOneLineColor(y, SELECTED_COLOR);
            }
        }
        if(key == 's') {                               // if 's' is pressed, move down
            kout.changOneLineColor(y, ORIGIN_COLOR);
            if(y != applnum -1) {
                y += 1;
                kout.setpos(x, y);
                kout.changOneLineColor(y, SELECTED_COLOR);
            }else {
                y = 1;                                  // y is at the end, move to the begin
                kout.setpos(x, y);                      
                kout.changOneLineColor(y, SELECTED_COLOR);
            }
        }
        if(key.ascii() == 10) {
            switch (y)
            {
            case  1:                                    // the first thread: application
                {
                    Application appl(stack1 + STACK_SIZE);
                    guarded_organizer.ready(appl);
                    process_sem.wait();
                    from_other = true;
                }
                break;
            
            default:
                from_other = false;
                break;
            }
        }
    }
}

