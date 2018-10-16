#include "node.h"

//////////////////////////////////////////////////////////////////////
//
//    rmnode() - a node library function to clear and deallocate an 
//               existing node
//
// status codes:
//               DLN_SUCCESS: no problems encountered
//               DLN_NULL:    node in NULL state
//               DLN_ERROR:   some error occurred
//               DLN_INVALID: invalid use (NULL pointer)
//
//   suggestion: avoid deallocating an already NULL or non-existant
//               node; do proper error checking!
//
//         NOTE: you are to have only ONE return statement for this
//               entire function. Change the existing one as needed.
//
//               be sure to explicitly set the node to NULL after
//               performing all necessary steps (but don't JUST
//               set it NULL- clear and deallocate first).
//
code_t rmnode(Node ** curNode)
{
	//
	// Initialize status code as ERROR, will be altered in later logic
	//
	code_t status = DLN_ERROR;

	//
	// if the current node is NULL or UNDEFINED, we have an error. return
	// invalid status code. Nothing to deallocate
	//
	if (curNode == NULL || curNode == UNDEFINED)
		status = status | DLN_INVALID;

	//
	// If the node is already in a NULL state, return the NULL status code
	// to let user know that node is in a NULL state.
	//
	else if (*curNode == NULL)
		status = status | DLN_NULL;

	//
	// If the node has "something" in it, free the node and point it at NULL.
	// The status is a successful deallocation and the node is in a null state.
	//
	else
	{
		free(*curNode);
		*curNode = NULL;
		status = DLN_SUCCESS | DLN_NULL;
	}

	return (status);
}
