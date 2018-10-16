#include "tree.h"

//////////////////////////////////////////////////////////////////////
//
//traverse_i()- a tree library utility function to walk through the 
//              tree, by order of the indicated traversal mode, and
//              to produce a list of all the nodes encountered, in 
//              the order they were encountered.
//
//        note: traverse_i() focuses on the actual content of what
//              is in the tree, setting a (double) pointer to a
//              list that contains the ordered content as it was
//              encountered in the tree. To avoid an error, the list
//              should be NULL (create it).
//
//              the tree should not be modified as a result of
//              performing this action.
//
//              an iterative approach will be one to conform to a
//              more detail-oriented approach- loops. Also think of
//              it as the "naive" approach- if, once understanding
//              the task to be done, you set out to implement it
//              without trying to reference any existing approaches;
//              Especially an approach prior to gaining more
//              experience with recursion, and any experience with
//              stacks.
//
//              traverse_i() could be used as a prerequisite step 
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
code_t traverse_i(Tree * myTree, List ** result, uc mode)
{
	//
	// Initiate Error status code incase program runs into
	// any problems later.  Initialize 3 tmp variables for list
	// traversal
	//
	code_t status = DLT_ERROR;
	Node *tmp = NULL;
	Node *tmp2 = NULL;
	Node *tmp3 = NULL;

	//
	// If myTree or result does not exist, return NULL status code
	// because there is no tree to traverse
	//
	if (myTree == NULL || result == NULL)
		status = status | DLT_NULL;

	//
	// If myTree exists, we can begin checking if the contents are NULL
	// or empty
	//
	else if (myTree != NULL && result != NULL)
	{
		//
		// If the root of the tree is NULL, check that the mode is valid
		// and return status code related to state of the empty tree.
		// result pointer cannot be NULL so that the result list can be
		// allocated
		//
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
		// Handle successful traversals here
		// Now that empty and NULL trees/result lists have been accounted
		// for, we can successfully build a new list and iteratively
		// traverse the tree
		// 
		else
		{
			mklist(result);
			tmp = myTree->root;
			//
			// Inorder iterative traversal Iterate over
			// the tree and append each element of the tree in an
			// inordered pattern to the resulting list. This is a morris
			// traversal, which rearranges the pointers of nodes to support
			// Inorder traversing while threading through the tree 
			//
			if (mode == 1)
			{
				while (tmp != NULL)
				{
					if (tmp->fro == NULL)
					{
						mknode(&tmp2, tmp->VALUE);
						append(result,
						       (*result)->caboose,
						       tmp2);
						tmp2 = NULL;
						tmp = tmp->to;
					}
					else
					{
						tmp3 = tmp->fro;
						while (tmp3->to != NULL
						       && tmp3->to != tmp)
						{
							tmp3 = tmp3->to;
						}
						if (tmp3->to == NULL)
						{
							tmp3->to = tmp;
							tmp = tmp->fro;
						}
						else
						{
							tmp3->to = NULL;
							mknode(&tmp2,
							       tmp->VALUE);
							append(result,
							       (*result)->
							       caboose, tmp2);
							tmp2 = NULL;
							tmp = tmp->to;
						}

					}
				}
			}
			//
			// Preorder traversal, Same logic as above, except tmp->fro
			// becomes tmp->to in some cases due to the new preorder
			// ordering
			//
			else if (mode == 0)
			{
				while (tmp != NULL)
				{
					if (tmp->fro == NULL)
					{
						mknode(&tmp2, tmp->VALUE);
						append(result,
						       (*result)->caboose,
						       tmp2);
						tmp2 = NULL;
						tmp = tmp->to;
					}
					else
					{
						tmp3 = tmp->fro;
						while (tmp3->to != NULL
						       && tmp3->to != tmp)
						{
							tmp3 = tmp3->to;
						}
						if (tmp3->to == tmp)
						{
							tmp3->to = NULL;
							tmp = tmp->to;
						}
						else
						{
							mknode(&tmp2,
							       tmp->VALUE);
							append(result,
							       (*result)->
							       caboose, tmp2);
							tmp3->to = tmp;
							tmp2 = NULL;
							tmp = tmp->fro;
						}

					}
				}
			}
			//
			// PostOrder traversal.  The only difference between this and
			// the inorder traversal is that the elements of the list
			// are being added in reverse to the list.  This results in
			// the correct reverse order of inorder (postorder) in the list
			//
			if (mode == 2)
			{
				while (tmp != NULL)
				{
					if (tmp->fro == NULL)
					{
						mknode(&tmp2, tmp->VALUE);
						insert(result,
						       (*result)->engine, tmp2);
						tmp2 = NULL;
						tmp = tmp->to;
					}
					else
					{
						tmp3 = tmp->fro;
						while (tmp3->to != NULL
						       && tmp3->to != tmp)
						{
							tmp3 = tmp3->to;
						}
						if (tmp3->to == NULL)
						{
							tmp3->to = tmp;
							tmp = tmp->fro;
						}
						else
						{
							tmp3->to = NULL;
							mknode(&tmp2,
							       tmp->VALUE);
							insert(result,
							       (*result)->
							       engine, tmp2);
							tmp2 = NULL;
							tmp = tmp->to;
						}

					}
				}
			}

			status = DLT_SUCCESS;
		}
	}
	return (status);
}
