#include "tree.h"

//////////////////////////////////////////////////////////////////////
//
//  cptree()   - duplicate a given tree (especially the state of
//               its contents), in a new tree.
//
//  status code: this function can generate the following status code
//                 DLT_SUCCESS:     normal operation
//                 DLT_CREATE_FAIL: *newTree already exists
//                 DLT_EMPTY:       curTree and *newTree are EMPTY
//                 DLT_NULL:        curTree or *newTree is NULL
//                 DLT_FAIL:        a failure was encountered
//
//         note: you are to have only ONE return statement for this
//               entire function. Change the existing one as needed.
//

//
// Prototype function declaration for recursive tree copying
// function
//
Node *copy(Node *);

code_t cptree(Tree * curTree, Tree ** newTree)
{
	//
	// Initialize error code as DLT_ERROR incase program runs into
	// problems during implementation. Set a current and tmp node pointer
	// for traversing the current tree
	//
	code_t status = DLT_ERROR;
	Node *current = NULL;
	Node *tmp = NULL;

	//
	// If current tree does not exist, current tree cannot be traversed or
	// copied over to a new tree, sor eturn a NULL tree error code
	//
	if (curTree == NULL)
		status = status | DLT_NULL;

	//
	// If tree is empty, create a new tree calling mktree function 
	//
	else if (curTree->root == NULL)
	{
		mktree(newTree, curTree->max_height);
		status = DLT_SUCCESS | DLT_EMPTY | DLL_EMPTY;
	}

	//
	// If tree is not empty and exists, create a newTree under the newTree
	// pointer, traverse the current tree, and copy it over recursively to the
	// new tree
	//
	else
	{
		mktree(newTree, curTree->max_height);

		if (curTree->root->to == NULL && curTree->root->fro == NULL)
		{
			current = curTree->root;
			mknode(&tmp, current->VALUE);
			addnode(newTree, tmp);
		}
		else
		{
			current = curTree->root;
			(*newTree)->root = copy(current);
		}
		status = DLT_SUCCESS;
	}

	return (status);
}

//
// Recursive copy function which traverses over the existing list,
// copies each node and adds it to its proper place in the new tree
// Each iteration returns the new node being placed
//
Node *copy(Node * root)
{
	Node *tmp = NULL;

	if (root != NULL)
	{
		mknode(&tmp, root->VALUE);
		tmp->fro = copy(root->fro);
		tmp->to = copy(root->to);
	}
	return tmp;
}
