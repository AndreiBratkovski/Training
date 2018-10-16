#include <stdio.h>
#include "list.h"

//////////////////////////////////////////////////////////////////////
//
//  display() - display the list in a specified orientation, also
//              with or without positional values (as indicated
//              by the mode parameter).
//
//       modes: DISPLAY_FORWARD:   display the list forward
//              DISPLAY_NOPOSVALS: display with no positional values
//              DISPLAY_POSVALS:   display with positional values
//              DISPLAY_BACKWARD:  display the list backward
//     
//        note: positional values are indexed from 0
//     
// status code: this function can generate the following status codes
//                DLL_SUCCESS:     normal (not NULL, EMPTY, ERROR)
//                DLL_NULL:        list is NULL
//                DLL_EMPTY:       list is EMPTY
//                DLL_ERROR:       non-populated list
//
//    behavior: on a NULL list,    output: "(NULL)"
//              on an EMPTY list,  output: "-> NULL"
//              invalid mode:      MOD by # of modes and do result
//
//      format: output is to be on a single line, with node values
//              space-padded. and separated by "->" sequences, flush
//              against the left margin, of the forms:
//
// for forward: 0 -> 1 -> 2 -> ... -> N-1 -> N -> NULL
//
//   backwards: N -> N-1 -> ... -> 2 -> 1 -> 0 -> NULL
//
//              or, if being displayed with node positions:
//
// for forward: [0] 0 -> [1] 1 -> ... -> [N-1] N-1 -> [N] N -> NULL
//
//   backwards: [N] N -> [N-1] N-1 -> ... -> [1] 1 -> [0] 0 -> NULL
//
//        note: ALL output ends with a newline character
//
//        note: backwards output differs from that of singly-linked list
//              displayb(); with dll0, all display() output is universal
//              regardless of orientation.
//
//              if a mode of DISPLAY_POSVALS | DISPLAY_BACKWARD, you
//              WILL need to count up the number of nodes in the list;
//              this is expected, and shouldn't happen anywhere else.
//
code_t display(List * myList, int mode)
{
	//
	// Initialize tmp node, pos counter for counting the list positions
	// and status code to NULL list error
	//
	code_t status = DLL_ERROR;
	Node *tmp = NULL;
	int posCounter = 0;

	//
	// if MyList is NULL, return NULL list status code
	//
	if (myList == NULL)
	{
		fprintf(stdout, "NULL\n");
		status = DLL_NULL;
	}
	//
	// if Mylist is not NULL and not UNDEFINED, we can begin traversing the list to display it
	//
	if (myList != NULL && myList != UNDEFINED)
	{
		//
		// If myList is empty, return empty code and -> NULL
		//
		if (myList->engine == NULL && myList->caboose == NULL)
		{
			fprintf(stdout, "-> NULL\n");
			status = DLL_EMPTY;
		}
		// NOTE: Check DISPLAY_BACKWARD first so that the program can
		// bitwise check non zero data (DISPLAYBACKWARD) first
		//
		// Check if displaying position values display list forwards or
		// backwards without positional values
		//
		else if ((mode & DISPLAY_POSVALS) == DISPLAY_POSVALS)
		{
			tmp = myList->engine;

			//
			// Display list backwards with position values
			// set status code to SUCCESS
			//
			if ((mode & DISPLAY_BACKWARD) == DISPLAY_BACKWARD)
			{
				while (tmp != NULL)
				{
					posCounter++;
					tmp = tmp->to;
				}
				tmp = myList->caboose;
				posCounter--;
				do
				{
					fprintf(stdout, "[%d] %d -> ",
						posCounter, tmp->VALUE);
					tmp = tmp->fro;
					posCounter--;
				}
				while (tmp != NULL);

				fprintf(stdout, "NULL\n");
				status = DLL_SUCCESS;
			}

			//
			// Display list forwards with position values
			//
			else
			{
				tmp = myList->engine;
				do
				{
					fprintf(stdout, "[%d] %d -> ",
						posCounter, tmp->VALUE);
					tmp = tmp->to;
					posCounter++;
				}
				while (tmp != NULL);
				fprintf(stdout, "NULL\n");
				status = DLL_SUCCESS;
			}
		}
		//
		// Check if not displaying position values, display list forwards or
		// backwards without positional values, set status code to success
		//
		else if ((mode & DISPLAY_NOPOSVALS) == DISPLAY_NOPOSVALS)
		{
			if ((mode & DISPLAY_BACKWARD) == DISPLAY_BACKWARD)
				tmp = myList->caboose;
			else
				tmp = myList->engine;

			do
			{
				fprintf(stdout, "%d -> ", tmp->VALUE);

				if ((mode & DISPLAY_BACKWARD) ==
				    DISPLAY_BACKWARD)
					tmp = tmp->fro;
				else
					tmp = tmp->to;
			}

			while (tmp != NULL);
			fprintf(stdout, "NULL\n");
			status = DLL_SUCCESS;
		}

	}

	return (status);
}
