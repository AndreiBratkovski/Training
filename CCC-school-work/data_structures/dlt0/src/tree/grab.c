#include "tree.h"

//////////////////////////////////////////////////////////////////////
//
//grabnode()  - grab node out of indicated tree, ensuring integrity
//              is maintained (tree is modified)
//              
// status code: this function can generate the following status codes
//                  DLT_SUCCESS: normal operation
//                  DLT_EMPTY:   tree is now EMPTY after grabnode_r()
//                  DLT_NULL:    tree is NULL
//                  DLT_FAIL:    error occurred (tree is NULL,
//                               tried to grab from an empty tree)
//
//              The key with getting a node out of the tree is 
//              that, in many cases, you are removing a parent;
//              so, what takes its place?
//
//              as with the other functions, you may use no more
//              than one return() statement per function.
//
code_t grabnode(Tree ** myTree, Node ** newNode)
{
	//
	// Initialize Error code for status incase program runs into
	// a problem later when attempting to grab a node. Initialize
	// current node pointer to traverse list until node is grabbed
	//
	code_t status = DLT_ERROR;
	Node *current = NULL;

	//
	// If tree does not exist, return error invalid code or NULL code
	// depending on state of tree.  Neither state can be grabbed from
	//
	if (myTree == NULL)
		status = status | DLT_INVALID;
	else if (*myTree == NULL)
		status = status | DLT_NULL;
	//
	// If tree is empty, return an empty status code. Empty trees cannot
	// be grabbed from
	//
	else
	{
		if ((*myTree)->root == NULL)
			status = status | DLT_EMPTY;
		//
		// If tree is 1 node, grab that one node and return an empty status
		// code.  the Root would be set to NULL because the tree is now empty
		//
		else
		{
			if ((*myTree)->root->to == NULL
			    && (*myTree)->root->fro == NULL)
			{
				*newNode = (*myTree)->root;
				(*myTree)->root = NULL;
				status = DLT_SUCCESS | DLT_EMPTY;
			}
			//
			// In all other cases, iteratively traverse over the tree
			// using a current Node pointer starting from the trees root
			//
			else
			{
				//
				// If grabbing from root, rearrange pointers so that the
				// largest node on the left subtree is being pulled up to
				// be the new root
				//
				if (*newNode == (*myTree)->root)
				{
					//
					// Grabbing from the root, rearranging pointers of
					// tree pointers to reflect newTree
					//
					if ((*newNode)->fro != NULL)
					{
						if ((*newNode)->fro->to != NULL)
						{
							(*newNode)->fro->
							    to->fro =
							    (*myTree)->
							    root->fro;
							(*newNode)->fro->
							    to->to =
							    (*myTree)->root->to;
							(*myTree)->root =
							    (*newNode)->fro->to;
							(*newNode)->fro->to =
							    NULL;
						}
						//
						// If newNode fro is NULL, then newNode Fro is
						// the largest possible node value in the left subtree
						//
						else
						{
							(*newNode)->fro->to =
							    (*myTree)->root->to;
							(*myTree)->root =
							    (*newNode)->fro;
						}
					}
				}
				//
				// Grabbing from anywhere else but the root. Iteratively
				// traverse the tree, using the same logic to get current node
				// all the way to the node previous to the node being grabbed
				// When Node being grabbed is found, rearrange pointers to
				// exclude the node in question and connect its to/fro pointer
				// to the current( previous of newNode) node
				else
				{
					current = (*myTree)->root;
					while (current != NULL)
					{
						if (current->VALUE <
						    (*newNode)->VALUE
						    && current->to != *newNode)
							current = current->to;

						else if (current->VALUE >=
							 (*newNode)->VALUE
							 && current->fro !=
							 *newNode)
							current = current->fro;
						else if (current->to ==
							 *newNode)
						{
							current->to =
							    (*newNode)->to;
							current->fro =
							    (*newNode)->fro;
						}
						else if (current->fro ==
							 *newNode)
						{
							if ((*newNode)->to ==
							    NULL)
								current->fro =
								    (*newNode)->fro;
							else if ((*newNode)->to
								 != NULL)
							{
								current->fro =
								    (*newNode)->to;
								(*newNode)->
								    to->fro =
								    (*newNode)->fro;
							}
							break;
						}

					}
				}

				status = DLT_SUCCESS;
			}

		}

	}
	return (status);
}
