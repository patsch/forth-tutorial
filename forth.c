//
//  forth.c
//  
//
//  Created by Patrick Dockhorn on 26/12/20.
//

#include "forth.h"


/********************************************************************
 * The code for our dictionary defined functions
 ********************************************************************/

// the code for the functions our forth interpreter offers

// execute the 'add' function on the top two stack entries
Retcode add() {
    // check if we have at least to elements on the stack, if not return error
    if ((stack == NULL) || (stack->next == NULL))
    {
        return ERR_PILE_VIDE;
    }
    else
    {
        printf("Adding %s and %s and putting result back onto stack\n",stack->word,stack->next->word);

        int val1;
        int val2;
        sscanf(stack->word,"%d",&val1);
        sscanf(stack->next->word,"%d",&val2);

        // remove the topmost stack element (let's ignore memory management for now, we should free the memory occupied by the current 'stack' first)
        stack = stack->next;
        // now replace it's value with the result of the operation (normally we should remove the two topmost elements, then push a new element with the result, but this has the same outcome)
        // convert the sum of the two numbers into a string and make that the current value
        sprintf(stack->word,"%d",val1 + val2);
        return OK;
    }
}

// execute the 'subtract' function on the top two stack entries
Retcode subtract() {
    return OK;
}

// execute the 'multiplication' function on the top two stack entries
Retcode mult() {
    return OK;
}


// execute the 'division' function on the top two stack entries
Retcode divide() {
    return OK;
}

// execute the 'duplication' function (duplicate the topmost element)
Retcode duplicate() {
    return OK;
}

// execute the 'pop' function (remove the topmost element)
Retcode pop() {
    return OK;
}
