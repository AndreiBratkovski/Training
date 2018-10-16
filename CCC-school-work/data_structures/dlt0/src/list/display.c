#include <stdio.h>
#include "list.h"

//////////////////////////////////////////////////////////////////////
//
//  display() - display the list according to mode(s).
//
//       modes: DISPLAY_FORWARD:   display the list forward
//              DISPLAY_NOPOSVALS: display with no positional values
//              DISPLAY_NOASCII:   display numeric values
//              DISPLAY_SEPS:      display separators between values
//              DISPLAY_POSVALS:   display with positional values
//              DISPLAY_BACKWARD:  display the list backward
//              DISPLAY_ASCII:     display ASCII characters
//              DISPLAY_NOSEPS:    do not display separators
//     
//        note: positional values are indexed from 0
//     
// status code: this function can generate the following status codes
//                DLL_SUCCESS:     normal (not NULL, EMPTY, ERROR)
//                DLL_NULL:        list is NULL
//                DLL_EMPTY:       list is EMPTY
//                DLL_ERROR:       non-populated list
//
//    behavior: on a NULL list,    output "(NULL)"
//              on an EMPTY list,  output "-> NULL" or "(EMPTY)" if
//                                 in ASCII mode
//              invalid mode:      MOD by 16 and do the result
//
//      format: output is to be against the left margin, on a single
//              line, ending with a newline character
//
//              DISPLAY_NOSEPS being set will remove all separators
//              and spaces from output, and positional values being
//              displayed change from "[#] " to "#:"
//
//              With DISPLAY_ASCII, separators are commas ', ', but
//              omitting the trailing comma at the end (there is no
//              terminating "NULL" displayed either)
//
//              Please see unit test output for examples. Note that
//              some mode combinations are nonsensical.
//
code_t display(List * myList, int mode)
{
	//
	// I call this the gourmet of list display functionality.  Displaying now has 
	// various types of options based on status codes given.
	//
	// *Note : Values are checked based upon their bitwise configurations.  Due to 
	//      multiple status codes being set to 0, program needs to single out bitwise operations
	//      with nonzero values first in order to check in the correct order

	//
	// Initialize status code to ERROR incase program runs into any problems and needs a
	// status code output. Initialize tmp variable for traversing the list and a posCounter
	// variable for counting the list indices
	//
	code_t status = DLL_ERROR;
	Node *tmp = NULL;
	int posCounter = 0;

	//
	// Check if List is NULL, if so, display (NULL)
	//
	if (myList == NULL)
	{
		status = DLL_NULL;
		fprintf(stdout, "(NULL)\n");
	}

	//
	// If list is UNDEFINED, return INVALID list code to let user know that list
	// does not exist
	//
	else if (myList == UNDEFINED)
		status = status | DLL_INVALID;

	//
	// If list is NOT null, it is either a populated list or an empty list, program now needs
	// to check the state of the list contents
	//
	else if (myList != NULL)
	{
		//
		// If the list is NOT empty, then display function can begin checking status codes to see
		// what form of list contents user wants displayed
		//
		if (myList->engine != NULL)
		{
			//
			// Display posvals. Checking for POSVALS first due to it being a bitwise value grater than
			// 0. That way the program doesn't skip it due to being a non-value
			//
			if ((mode & DISPLAY_POSVALS) == DISPLAY_POSVALS)
			{

				tmp = myList->engine;
				//
				// Backwards - Check if displaying list forward or backwards with positional values
				//
				if ((mode & DISPLAY_BACKWARD) ==
				    DISPLAY_BACKWARD)
				{
					//
					// Count list to keep track of indices later
					//
					while (tmp != NULL)
					{
						posCounter++;
						tmp = tmp->to;
					}
					//
					// Iterate backwards over the list due to backwards display status
					//
					tmp = myList->caboose;
					posCounter--;
					do
					{
						// ASCII - Check if list is being displayed in ASCII or VALUES
						if ((mode & DISPLAY_ASCII) ==
						    DISPLAY_ASCII)
						{
							//
							// NO SEPARATORS- Check if list does not include separators
							//
							if ((mode &
							     DISPLAY_NOSEPS) ==
							    DISPLAY_NOSEPS)
								fprintf(stdout,
									"%d:%c",
									posCounter,
									tmp->
									VALUE);
							//
							// SEPARATORS
							//
							else if (tmp->fro !=
								 NULL)
								fprintf(stdout,
									"[%d] '%c', ",
									posCounter,
									tmp->
									VALUE);
							else
								fprintf(stdout,
									"[%d] '%c'",
									posCounter,
									tmp->
									VALUE);
						}
						//
						// NO ASCII - check if list is being displayed in VALUES
						//
						else
						{
							//
							// NO SEPARATORS - Check if list does not include separators
							//
							if ((mode &
							     DISPLAY_NOSEPS) ==
							    DISPLAY_NOSEPS)
								fprintf(stdout,
									"%d:%d",
									posCounter,
									tmp->
									VALUE);
							//
							// SEPARATORS
							//
							else
								fprintf(stdout,
									"[%d] %d -> ",
									posCounter,
									tmp->
									VALUE);
						}
						//
						// Iterate backwards over list to print values one at a time
						//
						tmp = tmp->fro;
						posCounter--;
					}
					while (tmp != NULL);

					//
					// If displaying values, function makes sure to tag NULL at the end, if not,
					// function returns a new line
					//
					if ((mode & DISPLAY_ASCII) !=
					    DISPLAY_ASCII)
						fprintf(stdout, "NULL\n");
					else
						fprintf(stdout, "\n");
				}
				//
				// Display FORWARD POS VALS
				//
				else
				{

					do
					{
						//
						// ASCII - Check if displaying Values or ASCII
						//
						if ((mode & DISPLAY_ASCII) ==
						    DISPLAY_ASCII)
						{
							//
							// NO SEPARATORS - Check if displaying with or without separators
							//
							if ((mode &
							     DISPLAY_NOSEPS) ==
							    DISPLAY_NOSEPS)
								fprintf(stdout,
									"%d:%c",
									posCounter,
									tmp->
									VALUE);
							else if (tmp->to !=
								 NULL)
								fprintf(stdout,
									"[%d] '%c', ",
									posCounter,
									tmp->
									VALUE);
							//
							// SEPARATORS
							//
							else
								fprintf(stdout,
									"[%d] '%c'",
									posCounter,
									tmp->
									VALUE);
						}
						//
						// NO ASCII - Check if displaying VALUES
						//
						else
						{
							//
							// NO SEPARATORS - Check if displaying without separators
							//
							if ((mode &
							     DISPLAY_NOSEPS) ==
							    DISPLAY_NOSEPS)
								fprintf(stdout,
									"%d:%d",
									posCounter,
									tmp->
									VALUE);
							//
							// SEPARATORS
							//
							else
								fprintf(stdout,
									"[%d] %d -> ",
									posCounter,
									tmp->
									VALUE);
						}
						//
						// Iterate over list and increase index count
						//
						tmp = tmp->to;
						posCounter++;
					}
					while (tmp != NULL);

					//
					// As above, display newline or NULL at the end of the list if in ASCII or VALUES respectively
					//
					if ((mode & DISPLAY_ASCII) !=
					    DISPLAY_ASCII)
						fprintf(stdout, "NULL\n");
					else
						fprintf(stdout, "\n");
				}

			}
			//
			// NO POS VALS - Check if list display function wants to display whatever list without position values.  This is the
			// 2nd largest check
			//
			else if ((mode & DISPLAY_NOPOSVALS) ==
				 DISPLAY_NOPOSVALS)
			{
				tmp = myList->engine;
				//
				// Backwards NO POS VALS- Various versions of displaying list backwards
				//
				if ((mode & DISPLAY_BACKWARD) ==
				    DISPLAY_BACKWARD)
				{
					//
					// count list
					//
					while (tmp != NULL)
					{
						posCounter++;
						tmp = tmp->to;
					}
					tmp = myList->caboose;
					posCounter--;
					do
					{
						//
						// ASCII- Check if displaying backwards in ASCII
						//
						if ((mode & DISPLAY_ASCII) ==
						    DISPLAY_ASCII)
						{
							//
							// NO SEPARATORS
							//
							if ((mode &
							     DISPLAY_NOSEPS) ==
							    DISPLAY_NOSEPS)
								fprintf(stdout,
									"%c",
									tmp->
									VALUE);
							//
							// With SEPARATORS
							//
							else if (tmp->fro !=
								 NULL)
								fprintf(stdout,
									"'%c', ",
									tmp->
									VALUE);
							else
								fprintf(stdout,
									"'%c'",
									tmp->
									VALUE);
						}
						//
						// NO ASCII- Check if displaying backwards in VALUES
						//
						else
						{
							//
							// NO SEPARATORS
							//
							if ((mode &
							     DISPLAY_NOSEPS) ==
							    DISPLAY_NOSEPS)
								fprintf(stdout,
									"%d",
									tmp->
									VALUE);
							//
							// SEPARATORS
							//
							else
								fprintf(stdout,
									"%d -> ",
									tmp->
									VALUE);
						}
						//
						// Iterate over list one element at a time and decrement list counter
						//
						tmp = tmp->fro;
						posCounter--;
					}
					while (tmp != NULL);

					//
					// Display NULL or line return depending on if ASCII or VALUES
					//
					if ((mode & DISPLAY_ASCII) !=
					    DISPLAY_ASCII)
						fprintf(stdout, "NULL\n");
					else
						fprintf(stdout, "\n");
				}
				//
				// Display list FORWARDS with NO POS VALS
				//
				else
				{
					do
					{
						//
						// ASCII - Check if displaying forwards in ascii
						//
						if ((mode & DISPLAY_ASCII) ==
						    DISPLAY_ASCII)
						{
							//
							// SEPARATORS- Check if displaying forwards with or without separators
							//
							if ((mode &
							     DISPLAY_NOSEPS) ==
							    DISPLAY_NOSEPS)
								fprintf(stdout,
									"%c",
									tmp->
									VALUE);
							else if (tmp->to !=
								 NULL)
								fprintf(stdout,
									"'%c', ",
									tmp->
									VALUE);
							else
								fprintf(stdout,
									"'%c'",
									tmp->
									VALUE);
						}
						//
						// NO ASCII - Check if displaying forwards in VALUES
						//
						else
						{
							//
							// NO SEPARATORS 
							//
							if ((mode &
							     DISPLAY_NOSEPS) ==
							    DISPLAY_NOSEPS)
								fprintf(stdout,
									"%d",
									tmp->
									VALUE);
							//
							// SEPARATORS
							//
							else
								fprintf(stdout,
									"%d -> ",
									tmp->
									VALUE);
						}
						//
						// Iterate over list one at a time and increase list size counter
						//
						tmp = tmp->to;
						posCounter++;
					}
					while (tmp != NULL);

					//
					// Check if ending list with NULL or line return, depending on
					// if it is in ASCII or VALUES
					//
					if ((mode & DISPLAY_ASCII) !=
					    DISPLAY_ASCII)
						fprintf(stdout, "NULL\n");
					else
						fprintf(stdout, "\n");

				}

			}
			//
			// If list is displayed, return list success value letting use know that the
			// function worked properly
			//
			status = DLL_SUCCESS;
		}

		//
		// Check if list is empty , and print various forms of empty list status codes
		// (EMPTY) if in ASCII and -> NULL if in VALUES.  If status code also asks for no
		// separators, return a line return for ASCII and NULL for values.  These leaves out all
		// possible separators
		//
		else
		{
			status = DLL_EMPTY;
			if ((mode & DISPLAY_ASCII) == DISPLAY_ASCII)
			{
				if ((mode & DISPLAY_NOSEPS) == DISPLAY_NOSEPS)
					fprintf(stdout, "\n");
				else
					fprintf(stdout, "(EMPTY)\n");
			}
			else
			{
				if ((mode & DISPLAY_NOSEPS) == DISPLAY_NOSEPS)
					fprintf(stdout, "NULL\n");
				else
					fprintf(stdout, "-> NULL\n");
			}
		}

	}

	return (status);
}
