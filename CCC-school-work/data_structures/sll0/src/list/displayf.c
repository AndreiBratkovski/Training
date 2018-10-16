#include <stdio.h>
#include "list.h"

//////////////////////////////////////////////////////////////////////
//
// displayf() - display the list in a specified orientation, also
//                        with or without positional values (as indicated
//                        by the mode parameter).
//
//         modes: 0 display the list forward, no positional values
//                        1 display the list forward, with positional values
//       
//              note: positional values are indexed starting from 0
//       
//      behavior: on a NULL list, output "NULL"
//                        if list is UNDEFINED, output "UNDEFINED"
//                        on an EMPTY list, output "-> NULL"
//                        on error (invalid mode): MOD by 2 and do the result
//                               (or the logical equivalent)
//
//        format: output is to be on a single line, with node values
//                        space-padded. and separated by "->" sequences, flush
//                        against the left margin, of the forms:
//
// for forward:   val0 -> val1 -> val2 -> ... -> valN-1 -> valN -> NULL
//
//                        or, if being displayed with node positions:
//
// for forward: [0] val0 -> [1] val1 -> ... -> [N-1] valN-1 -> [N] valN -> NULL
//
//              note: ALL output ends with a newline character
//
void displayf(List * myList, int mode)
{
	// 
	// Declare counter variables and tmp node for traversing list
	//
	int showPos = 1;
	int noPos = 0;
	int posCounter = 0;
	Node *tmp;

	//
	//  if myList is NULL or UNDEFINED, print NULL or UNDEFINED
	//
	if (myList == UNDEFINED)
	{
		fprintf(stdout, "UNDEFINED\n");
	}

	if (myList == NULL)
	{
		fprintf(stdout, "NULL\n");
	}

	//
	// if List exists, traverse list and print out list contents
	//
	if (myList != NULL && myList != UNDEFINED)
	{
		if (myList->engine == NULL && myList->caboose == NULL)
		{
			fprintf(stdout, "-> NULL\n");
		}

		//
		// Print out node contents with position numbers
		//
		else if (mode == showPos)
		{
			tmp = myList->engine;
			do
			{
				fprintf(stdout, "[%d] %d -> ", posCounter,
					tmp->contents);
				posCounter++;
				tmp = tmp->to;
			}
			while (tmp != NULL);

			fprintf(stdout, "NULL\n");
		}

		//
		// Print out node contents without positions
		//
		else if (mode == noPos)
		{
			tmp = myList->engine;
			do
			{
				fprintf(stdout, "%d -> ", tmp->contents);
				tmp = tmp->to;
			}
			while (tmp != NULL);

			fprintf(stdout, "NULL\n");
		}
	}
}
