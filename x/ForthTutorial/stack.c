
#include "stack.h"
#include "dictionary.h"

// this module implements the basic functions of the forth stack, allowing you to push a value or command onto it, and to
// pop a value from it

/** -------------------------------
    Our global stack
 * -------------------------------*/

// stack points to the topmost stack element
StackElement *stack = NULL;

//
// if the word is a command in our dictionary, execute the command
// otherwise push the value onto the stack
// perform some checking - if what we push is NOT a number raise an error
Retcode stackPush(char *word) {
    
    Entry *command;
    
    Retcode ret = dictLookupCommand(word, &command);
    if (ret == OK)
    {
        // we successfully looked up a command - so now we execute it
        ret = command->code();
    }
    else
    {
        if (ret == ERR_NOT_YET_IMPLEMENTED)
        {
            printf("\nERR: was asked to execute the '%s' command, but that command hasn't been implemented yet. Add the implementation in forth.c !\n",word);
        }
        else
        {
            // check if this is a number
            StackValue val;
            sscanf(word,"%ld",&val);
            char buf[255];
            sprintf(&buf[0],"%ld",val);
            if (strcmp(buf,word) != 0)
            {
                printf("\nERR: was given an unknown word '%s' which I cannot interpret. Try 'help' for a list of available commands.\n",word);
                ret = ERR_UNKNOWN_COMMAND;
            }
            else
            {
                ret = stackPushValue(val);
            }
        }
    }
    return ret;
}

Retcode stackPushValue(StackValue val)
{
    // push the number onto the stack

    // allocate space for a new stack element
    StackElement *newStackElement = malloc(sizeof(StackElement)*sizeof(char));
    // initialise with the parameter
    newStackElement->value = val;
    newStackElement->next = stack;   // link to the previous top of the stack
    stack = newStackElement; // and make the new element the top of the global stack

    return OK;
}

// pop the topmost element from the stack and return it as a StackValue via the given pointer
Retcode stackPop(StackValue *value) {
    Retcode ret = OK;
    if (stack)
    {
        // we have at least one element on the stack - good !
        // transfer the number value from the stack (stored in 'word' as a string) to the value pointer given
        *value = stack->value;
        // move the top pointer to the next element - again, no memory management of the topmost element which should now be freed..
        stack = stack->next;
    }
    else
    {
        ret = ERR_STACK_EMPTY;
        *value = 0;
    }
    return ret;
}

// return the current depth of the stack (how many elements we have)
int stackDepth(void)
{
    int depth = 0;
    StackElement *top = stack;
    while (top)
    {
        top = top->next;
        depth+=1;
    }
    return depth;
}

