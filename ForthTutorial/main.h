// this header file defines some commmon structs and enums for the whole project

// these first two lines below are used to ensure that an Include (Header) file
// is only over loaded once during a compilation process for a C program.
// Without them you would get errors/warnings about things being defined more than once.

#ifndef __MINI_FORTH_INCLUDED__
#define __MINI_FORTH_INCLUDED__

#define VERSION "1.0"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// a generic return code that can be used to express an error condition in a function
// in a C program having an enum like 'Retcode' here to express a status upon returning from a function call
// is generally considered good practice
typedef enum
{
    OK = 0,
    BYEBYE = -1000,                 // used to indicate that we have received the bye command
    ERR_UNKNOWN_COMMAND = -1,       // return when an unknown command is encountered on the stack
    ERR_NOT_YET_IMPLEMENTED = -2,   // return when a known command is used that hasn't been implemented yet
    ERR_STACK_EMPTY = -3            // return when the stack is (unexpectedly) empty, i.e. when you need values from the stack for a command
} Retcode;

// Boolean values in FORTH
#define FORTH_TRUE (StackValue)-1
#define FORTH_FALSE (StackValue)0

// quelques types et constantes utiles Èmulant C++
typedef enum { false, true } bool;

#ifndef NULL // gcc on Darwin (MacOS) already defines NULL, so we check first
#define NULL (void*)0
#endif


extern char *errorStringFor(Retcode ret);

extern int debug;

#endif
