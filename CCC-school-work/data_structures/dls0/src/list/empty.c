#include "list.h"

//////////////////////////////////////////////////////////////////////
//
//     empty() - a list library function to clear an existing list of
//               any and all of its component nodes (deallocate them).
//               The list itself continues to exist, but is in an
//               empty state following the successful call to
//               empty().
//
//               be sure to utilize existing list and node library
//               functions to facilitate your implementation. Do NOT
//               reinvent the wheel.
//
//  status code: this function can generate the following status code
//                 DLL_SUCCESS: everything went according to plan
//                 DLL_EMPTY:   list is now empty (normal operation)
//                 DLL_NULL:    *myList is NULL
//                 DLL_ERROR:   a failure was encountered, NULL
//                 DLL_INVALID: invalid condition (myList NULL)
//
//               as with the other functions, you may use no more
//               than one return() statement per function.
//
//               do not count; navigate by comparison
//
code_t empty(List ** myList)
{
	//
	// As in all other status code functions, initialize code to
	// dll_error incase program runs into an error down the line
	// set tmp and tmp2 pointers for traversing the list
	//
	code_t status = DLL_ERROR;
	Node *tmp = NULL;
	Node *tmp2 = NULL;

	//
	// before emptying the list, check that list exists and is not null.  If
	// these conditions are met, there is a list that can be emptied in the
	// first place
	//
	if (myList != NULL)
	{
		if (*myList != NULL)
		{
			if ((*myList)->engine != NULL)
			{
				//
				// Traverse list and empty it.  Free each node
				//
				tmp = (*myList)->engine;
				while (tmp != NULL)
				{
					tmp2 = tmp;
					tmp = tmp->to;
					tmp2->fro = NULL;
					tmp2->to = NULL;
					free(tmp2);
					tmp2 = NULL;
				}
				(*myList)->engine = NULL;
				(*myList)->caboose = NULL;

				//
				// Once successfully deallocated, make sure list is empty by calling
				// mklist
				//
				mklist(myList);
				status = DLL_SUCCESS | DLL_EMPTY;
			}
			//
			// Return success and empty status code since the goal is to have an
			// empty list by the end of implementation
			//
			else
				status = DLL_SUCCESS | DLL_EMPTY;
		}
		//
		// If list is null, empty cannot be called, return NULL error
		//
		else
			status = status | DLL_NULL;
	}
	//
	// If list does not exist, return invalid status code
	//
	else
		status = status | DLL_INVALID;

	return (status);
}
