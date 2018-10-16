#include "tree.h"

//////////////////////////////////////////////////////////////////////
//
//searchtree()- a tree library utility function to locate a node in
//              an existing tree by value it contains.
//
//        note: searchtree() focuses on the actual content of what
//              is in the nodes, setting a (double) pointer to the
//              first node that contains the searchVal (from the
//              root of the tree, if *match is initially NULL, or
//              from the point in the tree that *match points).
//
//              the tree should not be modified as a result of
//              performing this action. Any matched nodes remain in
//              the tree, unmodified.
//
// status code: this function generates the following status codes:
//                DLT_SUCCESS:     match found
//                DLT_EMPTY:       no matches found (or tree empty)
//                DLT_NULL:        tree is in NULL state
//                DLT_FAIL:        an error has taken place (tree
//                                 is NULL or EMPTY).
//
//              you are to have only ONE return statement for this
//              entire function. Change the existing one as needed.
//
code_t searchtree(Tree * myTree, Node ** match, sc searchVal)
{
	//
	// Initialize error status code incase of running into a problem
	// in the program when searching the tree.  Create a tmp Node for
	// traversing the tree
	//
	code_t status = DLT_ERROR;
	Node *tmp = NULL;

	//
	// If tree does not exist, return a NULL status code because we cannot
	// traverse a non existant tree
	//
	if (myTree == NULL)
		status = status | DLT_NULL;

	//
	// If tree is empty, return empty status code ( if root is null )
	//
	else if (myTree->root == NULL)
		status = status | DLT_EMPTY;

	//
	// If tree is not empty, use tmp variable to traverse tree until
	// searchVal is found in the current node. If it is found, set match
	// to that node, otherwise match will remain unloved and left alone
	// as an empty pointer
	//
	else if (myTree->root != NULL)
	{
		status = DLT_SUCCESS;
		tmp = myTree->root;
		while (tmp != NULL)
		{
			if (tmp->VALUE == searchVal)
			{
				*match = tmp;
			}
			if (searchVal > tmp->VALUE)
				tmp = tmp->to;
			else if (searchVal <= tmp->VALUE)
				tmp = tmp->fro;

		}
		if (*match == NULL)
			status = DLT_EMPTY;
	}

	else if (*match == NULL)
		status = DLT_EMPTY;

	return (status);
}
