#include "list.h"

//////////////////////////////////////////////////////////////////////
//
//   obtain() - take and isolate indicated node out of list, through
//              a careful adjustment of necessary pointers. obtain()
//              needs to maintain list integrity.
//              
//error states: NULL or EMPTY initial list, NULL thatNode. In such a
//              case, do not modify the list.
//
// status code: this function can generate the following status codes
//                  DLN_NULL:    *thatNode is NULL
//                  DLN_INVALID: thatNode is NULL
//                  DLN_ERROR:   *thatNode not in list
//                  DLL_SUCCESS: normal operation
//                  DLL_NULL:    list is NULL
//                  DLL_ERROR:   error encountered (any error)
//                  DLL_INVALID: cannot proceed (myList is NULL)
//                  DLL_EMPTY:   list is EMPTY (not directly an
//                               error, although likely is associated
//                               with error condition)
//
//              as with the other functions, you may use no more
//              than one return() statement per function.
//
//              do not count; navigate by comparison
//
code_t obtain(List ** myList, Node ** thatNode)
{
	// dll2
	//
	// Note*: if obtain is successful, program decreases quantity by 
	// 1 due to decrease of list size
	//

	//
	// Initialize status code as an error, create NULL
	// tmp node for iterating over the list
	//
	code_t status = DLL_ERROR;
	Node *tmp = NULL;

	//
	// If mylist is null and thatnode is null, we cannot
	// obtain from the list.  Return error codes
	//
	if (myList == NULL || thatNode == NULL)
	{
		if (myList == NULL)
			status = status | DLL_INVALID;
		else if (thatNode == NULL)
			status = status | DLL_NULL;
	}

	//
	// if mylist pointer is Null, return null error code, indicated that the error
	// isn't quite as evil as the above error :D
	//
	else if (*myList == NULL)
		status = status | DLL_NULL;

	//
	// If thatNode is null return empty list code.  This indicates that there is no node
	// the program can obtain from the list
	//
	else if (*thatNode == NULL)
		status = status | DLL_EMPTY;

	//
	// Check that list isn't null and that node isn't NULL. If these conditions are met, obtain
	// functionality can begin implementing itself.
	//
	else if (*myList != NULL && *myList != UNDEFINED && *thatNode != NULL
		 && *thatNode != UNDEFINED)
	{
		//
		// Check that list isn't empty
		//
		if ((*myList)->engine != NULL && (*myList)->caboose != NULL)
		{
			//
			// Obtain from one node list. disconnect thatnode and set all
			// list pointers to NULL
			//
			if ((*myList)->engine == (*myList)->caboose)
			{
				(*myList)->engine = NULL;
				(*myList)->caboose = NULL;

				(*thatNode)->to = NULL;
				(*thatNode)->fro = NULL;
				(*myList)->qty -= 1;
				//
				// If successful, list should be empty, return empty status code
				//
				status = DLL_SUCCESS | DLL_EMPTY;
			}
			//
			// Obtaining from two node list
			//
			else if ((*myList)->engine->to == (*myList)->caboose)
			{
				//
				// Check if obtaining from first or 2nd node, then rearrange
				// node pointers correctly. 
				//
				if ((*thatNode) == (*myList)->engine)
				{
					//
					// if Obtaining first node, move over engine to caboose, and then
					// code removes primary engine node
					//
					(*myList)->engine = (*myList)->caboose;
					(*myList)->engine->fro = NULL;
					(*myList)->caboose->fro = NULL;

					(*myList)->engine->to = NULL;
					(*myList)->caboose->to = NULL;

					(*thatNode)->to = NULL;
					(*thatNode)->fro = NULL;

					(*myList)->qty -= 1;

					status = DLL_SUCCESS;
				}
				else if ((*thatNode) == (*myList)->caboose)
				{
					//
					// If node is caboose in a two node list, move caboose pointer
					// and disconnect primarily caboose node
					//
					(*myList)->caboose = (*myList)->engine;

					(*myList)->caboose->fro = NULL;
					(*myList)->engine->fro = NULL;

					(*myList)->caboose->to = NULL;
					(*myList)->engine->to = NULL;

					(*thatNode)->to = NULL;
					(*thatNode)->fro = NULL;

					(*myList)->qty -= 1;
					status = DLL_SUCCESS;
				}
			}
			//
			// Obtaining from the beginning of the list
			// Move over engine node and disconnect previous
			// engine node
			//
			else if ((*thatNode) == (*myList)->engine)
			{
				(*myList)->engine = (*thatNode)->to;
				(*myList)->engine->fro = NULL;
				(*thatNode)->to = NULL;
				(*myList)->qty -= 1;
				status = DLL_SUCCESS;
			}
			//
			// Obtaining from the end of a list
			// tmp node iterates over list until position previous of caboose
			// once position is reached, disconnect thatNode
			//
			else if ((*thatNode) == (*myList)->caboose)
			{
				tmp = (*myList)->engine;
				while (tmp != (*thatNode)->fro && tmp != NULL)
				{
					tmp = tmp->to;
				}

				if (tmp == NULL)
					status = DLL_ERROR;

				else
				{
					tmp->fro = (*myList)->caboose->fro->fro;
					(*myList)->caboose = tmp;
					tmp->to = NULL;
					(*thatNode)->to = NULL;
					(*myList)->qty -= 1;
					status = DLL_SUCCESS;
				}
			}
			//
			// Obtaining from the middle of the list
			// Most requests occur within this spectrum
			// tmp traverses to position before specified Node,
			// pointers are rearrange, leaving out thatNode, which is
			// now disconnected
			//
			else
			{
				tmp = (*myList)->engine;
				while (tmp != (*thatNode)->fro && tmp != NULL)
				{
					tmp = tmp->to;
				}
				if (tmp == NULL)
					status = DLL_ERROR;
				else
				{
					tmp->to = (*thatNode)->to;
					tmp->to->fro = tmp;
					(*thatNode)->to = NULL;
					status = DLL_SUCCESS;
					(*myList)->qty -= 1;
				}
			}
		}
		//
		// empty list. If the list is empty, return an empty status code
		//
		else
			status = status | DLL_EMPTY;
	}
	return (status);
}
