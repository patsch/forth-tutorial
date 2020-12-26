

#include "mini_forth.h"
#include "dictionary.h"
#include "forth.h"

Entry *commandDictionary;


Retcode dictInit() {
    commandDictionary = NULL;
    
    // add the '+' operator to the dictionary. it is triggered when you use '+'.
    // To execute it, call the 'add' method defined in forth.c
    dictAddCommand("+","Addition: Pop two values from the stack, add them, then push the result back onto the stack.",COMMAND_PLUS,add);


    // add the '-' operator to the dictionary. it is triggered when you use '-'.
    // To execute it, call the 'minus' method defined in forth.c
    dictAddCommand("-","Subtraction: Pop the subtrahend from the stack, then pop the minuend, then calculate the difference by subtracting the subtrahend from the minuend and push the resulting difference back onto the stack.",COMMAND_MINUS,subtract);

    // add the '*' (multiply) operator to the dictionary. it is triggered when you use '*'.
    // To execute it, call the 'multi' method defined in forth.c
    dictAddCommand("*","Multiplication: Pop two values from the stack, multiply them, then push the result back onto the stack.",COMMAND_MULTIPLY,mult);

    // add the '/' (divide) operator to the dictionary. it is triggered when you use '/'.
    // To execute it, call the 'div' method defined in forth.c
    dictAddCommand("/","Division: Pop the divisor from the stack, then pop the dividend, then calculate the quotient by dividing the dividend by the divisor and push the resulting quotient back onto the stack.",COMMAND_DIVIDE,divide);

    // add the '%' (modulo) operator to the dictionary. it is triggered when you use '%'.
    // To execute it, call the 'modulo' method defined in forth.c
    dictAddCommand("%","Remainder: Pop the divisor from the stack, then pop the dividend, then calculate the remainder by dividing the dividend by the divisor and push the resulting remainder of the division back onto the stack.",COMMAND_MODULO,modulo);

    // add the 'dup' (duplicate the topmost stack element) operator to the dictionary. it is triggered when you use 'dup'.
    // To execute it, call the 'duplicate' method defined in forth.c
    dictAddCommand("dup","Duplicate : Duplicate the topmost element on the stack, i.e. pop it, then push it back twice.",COMMAND_DUPLICATE,duplicate);

    // add the 'pop' (pop i.e. remove the topmost stack element) operator to the dictionary. it is triggered when you use 'pop'.
    // To execute it, call the 'pop' method defined in forth.c
    dictAddCommand("pop","Pop : Remove the topmost element from the stack.",COMMAND_POP,pop);

    // add the 'print' (print out the topmost element of the stack then remove it
    dictAddCommand(".","Print : Remove the topmost element from the stack (pop), then print it.",COMMAND_PRINT,print_pop);

    // add the 'print all' (print out the topmost element of the stack then remove it
    dictAddCommand("...","Print Stack : Print the complete stack to the screen without changing it.",COMMAND_PRINT_ALL,print_all);

    dictAddCommand("help","Help: Print out the available forth commands",COMMAND_HELP,forth_help);

    dictAddCommand("bye","Bye: Quit processing and exit to the shell.",COMMAND_BYE,forth_bye);

    return OK;
}

Retcode dictLookupCommand(char *word, Entry **returnedEntry) {
    
    Entry *entry = commandDictionary;
    
    // walk through our dictionary, trying to identify the given command
    
    int matchedAnyWord = 0;
    
    // look through our list of command keywords until we're either through the list
    // or we found a match
    while ((entry) && (matchedAnyWord == 0))
    {
        // does the current word match ?
        if (strcmp(entry->word,word) == 0)
        {
            // yes !
            if (debug)
            {
                printf("'%s' Matched '%s' keyword - applying to stack...\n",entry->word,entry->description);
            }
            
            matchedAnyWord = 1;
            
            // set the return pointer to the entry we found so the caller can work with it
            *returnedEntry = entry;
            // run the code associated with the keyword in our dictionary - this will now call one of the dictionary defined functions above
            // entry->code();
        }
        entry = entry->next_entry;
    }
    
    if (!matchedAnyWord)
    {
        *returnedEntry = NULL; // set the return pointer to NULL, just to make it clear we didn't find anything
        return ERR_UNKNOWN_COMMAND;
    }
    else
    {
        return OK;
    }
}

// DicoAdd is a helper method to add to the dictionary of keywords and the associated code
// note that the last parameter (code) is actually defined as a "pointer to function", so we can simply pass in a function name
// (see further down in 'main' where we use addToDictionary to set up our dictionary)

Retcode dictAddCommand(char *word, char *description, ForthCommand id, CodeForWord code){
    
    // allocate memory for a new dictionary entry
    Entry *entry = (Entry*) malloc(sizeof(Entry)*sizeof(char));

    // assign the dictionary properties from the parameters
    entry->word = word;
    entry->description = description;
    entry->id = id;
    entry->code = code;


    // internally our dictionary is also implemented as a stack, i.e. the elements are just linked to each other,
    // always starting with the most recently added elements. The dictionary functionality (lookup) is provided via
    // a function (dictLookupCommand) that works with that list and makes the 'dictionary' module behave like a dictionary should.
    
    // point to the current dictionary element as the next entry
    // initially dict is NULL, so this ensure the next_entry is initially set to NULL
    entry->next_entry = commandDictionary;

    // point the start of the dictionary to the entry
    commandDictionary = entry;

    return OK;
}

