/*


	Super Mini Forth

	Implements the main features of forth, a stack to push things onto, and a dictionary of 'operations' on stack elements


    by Patrick Dockhorn - Dec 26th 2020
*/

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>



#include "mini_forth.h"
#include "dictionary.h"

/********************
 * GLOBAL VARIABLES *
 ********************/

// stack points to the topmost stack element
StackElement *stack = NULL;


/********************************************************************
 * END code for our dictionary defined functions
 ********************************************************************/

// our code entry point
// our very simple forth requires you to pass in all parametres on the command line 

int main(int argc, char * argv[])
{
	if (argc <= 1)
	{
		printf("Usage:   miniforth word1 word2 word3 word4 ...\n");
		printf("Example: miniforth 1 2 +\n");
		printf("The program always prints the input stack first, then the stack after it has been evaluated.\n");
	}
	else
	{

		// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		// 1. Initialise the memory for the dictionary - for the moment we hardcode the number of dictionary elements so 'dict' is basically an array of 'Entry' structs
		// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		int numberOfDictionaryElements = 6;



		// add the '+' operator to the dictionary. it is triggered when you use '+', is a kernel word (MOT_NOYAU) and mapped to DICO_PLUS. To execute it, call the 'add' method defined above.
		DicoAdd("+","Add",DICO_PLUS,add);


		// add the '-' operator to the dictionary. it is triggered when you use '-', is a kernel word (MOT_NOYAU) and mapped to DICO_MOINS. To execute it, call the 'minus' method defined above.
		DicoAdd("-","Subtract",DICO_PLUS,subtract);

		// add the '*' (multiply) operator to the dictionary. it is triggered when you use '*', is a kernel word (MOT_NOYAU) and mapped to DICO_MULT. To execute it, call the 'multi' method defined above.
		DicoAdd("*","Multiply",DICO_MULT,mult);

		// add the '/' (divide) operator to the dictionary. it is triggered when you use '/', is a kernel word (MOT_NOYAU) and mapped to DICO_DIV. To execute it, call the 'div' method defined above.
		DicoAdd("/","Divide",DICO_DIV,divide);

		// add the 'dup' (duplicate the topmost stack element) operator to the dictionary. it is triggered when you use 'dup', is a kernel word (MOT_NOYAU) and mapped to DICO_DUP. To execute it, call the 'duplicate' method defined above.
		DicoAdd("dup","Duplicate",DICO_DUP,duplicate);

		// add the 'pop' (pop i.e. remove the topmost stack element) operator to the dictionary. it is triggered when you use 'pop', is a kernel word (MOT_NOYAU) and mapped to DICO_POP. To execute it, call the 'pop' method defined above.
		DicoAdd("pop","Pop",DICO_POP,pop);


		// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		// 2. Convert the parameters given on the command line to a stack, interpreting dictionary keywords as we go along
		// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------

		// remember that argv[0] is the program name, so we skip that first one

		for (int i = 1 ; i < argc ; i++)
		{
			char *word = argv[i];

			// check whether this is a dictionary word - if so, let it run its code
			// if it's not, push it onto the stack

			// loop through all dictionary words until you find a match
			
			int matchedAnyKeywords = 0;

			for (int j = 0 ; ((j < NUMBER_OF_DICTIONARY_ELEMENTS) && (!matchedAnyKeywords)) ; j++)
			{
				// get the dictionary entry at position j
				Entry *entry = &dict[j];

				// does the current word match ?
				if (strcmp(entry->mot,word) == 0)
				{
					// yes !
					printf("'%s' Matched '%s' keyword - applying to stack...\n",entry->mot,entry->description);
					matchedAnyKeywords = 1;
					// run the code associated with the keyword in our dictionary - this will now call one of the dictionary defined functions above 
					entry->code();
				}
			}

			// if we didn't find a match this isn't a dictionary keyword and has to be pushed onto the stack
			if (matchedAnyKeywords == 0)
			{
				printf("Pushing %s onto stack\n",argv[i]);

				StackElement *currentStack = stack;
				
				// allocate space for a new stack element	
				StackElement *newStackElement = malloc(sizeof(StackElement)*sizeof(char));
				// initialise with the parameter
				newStackElement->mot = argv[i];
				newStackElement->next = stack;   // link to the previous top of the stack
				stack = newStackElement;         // and make the 'stack' pointer the current element (last element added is always on top)
			}

		}

		// show the stack at the end
		printf("\n\nResulting Stack:");
		StackElement *top = stack;
		while (top)
		{
			printf(" %s",top->mot);
			top = top->next;
		}
		printf("\n\n");

		// free up the memory you allocated (at least some of it...)
	}

}
