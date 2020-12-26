

#ifndef __STACK_INCLUDED__
#define __STACK_INCLUDED__

#include "main.h"

typedef long int StackValue;    // the type of data you can push onto the stack (we just use long integer numbers)

// my typedef for a stack element - in theory we could reuse the 'Entry' typedef above, but I wanted to keep it very simple.
// my stack definition simply contains the 'word' given and a pointer to the next element. if the pointer is null then you have reached the bottom of the stack.
// often stacks are implemented with a fixed array and a size helper, i.e. https://groups.csail.mit.edu/graphics/classes/6.837/F04/cpp_notes/stack1.html
// but I went for the more dynamic version

typedef struct StackElement
{
  StackValue value; // the value at this position in the stack (a number)
  struct StackElement *next;
} StackElement;

// we defined RefStackElement as a pointer to a StackElement
typedef StackElement *RefStackElement;

// the stack variable
// the 'extern' declaration allows other .c modules to import this main.h header file and refer to the 'stack'
// global variable, even though it is actually defined only in main.c
extern StackElement *stack;

extern Retcode stackPush(char *word);
extern Retcode stackPushValue(StackValue val);
extern Retcode stackPop(StackValue *value);
extern int stackDepth(void);
#endif

