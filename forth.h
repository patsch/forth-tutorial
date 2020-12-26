//
//  forth.h
//  
//
//  Created by Patrick Dockhorn on 26/12/20.
//

#ifndef forth_h
#define forth_h

#include "mini_forth.h"

// execute the 'add' function on the top two stack entries
extern Retcode add();

// execute the 'subtract' function on the top two stack entries
extern Retcode subtract();

// execute the 'multiplication' function on the top two stack entries
extern Retcode mult();


// execute the 'division' function on the top two stack entries
extern Retcode divide();

// execute the 'duplication' function (duplicate the topmost element)
extern Retcode duplicate();

// execute the 'pop' function (remove the topmost element)
extern Retcode pop();

#endif /* forth_h */
