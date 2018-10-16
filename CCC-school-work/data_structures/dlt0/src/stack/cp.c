#include "stack.h"

//////////////////////////////////////////////////////////////////////
//
//   cpstack() - duplicate a given stack (especially the state of
//               its contents), in a new stack.
//
//     behavior: in the event of an existing yet non-NULL newStack,
//               just fall though (do nothing), and generate the
//               appropriate status code(s).
//
//               be sure to utilize existing list and stack library
//               functions to facilitate your implementation. Do NOT
//               reinvent the wheel.
//
//               the top of the stack should follow the last node in
//               its underlying list.
//
//  status code: this function can generate the following status code
//                 DLL_SUCCESS:     normal operation
//                 DLL_EMPTY:       stack data element is empty
//                 DLS_SUCCESS:     normal operation
//                 DLS_CREATE_FAIL: *newStack already exists
//                 DLS_EMPTY:       stack is EMPTY
//                 DLS_NULL:        stack is NULL
//                 DLS_ERROR:       a failure was encountered
//                 DLS_INVALID:     stack does not exist
//
//         note: as with the other functions, you may use no more
//               than one return() statement per function.
//
//               do not count; navigate by comparison
//
code_t cpstack(Stack * curStack, Stack ** newStack)
{
	//
	// Initialize status code error as DLS_ERROR incase we run into
	// copying error later on
	//
	code_t status = DLS_ERROR;

	//
	// Initialize new list as temporary list for copying curStack's list later
	// and pointing newStack's data to it
	//
	List *newList = NULL;

	//
	// If current stack does not exist, return NULL stack error code, cannot copy
	//
	if (curStack == NULL)
		status = status | DLS_NULL;

	//
	// if newStack does not exist, return INVALID status code.  Cannot copy over to
	// nothing
	//
	else if (newStack == NULL)
		status = status | DLS_INVALID;

	//
	// If newstack pointer is empty and curstack exists, we can copy the stack
	//
	else if (curStack != NULL && *newStack == NULL)
	{
		if (curStack->data != NULL)
		{
			//
			// If current stack is empty, make a newstack, copy the list data from
			// current stack over to new stack, and point newstacks top pointer to
			// its data caboose. Now we have a stack copy
			//
			if (curStack->data->engine != NULL)
			{
				mkstack(newStack, curStack->size);

				cplist(curStack->data, &newList);
				(*newStack)->data = newList;
				(*newStack)->top = newList->caboose;

				status = DLS_SUCCESS | DLL_SUCCESS;
			}
			//
			// Empty stack Null destination. Create a newstack since current stack is
			// empty, and return status code letting user know they received a new
			// empty stack. Essentially calling mkstack with the same size as curStack
			//
			else
			{
				mkstack(newStack, curStack->size);
				status =
				    DLS_SUCCESS | DLS_EMPTY | DLL_EMPTY |
				    DLL_SUCCESS;
			}
		}
	}
	//
	// If newStack already exists return a CREATE FAIL. stack must be a NULL pointer
	//
	else if ((*newStack)->data->engine == NULL)
		status = status | DLS_CREATE_FAIL;

	return (status);
}
