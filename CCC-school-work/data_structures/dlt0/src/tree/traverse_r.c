#include "tree.h"

//////////////////////////////////////////////////////////////////////
//
//traverse_r()- a tree library utility function to walk through the 
//              tree, by order of the indicated traversal mode, and
//              to produce a list of all the nodes encountered, in 
//              the order they were encountered.
//
//        note: traverse_r() focuses on the actual content of what
//              is in the tree, setting a (double) pointer to a
//              list that contains the ordered content as it was
//              encountered in the tree. To avoid an error, the list
//              should be NULL (create it).
//
//              the tree should not be modified as a result of
//              performing this action.
//
//              the recursive implementation of traverse_r() will 
//              embody the conceptual elegance often found in
//              such solutions: shorter code, less detail-oriented,
//              and relying centrally and heavily on calling some
//              function again and again as the means of processing.
//              While you cannot alter the header file, you may want
//              to implement a custom more local function that this
//              traverse_r() function calls.
//
//              traverse_r() could be used as a prerequisite step 
//              before calling the list display() function.
//
// status code: this function generates the following status codes:
//                DLT_SUCCESS:     traverse successful
//                DLT_EMPTY:       tree is in EMPTY state
//                DLT_NULL:        tree is in NULL state
//                DLT_FAIL:        an error has taken place (tree
//                                 is NULL, list exists, bad mode).
//
//              you are to have only ONE return statement for this
//              entire function. Change the existing one as needed.
//

//
// The prototype function declarations for recursive traversal
// Each representing a recursive function for the different modes
// Note: My favorite traversal due to the cleanliness of recursive
// code in tree traversal
//
void inOrder(Node *, List **);
void preOrder(Node *, List **);
void postOrder(Node *, List **);

code_t traverse_r(Tree * myTree, List ** result, uc mode)
{
	//
	// initialize status code to ERROR code incase we run into
	// any problems during traversal
	//
	code_t status = DLT_ERROR;

	//
	// If myTree does not exist or result does not exist,
	// return NULL status code letting user know that tree does not
	// exist
	//
	if (myTree == NULL || result == NULL)
		status = status | DLT_NULL;

	//
	// If tree and result exists, prepare for checking for empty trees
	// or empty lists
	//
	else if (myTree != NULL && result != NULL)
	{
		if (myTree->root == NULL && *result != NULL)
		{
			if (mode > 2)
			{
				status = status | DLT_EMPTY;
				*result = NULL;
			}
			else if (*result != NULL)
			{
				status =
				    DLT_ERROR | DLT_EMPTY | DLL_ERROR |
				    DLL_ALREADY_ALLOC;
			}
			else
			{
				status =
				    DLT_EMPTY | DLT_SUCCESS | DLL_EMPTY |
				    DLL_SUCCESS;
				mklist(result);
			}
		}
		//
		// If result list is already allocated. Return error code that
		// list is allocated.  Result pointer needs to be null in order
		// to make a new list. 
		//
		else if (*result != NULL && mode <= 2)
			status = DLT_ERROR | DLL_ERROR | DLL_ALREADY_ALLOC;

		else if (mode > 2)
		{
			if (myTree->root != NULL)
				status = DLT_ERROR;
			else
				status = status | DLT_EMPTY;
		}
		//
		// Recursive traversal implementation here, now that all error checks
		// have been made
		//
		else
		{
			*result = NULL;
			mklist(result);

			if (mode == INORDER)	// InOrder
				inOrder(myTree->root, result);

			else if (mode == PREORDER)	// PreOrder
				preOrder(myTree->root, result);

			else if (mode == POSTORDER)	// PostOrder
				postOrder(myTree->root, result);

			if ((*result)->engine == NULL)
				status =
				    DLT_EMPTY | DLT_SUCCESS | DLL_EMPTY |
				    DLL_SUCCESS;

			else
				status = DLT_SUCCESS;
		}
	}

	return (status);
}

//
// Each recursive traversal is based on the order in which
// the list will be presented.  Through each recursive iteration,
// the newnode in the specific form of traversal is appended to the
// resulting list
//
void inOrder(Node * node, List ** result)
{
	Node *tmp = NULL;

	if (node != NULL)
	{
		mknode(&tmp, node->VALUE);
		append(result, (*result)->caboose, tmp);
		inOrder(node->fro, result);
		inOrder(node->to, result);
	}
}

void preOrder(Node * node, List ** result)
{
	Node *tmp = NULL;

	if (node != NULL)
	{
		preOrder(node->fro, result);
		mknode(&tmp, node->VALUE);
		append(result, (*result)->caboose, tmp);
		preOrder(node->to, result);
	}
}

void postOrder(Node * node, List ** result)
{
	Node *tmp = NULL;

	if (node != NULL)
	{

		postOrder(node->to, result);
		mknode(&tmp, node->VALUE);
		append(result, (*result)->caboose, tmp);
		postOrder(node->fro, result);
	}
}
