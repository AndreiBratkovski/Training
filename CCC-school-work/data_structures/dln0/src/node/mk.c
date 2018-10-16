#include "node.h"

//////////////////////////////////////////////////////////////////////
//
//    mknode() - a node library function to allocate and initialize
//               a new node (to provided value).
//
// status codes:
//               DLN_SUCCESS:       no problems encountered
//               DLN_MALLOC_FAIL:   error on creation
//               DLN_ALREADY_ALLOC: already exists
//               DLN_NULL:          node is in NULL state
//               DLN_ERROR:         some error occurred
//               DLN_INVALID:       invalid use (NULL pointer)
//
//   suggestion: be sure to error check any allocation or query of
//               external resources; limit initialization steps to
//               only be performed in the allocation was successful.
//
//         NOTE: you are to have only ONE return statement for this
//               entire function. Change the existing one as needed.
//
//               if node is not in valid state, node should be set
//               to NULL.
//
code_t mknode(Node ** newNode, char info)
{
	//
	// Initialize status code as ERROR.  Will be altered or added to later in program
	//
	code_t status = DLN_ERROR;

	//
	// If new Node is NULL or UNDEFIND, the pointer use is invalid
	//
	if (newNode == NULL || newNode == UNDEFINED)
	{
		status = status | DLN_INVALID;
	}

	//
	// If the newNode is pointing to NULL, it is ready to be allocated
	//
	else if ((*newNode) == NULL)
	{
		*newNode = (Node *) malloc(sizeof(Node));
		(*newNode)->to = NULL;
		(*newNode)->fro = NULL;
		(*newNode)->VALUE = info;

		//
		// If allocation fails, the newNode is pointed at NULL
		// return Null node status code, otherwise, it was a successful
		// allocation
		//
		if ((*newNode) == NULL)
			status = status | DLN_NULL;
		else
			status = DLN_SUCCESS;
	}

	//
	// If none of the above conditions are met, the node is already
	// alllocated. Return allocated status code
	//
	else
		status = status | DLN_ALREADY_ALLOC;

	return (status);
}
