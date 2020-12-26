//
//  forth.c
//  
//
//  Created by Patrick Dockhorn on 26/12/20.
//

// this is the code for the commands provided by this tiny forth implementation
// as defined by our 'command dictionary' (see dictionary.c)

#include "stack.h"
#include "forth.h"
#include "dictionary.h"

// the code for the functions our forth interpreter offers

// execute the 'add' function on the top two stack entries
Retcode add() {
    Retcode ret = OK;
    
    StackValue val1;
    StackValue val2;
    
    // pop the first value
    ret = stackPop(&val1);
    if (ret == OK)
    {
        // if ok, pop the 2nd value
        ret = stackPop(&val2);
        if (ret == OK)
        {
            // if still ok, add the two values, then push the result
            StackValue result = val1 + val2;
            stackPushValue(result);
        }
    }
    return ret;
}

// execute the 'subtract' function on the top two stack entries
Retcode subtract() {
    Retcode ret = OK;
    
    StackValue val1;
    StackValue val2;
    
    // pop the first value
    ret = stackPop(&val1);
    if (ret == OK)
    {
        // if ok, pop the 2nd value
        ret = stackPop(&val2);
        if (ret == OK)
        {
            // if still ok, subtract the two values, then push the result
            StackValue result = val2 - val1;
            stackPushValue(result);
        }
    }
    return ret;
}

// execute the 'multiplication' function on the top two stack entries
Retcode mult() {
    Retcode ret = OK;
    
    StackValue val1;
    StackValue val2;
    
    // pop the first value
    ret = stackPop(&val1);
    if (ret == OK)
    {
        // if ok, pop the 2nd value
        ret = stackPop(&val2);
        if (ret == OK)
        {
            // if still ok, subtract the two values, then push the result
            StackValue result = val1 * val2;
            stackPushValue(result);
        }
    }
    return ret;
}

// execute the 'division' function on the top two stack entries
Retcode divide() {
    return ERR_NOT_YET_IMPLEMENTED;
}


// execute the 'modulo' function on the top two stack entries
Retcode modulo() {
    return ERR_NOT_YET_IMPLEMENTED;
}

// execute the 'duplication' function (duplicate the topmost element)
Retcode duplicate() {
    return ERR_NOT_YET_IMPLEMENTED;
}

// execute the 'pop' function (remove the topmost element)
Retcode pop() {
    return ERR_NOT_YET_IMPLEMENTED;
}

Retcode print_pop() {
    StackValue val;
    Retcode ret = stackPop(&val);
    if (ret == OK)
    {
        printf("<<<%ld>>>\n",val);
    }
    return ret;
}


Retcode print_all() {
    Retcode ret = OK;
    StackElement *top = stack;
    if (!top)
    {
        printf("\nStack is empty.\n");
    }
    else
    {
        printf("\nStack Contents:\n");
        int pos = 0;
        while (top)
        {
            printf("[%d] <<< %ld >>>\n",pos,top->value);
            top = top->next;
            pos++;
        }
    }
    return ret;
}

// implement a simple help function which can be called on the command line or interactively
Retcode forth_help() {
    printf("\n\n---------------------------------------------------------\n");
    printf("BEGIN HELP\n\n");
    printf("\n\nYou can use this program in two ways - either provide all stack elements on the command line - or work interactively.\n");
    printf("If you provide the stack elements on the command line they will be processed first and the Forth interpreter will then\n");
    printf("enter interactive mode. In interactive mode, you can simply enter values / commands one by one; hit ENTER/RETURN after each\n");
    printf("value/command to push the value/command onto the stack and, if you push a command, perform the requested operation.\n\n");
    printf("Usage:   mini_forth word1 word2 word3 word4 ...\n");
    printf("Example: mini_forth 1 2 +\n");
    printf("\n\nHere is a list of all the operators this mini forth implementation understands:\n\n");
    
    Entry *entry = commandDictionary;
    
    while (entry)
    {
        printf("%s : %s\n",entry->word,entry->description);
        entry = entry->next_entry;
    }
    printf("\n\nEND HELP\n\n");
    printf("---------------------------------------------------------\n\n");
    return OK;
}

Retcode forth_bye() {
    // bye command simple returns a special Return code to indicate to the caller that we should quit
    return BYEBYE;
}
