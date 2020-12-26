
#ifndef __DICTIONARY_INCLUDED__
#define __DICTIONARY_INCLUDED__

#include "mini_forth.h"

// Entry: this is the structure that holds one dictionary entry. the dictionary is used to define what 'operations' forth understands - in this
// very simple example, it will be only the 4 basic arithmetic operations, +,-,* and / as well as 'dup' (to duplicate the top stack element) and 'pop' to remove the top stack element


// an enum for the commands our forth interpreter supports
typedef enum
{
    COMMAND_PLUS, COMMAND_MINUS, COMMAND_MULTIPLY, COMMAND_DIVIDE, COMMAND_MODULO, COMMAND_DUPLICATE, COMMAND_BYE, COMMAND_POP, COMMAND_PRINT,COMMAND_HELP
} ForthCommand;


// a function pointer type
typedef Retcode (*CodeForWord)(void);

typedef struct Entry
{
  char *word;         // the text that triggers this dictionary entry
  char *description; // a short description of what this entry does
  ForthCommand id;   // the code corresponding to the word
  CodeForWord code;  // the code that is executed if this word is found ( typedef Retcode (*CodeForWord)(); )
  struct Entry *next_entry; // to be able link up dictionary elements in a list
} Entry;

// define a pointer to an entry as a separate type (RefEntry)
typedef Entry *RefEntry;

extern Retcode dictInit(void);
extern Retcode dictLookupCommand(char *word, Entry **returnedEntry);
extern Retcode dictAddCommand(char *word, char *description, ForthCommand id, CodeForWord code);

// the reference to the global command dictionary
extern Entry *commandDictionary;
#endif

