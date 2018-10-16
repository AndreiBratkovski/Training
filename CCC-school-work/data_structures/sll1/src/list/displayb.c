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
	int increment = 0;
	int position;

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

	else
	{
		//
		// Set position of tmp at the end of the list
		//
		position = getpos(myList, myList->caboose);
		tmp = setpos(myList, position);

		//
		// print out NULL pointer at the end of list
		//
		fprintf(stdout, "NULL <- ");

		//
		// iterate through list and display contents backwards
		// iteration goes backwards because we are decrementing the position
		//
		for (increment = position; increment >= 0; increment--)
		{
			tmp = setpos(myList, increment);
			if (mode == 0 && increment != 0)
			{
				fprintf(stdout, "%d <- ", tmp->contents);
			}
			else if (mode == 1 && increment != 0)
			{
				fprintf(stdout, "[%d] %d <- ", increment,
					tmp->contents);
			}

			//
			// When reaching the end of the list, reformat so that the 
			// arrow is not printed and there is a new line
			//
			else
			{
				if (mode == 0)
				{
					fprintf(stdout, "%d\n", tmp->contents);
				}
				else if (mode == 1)
				{
					fprintf(stdout, "[%d] %d\n", increment,
						tmp->contents);
				}
			}
		}

	}
}
