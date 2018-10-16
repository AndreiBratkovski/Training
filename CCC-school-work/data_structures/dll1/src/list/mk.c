#include "list.h"

//////////////////////////////////////////////////////////////////////
//
//  mklist() - allocate, initialize, and return a pointer to the
//             newly allocated and initialized list struct.
//
//status code: this function generates the following status codes:
//               DLL_SUCCESS:       no problems encountered
//               DLL_EMPTY:         result of normal operation
//               DLL_MALLOC_FAIL:   error on creation
//               DLL_ALREADY_ALLOC: list pointer already allocated
//               DLL_NULL:          list remains in NULL state
//               DLL_ERROR:         an error has taken place
//
//             be sure you perform any necessary error checking,
//             and that any and all struct members are appropriately
//             initialized.
//
//             as with the other functions, you may use no more
//             than one return() statement per function.
//
code_t mklist(List ** newList)
{
	//
	// Initialize code to error
	//
	code_t status = DLL_ERROR;

	//
	// If list is NULL or does not exist, return invalid code
	//
	if (newList == NULL || newList == UNDEFINED)
		status = status | DLL_INVALID;

	//
	// Else, allocate a new list
	//
	else if ((*newList) == NULL)
	{
		*newList = (List *) malloc(sizeof(List));
		(*newList)->engine = (Node *) malloc(sizeof(Node));
		(*newList)->engine = NULL;
		(*newList)->caboose = (Node *) malloc(sizeof(Node));
		(*newList)->caboose = NULL;

		//
		// If list is NULL after allocation
		//
		if ((*newList) == NULL)
			status = status | DLL_NULL;
		//
		// If List allocation is successful, list is empty
		//
		else
			status = DLL_EMPTY | DLL_SUCCESS;
	}

	//
	// If none of the above conditions are met, the list is already allocated
	//
	else
		status = status | DLL_ALREADY_ALLOC;

	return (status);
}
