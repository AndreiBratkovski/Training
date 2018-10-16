#include "tree.h"
#include "stack.h"

//////////////////////////////////////////////////////////////////////
//
//traverse_s()- a tree library utility function to walk through the 
//              tree, by order of the indicated traversal mode, and
//              to produce a list of all the nodes encountered, in 
//              the order they were encountered.
//
//        note: traverse_s() focuses on the actual content of what
//              is in the tree, setting a (double) pointer to a
//              list that contains the ordered content as it was
//              encountered in the tree. To avoid an error, the list
//              should be NULL (create it).
//
//              the tree should not be modified as a result of
//              performing this action.
//
//              the stack-based implementation of traverse() will 
//              embody the utilization of a stack to the solution
//              of the tree traversal process. Once again, we are
//              sacrificing detail-oriented control in the moment
//              for conceptual elegance and simplification, which
//              will test your understanding of stack concepts.
//
//              traverse_s() could be used as a prerequisite step 
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
// Prototype functions for recursive based stack traversals
//
void inOrderStack(Node *, List **);
void preOrderStack(Node *, List **);
void postOrderStack(Node *, List **);

code_t traverse_s(Tree * myTree, List ** result, uc mode)
{
	//
	// Initialize error codes just incase the traversal fails due to 
	// an error encountered in the program
	//
	code_t status = DLT_ERROR;

	//
	// If the tree or result does not exist, return a NULL tree status code
	// to let the user know that they need an existing tree for traversal
	//
	if (myTree == NULL || result == NULL)
		status = status | DLT_NULL;

	//
	// if tree and resulting list both exist, then check for empty list
	// or allocated list status codes as well as invalid mode listed
	//
	else if (myTree != NULL && result != NULL)
	{
		if (myTree->root == NULL)
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
		else if (*result != NULL && mode <= 2)
			status = DLT_ERROR | DLL_ERROR | DLL_ALREADY_ALLOC;

		else if (mode > 2)
			status = DLT_ERROR;
		//
		// Recursive traversal implementation here, now that all error checks
		// have been made
		//
		else
		{
			mklist(result);

			if (mode == INORDER)	// InOrder
				inOrderStack(myTree->root, result);

			else if (mode == PREORDER)	// PreOrder
				preOrderStack(myTree->root, result);

			else if (mode == POSTORDER)	// PostOrder
				postOrderStack(myTree->root, result);

			status = DLT_SUCCESS;
		}
	}
	return (status);
}

//
// Essentially, the recursive programs are the same as the recursive
// traversals, except the inclusion of a newstack exists, where the new node 
// is pushed and popped off the stack. This is to demonstrate the
// understanding to how a stack works, but doesn't need to be used in
// this type of situation.  However, stacks can be used iteratively to
// form a solution without recursion due to their LIFO properties
//
void inOrderStack(Node * node, List ** result)
{
	Node *tmp = NULL;
	Stack *newStack = NULL;

	mkstack(&newStack, 0);

	if (node != NULL)
	{
		mknode(&tmp, node->VALUE);
		push(&newStack, tmp);
		pop(&newStack, &tmp);
		append(result, (*result)->caboose, tmp);
		inOrderStack(node->fro, result);
		inOrderStack(node->to, result);
	}
}

void preOrderStack(Node * node, List ** result)
{
	Node *tmp = NULL;
	Stack *newStack = NULL;

	mkstack(&newStack, 0);

	if (node != NULL)
	{
		preOrderStack(node->fro, result);
		mknode(&tmp, node->VALUE);
		push(&newStack, tmp);
		pop(&newStack, &tmp);
		append(result, (*result)->caboose, tmp);
		preOrderStack(node->to, result);
	}
}

void postOrderStack(Node * node, List ** result)
{
	Node *tmp = NULL;
	Stack *newStack = NULL;

	mkstack(&newStack, 0);

	if (node != NULL)
	{
		postOrderStack(node->to, result);
		mknode(&tmp, node->VALUE);
		push(&newStack, tmp);
		pop(&newStack, &tmp);
		append(result, (*result)->caboose, tmp);
		postOrderStack(node->fro, result);
	}
}
