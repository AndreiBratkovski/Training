#include <stdio.h>
#include "list.h"

//////////////////////////////////////////////////////////////////////
//
// displayb() - display the list in a reversed orientation, also
//              with or without positional values (as indicated
//              by the mode parameter).
//
//       modes: 0 display the list backward, no positional values
//              1 display the list backward, with positional values
//     
//        note: positional values are indexed starting from 0
//     
//    behavior: on a NULL list, output "NULL"
//              if list is UNDEFINED, output "UNDEFINED"
//              on an EMPTY list, output "NULL <-"
//              on error (invalid mode): MOD by 2 and do the result
//                 (or the logical equivalent)
//
//      format: output is to be on a single line, with node values
//              space-padded. and separated by "<-" sequences, flush
//              against the left margin, of the forms:
//
//   backwards:   NULL <- 9 <- 7 <- 6 <- 4
//
//              or, if being displayed with node positions:
//
//   backwards:   NULL <- [3] 9 <- [2] 7 <- [1] 6 <- [0] 4
//
//        note: ALL output ends with a newline character
//
void displayb(List * myList, int mode)
{
	//
	// initialize temporary node to traverse list and record contents
	// initialize listArray to keep track of list contents. List array can be
	// as large as we want it malloc'd, but for testing purposes it is limited to 25
	//
	Node *tmp;
	int arrayCounter;

	char listArray[25];

	arrayCounter = 0;
	int increment = 0;

	//
	// if List is NULL, return NULL
	//
	if (myList == NULL)
	{
		fprintf(stdout, "NULL\n");
		fflush(stdout);
	}

	//
	// if List is Undefined, return UNDEFINED
	//
	else if (myList == UNDEFINED)
	{
		fprintf(stdout, "UNDEFINED\n");
		fflush(stdout);
	}

	//
	// if List is empty, return NULL <-
	//
	else if (myList->engine == NULL)
	{
		tmp = myList->engine;
		fprintf(stdout, "NULL <-\n");
		fflush(stdout);
	}
	//
	// Display list without positional values
	// traverse list and record values into list array
	// print listArray contents backwards 
	//
	else if (mode == 0)
	{
		fprintf(stdout, "NULL <- ");
		tmp = myList->engine;

		while (tmp != NULL)
		{
			listArray[arrayCounter] = tmp->contents;
			arrayCounter++;
			tmp = tmp->to;
		}
		//
		// Iterate over listArray backwards, and print reseults
		//
		for (increment = arrayCounter - 1; increment >= 0; increment--)
		{
			if (increment != 0)
			{
				fprintf(stdout, "%d <- ", listArray[increment]);
			}
			else
			{
				fprintf(stdout, "%d\n", listArray[increment]);
			}
		}
		fflush(stdout);

	}

	//
	// Display list with positional values
	// traverse list and record values into list array
	// print listArray contents backwards
	//
	else if (mode == 1)
	{
		fprintf(stdout, "NULL <- ");
		tmp = myList->engine;

		//
		// Build up list array with list node contents
		//
		while (tmp != NULL)
		{
			listArray[arrayCounter] = tmp->contents;
			arrayCounter++;
			tmp = tmp->to;
		}
		//
		// Iterate over listArray Backwards, and print results include positional values
		//
		for (increment = arrayCounter - 1; increment >= 0; increment--)
		{
			if (increment != 0)
			{
				fprintf(stdout, "[%d] %d <- ", increment,
					listArray[increment]);
			}
			else
			{
				fprintf(stdout, "[%d] %d\n", increment,
					listArray[increment]);
			}
		}
		fflush(stdout);

	}
}
