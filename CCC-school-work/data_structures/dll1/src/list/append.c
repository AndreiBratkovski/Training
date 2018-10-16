#include "list.h"

//////////////////////////////////////////////////////////////////////
//
//   append() - add a new node to the given list after the node
//              at the indicated place. append() needs to manage
//              the necessary connections (pointers) to maintain list
//              integrity, along with ensuring the first and last
//              indicators of the list remain relevant and up-to-date.
//
//    behavior: do NOT create a list if NULL
//
// status code: this function can generate the following status codes
//                DLN_NULL:    newNode is NULL
//                DLN_ERROR:   place or newNode NULL (list not EMPTY)
//                DLL_SUCCESS: normal operation (success!)
//                DLL_NULL:    list is NULL
//                DLL_EMPTY:   list ends up EMPTY
//                DLL_ERROR:   error encountered
//                DLL_INVALID: invalid condition (place not in list)
//
//              as with the other functions, you may use no more
//              than one return() statement per function.
//
//              do not count; navigate by comparison
//
code_t append(List ** myList, Node * place, Node * newNode)
{
	Node *tmp;

	//
	// Initialize status code to DLL_ERROR
	//
	code_t status = DLL_ERROR;

	//
	// If my List is not UNDEFINED or NULL, then append can begin its
	// functionality
	//
	if (myList != UNDEFINED && myList != NULL && newNode != NULL
	    && newNode != UNDEFINED)
	{
		//
		// Appending to empty list
		//
		if ((*myList)->engine == NULL && (*myList)->caboose == NULL)
		{
			(*myList)->engine = newNode;
			(*myList)->caboose = newNode;
			newNode->to = NULL;
			newNode->fro = NULL;
			status = DLL_SUCCESS;
		}

		//
		// Appending to one node list
		//
		else if ((*myList)->engine == (*myList)->caboose)
		{
			(*myList)->engine->to = newNode;
			(*myList)->caboose = newNode;
			newNode->fro = (*myList)->engine;
			status = DLL_SUCCESS;
		}

		//
		// Appending to beginning of list
		//
		else if (place == (*myList)->engine)
		{
			newNode->to = (*myList)->engine->to;
			(*myList)->engine->to = newNode;
			newNode->fro = (*myList)->engine;
			newNode->to->fro = newNode;
			status = DLL_SUCCESS;
		}
		//
		// Appending to end of list
		//

		else if (place == (*myList)->caboose)
		{
			tmp = (*myList)->engine;
			while (tmp != NULL)
			{
				if (tmp == place)
					break;
				tmp = tmp->to;
			}
			if (tmp != NULL)
			{
				tmp->to = newNode;
				newNode->fro = tmp;
				(*myList)->caboose = newNode;
				status = DLL_SUCCESS;
			}
			//
			// If tmp NULL, place was not found, therefore error message occurs
			//
			else
				status = DLN_ERROR | DLL_INVALID;
		}
		//
		// Appending in the middle of the list
		//
		else if (place != NULL)
		{
			tmp = (*myList)->engine;
			while (tmp != NULL)
			{
				if (tmp == place)
					break;
				tmp = tmp->to;
			}
			if (tmp != NULL)
			{
				newNode->to = tmp->to;
				newNode->to->fro = newNode;
				tmp->to = newNode;
				newNode->fro = tmp;
				status = DLL_SUCCESS;
			}
			//
			// If tmp is NULL, then the place node was not found,
			// therefore an error message is assigned to status.
			//
			else
				status = DLN_ERROR | DLL_INVALID;
		}
		//
		// if place is NULL add to status code error that it is NULL node
		//
		else
			status = DLL_INVALID | DLL_ERROR | DLN_ERROR | DLN_NULL;

	}
	//
	// If the list is NULL, it cannot be appended to. return invalid code
	//
	else if (myList == NULL)
		status = status | DLL_INVALID;

	//
	// If List is NULL/UNDEFINED or newNode is NULL/UNDEFINED, there is an
	// error and we hit one of the below statements
	//
	else
	{
		//
		// if myLists pointer is not null, there is something there
		//
		if ((*myList) != NULL)
		{
			//
			// If the list is empty, return an empty list with null node status
			//
			if ((*myList)->engine == NULL)
			{
				status = status | DLL_EMPTY;
				status = status | DLN_NULL;
			}
			//
			// If newnode is NULL, return a nullNode status
			//
			else if (newNode == NULL)
				status = status | DLN_NULL;
			//
			// else, return a NULL list status because newNode is not null
			//
			else
				status = status | DLL_NULL;
		}
		//
		// If list is NULL,r eturn null list status
		//
		else if ((*myList) == NULL)
			status = status | DLL_NULL;
	}

	return (status);
}
