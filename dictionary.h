
#ifndef __DICTIONARY_INCLUDED__
#define __DICTIONARY_INCLUDED__

#include "mini_forth.h"

// Entry: this is the structure that holds one dictionary entry. the dictionary is used to define what 'operations' forth understands - in this
// very simple example, it will be only the 4 basic arithmetic operations, +,-,* and / as well as 'dup' (to duplicate the top stack element) and 'pop' to remove the top stack element

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

extern Retcode DicoInit();
extern Retcode DicoFind(char *word, Entry *entry);
extern Retcode DicoAdd(char *word, char *description, ForthCommand id, CodeForWord code);

#endif

