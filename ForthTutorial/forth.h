//
//  forth.h
//  
//
//  Created by Patrick Dockhorn on 26/12/20.
//

// this is the header file for the commands provided by this tiny forth implementation

#ifndef __FORTH_INCLUDED__
#define __FORTH_INCLUDED__

#include "main.h"

// execute the 'add' function on the top two stack entries
extern Retcode add(void);

// execute the 'subtract' function on the top two stack entries
extern Retcode subtract(void);

// execute the 'multiplication' function on the top two stack entries
extern Retcode mult(void);


// execute the 'division' function on the top two stack entries
extern Retcode divide(void);

// execute the 'modulo' (remainder) function on the top two stack entries
extern Retcode modulo(void);

// execute the 'duplication' function (duplicate the topmost element)
extern Retcode duplicate(void);

// execute the 'pop' function (remove the topmost element)
extern Retcode pop(void);

// execute the 'print_pop' function (print then remove the topmost element)
extern Retcode print_pop(void);

// print all
extern Retcode print_all(void);

// a simple 'help' method to display the available commands and usage
extern Retcode forth_help(void);

// byebye
extern Retcode forth_bye(void);

#endif /* forth_h */
