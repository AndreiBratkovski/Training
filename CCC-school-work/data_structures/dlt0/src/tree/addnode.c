#include "tree.h"

//////////////////////////////////////////////////////////////////////
//
// addnode()   - place newNode into indicated tree at proper position.
//
//  status code: this function can generate the following status codes
//                  DLT_SUCCESS:  normal operation (success!)
//                  DLT_NULL:     tree is NULL
//                  DLT_MAX:      tried to add onto a full bounded
//                                tree (considered an error)
//                  DLT_ERROR:    error encountered
//                  DLT_INVALID:  tree pointer doesn't exist
//
//         note: a max_height of 0 indicates an unbounded tree
//              
//  assumptions: duplicate values are allowed;
//               nodes with values less than or equal to that of
//               an analyzed node are placed to the left (back),
//               where greater than are placed to the right (there).
//
//         note: you are to have only ONE return statement for this
//               entire function. Change the existing one as needed.
//

code_t addnode(Tree ** myTree, Node * newNode)
{
	////////////////////////////////////////
	//
	// Iterative traversal for adding a node
	//
	////////////////////////////////////////

	//
	// Initialize a height variable to keep track of tree height,
	// a tmp variable for traversing the tree, and a trigger variable to
	// keep track of when to end iterations after adding a node
	//
	uc height = 0;
	code_t status = DLT_ERROR;
	Node *tmp = NULL;
	int trigger = 0;

	//
	// If my tree does not exist, return an invalid error code because
	// we cannot add a node to a non existant tree
	//
	if (myTree == NULL)
		status = status | DLT_INVALID;

	//
	// If myTree pointer is NULL, it has not been created yet, return
	// a null status code
	//
	else if (*myTree == NULL)
		status = status | DLT_NULL;

	//
	// If tree exists and new Node is not Null, begin traversal
	// Tree can now be added to
	//
	else if (myTree != NULL && newNode != NULL)
	{
		//
		// If tree is empty, new node becomes the root of my tree
		//
		if ((*myTree)->root == NULL)
		{
			(*myTree)->root = newNode;
			status = DLT_SUCCESS;
		}
		//
		// If tree is not empty, traverse tree until area where new node
		// shall be added
		//
		else
		{
			//
			// Set beginning of search node at the root of tree
			// Below is the iterative traversal logic for a tree
			// 
			tmp = (*myTree)->root;
			if ((*myTree)->max_height == 0)
			{
				while (trigger != 1)
				{
					//
					// If newNode is less than the current
					// traversed Value, tree traverses left, otherwise
					// tree traverses right. if we approach a NULL point,
					// add the node there
					//
					if (newNode->VALUE <= tmp->VALUE)
					{
						if (tmp->fro == NULL)
						{
							tmp->fro = newNode;
							trigger = 1;
						}
						else
							tmp = tmp->fro;
					}

					else if (newNode->VALUE > tmp->VALUE)
					{
						if (tmp->to == NULL)
						{
							tmp->to = newNode;
							trigger = 1;
						}
						else
							tmp = tmp->to;
					}
				}
			}
			//
			// Tree has a max height
			// Traversing over a tree iteratively with a set max height
			// Traversal ends if we reach max height of the tree, and exits
			// with a MAX limit reached status code
			//
			else
			{
				//
				// Iterative traversal over the tree is the exact
				// same as the previous loop, except it takes into account
				// the height of the tree, so that the max height cannot
				// be breached
				//
				while (trigger != 1)
				{
					if (height >= (*myTree)->max_height)
					{
						status = status | DLT_MAX;
						break;
					}
					if (newNode->VALUE <= tmp->VALUE)
					{
						if (tmp->fro == NULL)
						{
							tmp->fro = newNode;
							status = DLT_SUCCESS;
							trigger = 1;
						}
						else
						{
							tmp = tmp->fro;
							height++;
						}
					}

					else if (newNode->VALUE > tmp->VALUE)
					{
						if (tmp->to == NULL)
						{
							tmp->to = newNode;
							status = DLT_SUCCESS;
							trigger = 1;
						}
						else
						{
							tmp = tmp->to;
							height++;
						}
					}
				}
			}

		}
	}
	else if (newNode == NULL)
		status = status | DLN_NULL;

	return (status);
}
