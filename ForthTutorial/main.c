/*

    Tiny Forth Tutorial

    Implements some basic features of forth, a stack to push things onto, and a dictionary of 'operations' on stack elements


    by Patrick Dockhorn - Dec 26th 2020
*/

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>

#include "main.h"
#include "dictionary.h"
#include "stack.h"

// our code entry point
// our very simple forth requires you to pass in all parametres on the command line

int debug = 0; // set to 1 to debug (i.e. get more output during the run)

int main(int argc, char * argv[])
{
    
    dictInit(); // initialise the command dictionary
 

    // process any command line parameters first

    Retcode ret = OK;

    if (argc > 1)
    {
        for (int i = 1 ; ((i < argc) && (ret == OK)) ; i++)
        {
            char *word = argv[i];
            if (debug)
            {
                printf("Processing command line parameter %d : '%s'...",i,word);
            }
            ret = stackPush(word);
        }
        
    }
    // now interactively wait for input from the user (unless the command line contained a 'bye')
    
    char *line; // max input length is 1024, buffer overflow...
    size_t len = 0;
    ssize_t lineSize = 0;
    
    // unless the command line had a 'bye' command, enter interactive mode after processing the command line elements
    while (ret != BYEBYE)
    {
        printf("\n[%d] > ",stackDepth());
        
        lineSize = getline(&line, &len, stdin);

        // remove newline at the end...
        if (lineSize > 0)
        {
            if ((line[lineSize - 1] == '\n')||(line[lineSize - 1] == '\r'))
              {
                  // printf("chomping...\n");
                  line[lineSize - 1] = '\0';
                  --lineSize;
              }
        }
        
        if (debug)
        {
            printf("You entered <%s>, which has %zu chars. Spaces are evil, so do not surround your commands/values with spaces!\n", line, lineSize);
        }

        ret = stackPush(line);

        // memory management: should 'free' line as space for it is allocated in getline()
    }
        

    // show the stack at the end in debug mode
    if (stackDepth() > 0)
    {
        printf("\n\nResulting Stack at the end:\n");
        StackElement *top = stack;
        int pos = 0;
        while (top)
        {
            printf("[%d] <%ld>\n",pos,top->value);
            top = top->next;
            pos++;
        }
    }
    printf("\n\n");

    // free up the memory you allocated (at least some of it...)
}

char *errorStringFor(Retcode ret)
{
    char *sret = NULL;
    switch (ret)
    {
        case OK:
        {
            sret = "OK";
            break;
        }
        case ERR_STACK_EMPTY:
        {
            sret = "Stack is empty";
            break;
        }
        case ERR_UNKNOWN_COMMAND:
        {
            sret = "Unknown command";
            break;
        }
        case ERR_NOT_YET_IMPLEMENTED:
        {
            sret = "Command not yet implemented";
            break;
        }
        default:
        {
            sret = "Unknown/Unmapped return code (see errorStringFor() in main.c)";
            break;
        }
    }
    return sret;
}
