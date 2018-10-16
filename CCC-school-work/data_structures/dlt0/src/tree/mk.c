#include "tree.h"

//////////////////////////////////////////////////////////////////////
//
//  mktree() - allocate, initialize, and return a pointer to the newly
//             created tree.
//
//       note: the second parameter is to be the created tree's
//             maximum height (bound).
//
//     height: a height of 0 indicates an unbounded tree
//             > 0 will limit the total number of levels in the tree
//
//status code: this function can generate the following status codes:
//                 DLT_SUCCESS:     no problems encountered
//                 DLT_EMPTY:       result of normal operation
//                 DLT_CREATE_FAIL: error on creation (malloc-
//                                  related or already exists)
//                 DLT_NULL:        tree remains in NULL state
//                 DLT_FAIL:        an error has taken place
//
//             you are to have only ONE return statement for this
//             entire function. Change the existing one as needed.
//
code_t mktree(Tree ** newTree, uc height)
{
	//
	// Initialize error codes with DLT_ERROR incase program
	// runs into errors  during creation
	//
	code_t status = DLT_ERROR;

	//
	// If newTree doesn't exist, return NULL status code. Cannot make
	// a tree out of nothing
	//
	if (newTree == NULL || newTree == UNDEFINED)
		status = status | DLT_NULL;

	//
	// If newTree exists but is NULL, it can now be created. allocate memory
	// for newTree's root, and the newTree Struct. You now have a tree
	//
	else if ((*newTree) == NULL)
	{
		*newTree = (Tree *) malloc(sizeof(Tree));
		(*newTree)->root = (Node *) malloc(sizeof(Node));
		(*newTree)->root = NULL;

		//
		// If NewTree is still null, it is a creation error. Return null
		// status code
		//
		if ((*newTree) == NULL)
			status = status | DLT_NULL;

		//
		// After successful tree completion, return successful tree
		// status codes and Initialize height to given height in function
		// call
		//
		else
		{
			status = DLT_EMPTY | DLT_SUCCESS;
			(*newTree)->max_height = height;
		}
	}

	//
	// If New tree is already an allocated tree, return a create fail.  Can't
	// make a new tree out of an existing tree
	//
	else
		status = status | DLT_CREATE_FAIL;

	return (status);
}
