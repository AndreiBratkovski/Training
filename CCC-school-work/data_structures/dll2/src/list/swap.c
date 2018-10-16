#include "list.h"

//////////////////////////////////////////////////////////////////////
//
// swapnode() - swap the position of two given nodes in a list, being
//              sure to appropriately adjust any and all pertinent
//              pointers to ensure list integrity following the
//              operation (including potential changes to the list's
//              own first and last pointers, along with connectivity
//              between the nodes from the start to end of the list).
//
//              be sure to utilize existing list and node library
//              functions to facilitate your implementation. Do NOT
//              reinvent the wheel.
//
//        note: you are NOT to just adjust node info values. You must
//              disconnect the identified nodes from the list and 
//              reconnect them- the node is our unit of transaction,
//              NOT the data it contains.
//
// status code: this function can generate the following status codes
//                DLN_NULL:    node is NULL
//                DLL_SUCCESS: normal operation
//                DLL_NULL:    list is NULL
//                DLL_EMPTY:   list is empty
//                DLL_ERROR:   something is NULL or EMPTY, or other
//                             error state encountered.
//                DLL_INVALID: invalid list state
//
//              as with the other functions, you may use no more
//              than one return() statement per function.
//
//              do not count; navigate by comparison
//
code_t swapnode(List ** myList, Node * posA, Node * posB)
{
	//
	// Function made for swapping two nodes in a list. Initialize status code to 
	// DLL_ERROR incase an error is encountered in the program
	//
	code_t status = DLL_ERROR;

	//
	// Set tmp and tmp2 node variables for traversing the list
	//
	Node *tmp = NULL;
	Node *tmp2 = NULL;

	//
	// If list doesn't exist, return invalid status code
	//
	if (myList == NULL)
		status = status | DLL_INVALID;

	//
	// If list is NULL, return NULL status code.  Neither NULL or non existant list
	// can have positions to swap
	//
	else if (*myList == NULL)
		status = status | DLL_NULL;

	//
	// Check that list exists and that both position nodes exist before attempting to swap
	//
	else if (*myList != NULL && *myList != UNDEFINED && posA != NULL
		 && posB != NULL)
	{
		//
		// If the list isn't empty, swapping can occur and begin
		//
		if ((*myList)->engine != NULL)
		{
			//
			// Check that positions are not equal. If they are, then swapping is unnecessary because
			// it is one node
			//
			if (posA != posB)
			{
				//
				// Swap node logic, make two new nodes, append them after the listed positions, and disconnect
				// the previous nodes
				//
				mknode(&tmp, (posB->VALUE));
				append(myList, posA, tmp);

				mknode(&tmp2, (posA->VALUE));
				append(myList, posB, tmp2);

				obtain(myList, &posA);
				obtain(myList, &posB);

				posA = tmp;
				posB = tmp2;
				status = DLL_SUCCESS;
			}
		}
		//
		// Empty status code for empty list
		//
		else
			status = status | DLL_EMPTY;
	}
	//
	// If list is empty and positions are NULL, return status code indicating that. Nothing to 
	// swap
	//
	else
		status = status | DLN_NULL | DLL_EMPTY;
	return (status);
}
