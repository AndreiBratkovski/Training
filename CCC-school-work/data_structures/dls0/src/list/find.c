#include "list.h"

//////////////////////////////////////////////////////////////////////
//
//    find() - a list library utility function to locate a node in
//             an existing list by value it contains.
//
//       note: find() focuses on the actual content of what is in the
//             nodes, setting a (double) pointer to the first node
//             that contains the matching value (from the start of the
//             list, if foundNode is initially NULL, or from the point
//             in the list that foundNode points).
//
//status code: this function can generate the following status codes
//               DLN_SUCCESS:  match found
//               DLN_NULL:     match not found (node is NULL)
//               DLN_ERROR:    error encountered
//               DLN_INVALID:  node doesn't exist (UNDEFINED)
//               DLL_NULL:     list is NULL
//               DLL_EMPTY:    list is EMPTY
//               DLL_ERROR:    error encountered
//               DLL_INVALID:  list doesn't exist (UNDEFINED)
//
//   behavior: on error (NULL/UNDEFINED list/node), foundNode, if
//             it exists, is NULL.
//
//             as with the other functions, you may use no more
//             than one return() statement per function.
//
//             do not count; navigate by comparison
//
code_t find(List * myList, char searchval, Node ** foundNode)
{
	//
	// initialize status code to DLL_ERROR nad tmp node for traversing list
	//
	code_t status = DLL_ERROR;
	Node *tmp = NULL;

	//
	// If list is Undefined or NULL, we cannot traverse it with tmp as we would hope to
	//
	if (myList != UNDEFINED && myList != NULL)
	{
		//
		// if myList is not empty, traverse list and search for node with 
		// searchval in it
		//
		if (myList->engine != NULL)
		{
			if ((*foundNode) == NULL)
				tmp = myList->engine;
			else
				tmp = (*foundNode)->to;

			while (tmp != NULL)
			{
				if (tmp->VALUE == searchval)
				{
					(*foundNode) = tmp;
					status = DLN_SUCCESS;
					break;

				}
				tmp = tmp->to;
			}

			//
			// If node is not found, return NULL node status code
			//
			if (tmp == NULL)
			{
				if ((*foundNode) == NULL)
					status = DLN_NULL;
				else
				{
					(*foundNode) = NULL;
					status = DLN_NULL;
				}
			}
		}
		//
		// If list is empty, return empty list status code
		//
		else
			status = status | DLL_EMPTY;
	}
	//
	// If list is NULL, return NULL list status code
	//
	else
		status = status | DLL_NULL;
	return (status);
}
