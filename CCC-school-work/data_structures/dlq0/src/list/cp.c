#include "list.h"

//////////////////////////////////////////////////////////////////////
//
//    cplist() - duplicate a given list (especially the state of
//               its contents), in a new list.
//
//               be sure to utilize existing list and node library
//               functions to facilitate your implementation. Do NOT
//               reinvent the wheel.
//
//  status code: this function can generate the following status code
//                 DLL_SUCCESS:       normal operation
//                 DLL_ALREADY_ALLOC: *newList already exists
//                 DLL_EMPTY:         cur & ending *newList are EMPTY
//                 DLL_NULL:          oldList or *newList are NULL
//                 DLL_ERROR:         an error was encountered
//                 DLL_INVALID:       newList doesn't exist
//
//               as with the other functions, you may use no more
//               than one return() statement per function.
//
//               do not count; navigate by comparison
//
code_t cplist(List * oldList, List ** newList)
{
	//
	// Initialize 3 tmp nodes and a DLL_ERROR status code before traversing
	// old list
	//
	Node *tmp = NULL;
	Node *tmp2 = NULL;
	Node *tmp3 = NULL;
	code_t status = DLL_ERROR;

	//
	// If newList is not NULL and not Undefined, then 
	// program can check for oldList before copying
	//
	if ((newList != NULL) && (newList != UNDEFINED)
	    && ((*newList) != UNDEFINED))
	{

		//
		// if Oldlist is NULL, then the copied list is NULL
		//
		if (oldList == NULL)
		{
			newList = NULL;
			status = status | DLL_NULL;
		}

		//
		// Else, if newList is NULL, and oldList is not NULL, program
		// can copy oldList
		//
		else if ((*newList) == NULL)
		{
			mklist(newList);
			if (oldList->engine != NULL)
			{
				tmp = oldList->engine;
				cpnode(tmp, &tmp2);
				(*newList)->engine = tmp2;
				(*newList)->caboose = tmp2;

				while (tmp->to != NULL)
				{
					tmp3 = tmp2->to;
					tmp = tmp->to;
					cpnode(tmp, &tmp3);
					tmp2 = tmp2->to;
					(*newList)->caboose = tmp2;
				}
				status = DLL_SUCCESS;
			}
			//
			// If oldlist is empty, copy was successful and
			// new list is empty as well
			//
			else
				status = DLL_EMPTY | DLL_SUCCESS;

		}
		//
		// If *newList is not NULL, then it is already allocated
		//
		else
			status = status | DLL_ALREADY_ALLOC;
	}

	//
	// If none of the above conditions are met, the newList pointer is either
	// Undefined or Null. In that case, we cannot copy a list.
	//
	else
		status = status | DLL_INVALID;

	return (status);
}
