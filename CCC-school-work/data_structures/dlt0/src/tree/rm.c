#include "tree.h"

//////////////////////////////////////////////////////////////////////
//
//   rmtree() - unset, nullify members, and de-allocate the given 
//              tree.
//
//              be sure to utilize existing list and tree library
//              functions to facilitate your implementation.
//
// status code: this function can generate the following status codes
//                  DLT_SUCCESS: no problems encountered
//                  DLT_NULL:    normal operation
//                  DLT_FAIL:    error encountered (or tree was
//                               already NULL)
//
//        note: you are to have only ONE return statement for this
//              entire function. Change the existing one as needed.
//

//
// Recursive deallocation function to deallocate a binary tree
//
void deallocate(Node *);

code_t rmtree(Tree ** curTree)
{
	//
	// initialize status code to DLT_ERROR incase an error is run into
	// during tree deallocation. This is to let the user know if they run
	// into any problems, A tmp node is set to traverse the list for
	// deallocation
	//
	code_t status = DLT_ERROR;
	Node *tmp = NULL;

	//
	// If tree does not exist, nothing needs to be deallocated. Return
	// a NULL status code
	//
	if (curTree == NULL || *curTree == NULL)
		status = status | DLT_NULL;

	//
	// If tree is empty, free the tree pointer, set both the curtree
	// and curTree pointer to NULL, and return successful status code due
	// to free'd tree
	//
	else if ((*curTree)->root == NULL)
	{
		free(*curTree);
		*curTree = NULL;
		curTree = NULL;
		status = DLT_SUCCESS | DLT_NULL;
	}
	//
	// Removal of populated tree logic.
	//
	else
	{
		//
		// Recursive deallocation of list.  Function recursively
		// removes/frees each node until the tree is empty.
		//
		tmp = (*curTree)->root;
		deallocate(tmp);

		//
		// Free the Tree pointer and set it to NULL, returning an
		// extinguished tree and success code
		//
		free(*curTree);
		*curTree = NULL;
		curTree = NULL;
		status = DLT_SUCCESS | DLT_NULL;
	}
	return (status);
}

//
// While the node is not null ( meaning when the tree is not empty ),
// function recursively iterates throughout the binary tree, deallocating
// each node
//
void deallocate(Node * node)
{
	if (node != NULL)
	{
		deallocate(node->fro);
		deallocate(node->to);
		free(node);
	}
}
