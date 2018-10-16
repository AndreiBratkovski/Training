#include "list.h"

//////////////////////////////////////////////////////////////////////
//
//   insert() - add a new node to the given list before the node
//              at the indicated place. insert() needs to manage
//              the necessary connections/pointers) to maintain list
//              integrity, along with ensuring the start and end
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
code_t insert(List ** myList, Node * place, Node * newNode)
{
	//
	// Initialize tmp node and status code as DLL_ERROR
	//

	// dll2
	// Note* If insert is successful, program adds 1 to list quantity due to
	// increase in list size
	//
	Node *tmp;
	code_t status = DLL_ERROR;

	//
	// If List is not undefined and list is not NULL, proceed to insert logic
	//
	if (myList != UNDEFINED && myList != NULL && newNode != NULL
	    && newNode != UNDEFINED)
	{
		//
		// Insert in empty list
		//
		if ((*myList)->engine == NULL && (*myList)->caboose == NULL)
		{
			(*myList)->engine = newNode;
			(*myList)->caboose = newNode;
			newNode->to = NULL;
			newNode->fro = NULL;
			(*myList)->qty += 1;
			status = DLL_SUCCESS;
		}

		//
		// Insert in one node list
		//
		else if ((*myList)->engine == (*myList)->caboose)
		{
			newNode->to = (*myList)->caboose;
			(*myList)->engine = newNode;
			newNode->to->fro = newNode;
			newNode->fro = NULL;
			(*myList)->qty += 1;
			status = DLL_SUCCESS;
		}
		//
		// Insert at beginning
		//
		else if (place == (*myList)->engine)
		{
			newNode->to = (*myList)->engine;
			(*myList)->engine = newNode;
			newNode->to->fro = newNode;
			newNode->fro = NULL;
			(*myList)->qty += 1;
			status = DLL_SUCCESS;
		}
		//
		// Insert at end
		//
		else if (place == (*myList)->caboose)
		{
			tmp = (*myList)->engine;
			while (tmp != NULL && tmp->to != place)
			{
				tmp = tmp->to;
			}
			if (tmp != NULL)
			{
				newNode->to = (*myList)->caboose;
				tmp->to = newNode;
				newNode->to->fro = newNode;
				newNode->fro = tmp;
				(*myList)->qty += 1;
				status = DLL_SUCCESS;
			}
			//
			// If tmp is NULL, then newNode is NULL, return Null node status
			// code error
			//
			else
				status = DLN_ERROR | DLL_INVALID;
		}
		//
		// Insert in middle
		//
		else if (place != NULL)
		{
			tmp = (*myList)->engine;
			while (tmp != NULL && tmp->to != place)
			{
				tmp = tmp->to;
			}
			if (tmp != NULL)
			{
				newNode->to = tmp->to;
				tmp->to = newNode;
				newNode->to->fro = newNode;
				newNode->fro = tmp;
				(*myList)->qty += 1;
				status = DLL_SUCCESS;
			}
			//
			// If tmp is NULL, then NewNode is NULL, return NULL node status code error
			//
			else
				status = DLN_ERROR | DLL_INVALID;
		}
		//
		// If place is NULL and newNode is NULL, we have a NULL node error and a NULL list error
		//
		else
			status = DLL_INVALID | DLL_ERROR | DLN_ERROR | DLN_NULL;
	}

	//
	// If myList is NULL, the status code is an INVALID list.
	//
	else if (myList == NULL)
		status = status | DLL_INVALID;

	else
	{
		//
		// If list is not NULL, newNode is NUll or place is NULL
		//
		if ((*myList) != NULL)
		{
			//
			// If myList is empty, and newnode is NULL, return
			// empty list and null node status code
			//
			if ((*myList)->engine == NULL)
			{
				status = status | DLL_EMPTY;
				status = status | DLN_NULL;
			}
			//
			// If newNode is NULL, return newNode status code
			//
			else if (newNode == NULL)
				status = status | DLN_NULL;
			//
			// If the List is NULL, return null list status code
			//
			else
				status = status | DLL_NULL;
		}
		//
		// if my list pointer is NULL, return Null list status code
		//
		else if ((*myList) == NULL)
			status = status | DLL_NULL;
	}
	return (status);
}
