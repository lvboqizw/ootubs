/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                          D I S P A T C H E R                              */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Dispatcher implementation.                                                */
/* The Dispatcher maintains the life pointer that points to the currently    */
/* active coroutine. go() initializes the life pointer and starts the first  */
/* coroutine, all further context switches are triggered by dispatch().      */
/* active() returns the life pointer.                                        */
/*****************************************************************************/

/* Add your code here */ 
// #include "thread/dispatch.h"
// #include "device/cgastr.h"

// extern CGA_Stream kout;

// Dispatcher::Dispatcher(){
//     this -> ptr = 0;
// }

// void Dispatcher::go(Coroutine &first){
//     // Prozess speichern
//     this -> ptr = &first;
//     // Prozess ausführen
//     first.go();
// }

// void Dispatcher::dispatch(Coroutine &next){
//     // aktuellen Prozess zwischenspeichern
//     Coroutine *temp = this -> ptr;

//     if(!this -> ptr) return;

//     // Pointer neu setzen
//     this -> ptr = &next;
//     // Koroutinenwechsel
//     temp -> resume(*ptr);
// }

// Coroutine* Dispatcher::active(){
//     return this -> ptr;
// }