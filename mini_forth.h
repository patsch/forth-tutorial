
// these first two lines below are used to ensure that an Include (Header) file
// is only over loaded once during a compilation process for a C program.
// Without them you would get errors/warnings about things being defined more than once.

#ifndef __MINI_FORTH_INCLUDED__
#define __MINI_FORTH_INCLUDED__

#define VERSION "1.0"

#include <stdio.h>
#include <stdlib.h>

typedef long int StackValue;    // the type of data you can push onto the stack (we just use long integer numbers)


// my typedef for a stack element - in theory we could reuse the 'Entry' typedef above, but I wanted to keep it very simple.
// my stack definition simply contains the 'word' given and a pointer to the next element. if the pointer is null then you have reached the bottom of the stack.
// often stacks are implemented with a fixed array and a size helper, i.e. https://groups.csail.mit.edu/graphics/classes/6.837/F04/cpp_notes/stack1.html
// but I went for the more dynamic version

typedef struct StackElement
{
  char *word; // the text that triggers this dictionary entry
  struct StackElement *next;
} StackElement;

// we defined RefStackElement as a pointer to a StackElement
typedef StackElement *RefStackElement;


// a generic return code that can be used to express an error condition in a function
typedef enum
{
    OK = 0
    ,   ERR_NON_IMPL = -100
    ,   ERR_STACK_EMPTY =    -1
    ,   ERR_DICO_NOCODE = -19
} Retcode;

// Boolean values in FORTH
#define FORTH_TRUE (StackValue)-1
#define FORTH_FALSE (StackValue)0

// quelques types et constantes utiles Èmulant C++
typedef enum { false, true } bool;

#ifndef NULL // gcc on Darwin (MacOS) already defines NULL
#define NULL (void*)0
#endif

// an enum for the commands our forth interpreter supports
typedef enum
{
    COMMAND_PLUS, COMMAND_MINUS, COMMAND_TIMES, COMMAND_DIVIDED, COMMAND_DUPLICATE, COMMAND_POP
} ForthCommand;


// a function pointer type
typedef Retcode (*CodeForWord)();

// the stack variable
extern StackElement *stack;

#endif
