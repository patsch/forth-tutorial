

#include "dictionary.h"


Entry *dict;


Retcode DicoInit() {
    dict = NULL;
    return OK;
}

Retcode DicoFind(char *word, Entry *entry) {
    return OK;
}

// DicoAdd is a helper method to add to the dictionary of keywords and the associated code
// note that the last parameter (code) is actually defined as a "pointer to function", so we can simply pass in a function name
// (see further down in 'main' where we use addToDictionary to set up our dictionary)

Retcode DicoAdd(char *word, char *description, ForthCommand id, CodeForWord code){
    
    // fetch the current dictionary entry (starting from 0)
    Entry *entry = (Entry*) malloc(sizeof(Entry)*sizeof(char));

    // assign the dictionary properties from the parameters
    entry->word = word;
    entry->description = description;
    entry->id = id;
    entry->code = code;


    // point to the current dictionary element as the next entry
    // initially dict is NULL, so this ensure the next_entry is initially set to NULL
    entry->next_entry = dict;

    // point the start of the dictionary to the entry
    dict = entry;

}

