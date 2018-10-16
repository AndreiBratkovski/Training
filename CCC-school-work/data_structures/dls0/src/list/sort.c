#include "list.h"

//////////////////////////////////////////////////////////////////////
//
// sortlist() - a list library function to sort an existing list
//              according to the mode indicated.
//
//              the original list is **MODIFIED**, and becomes the
//              sorted list.
//
//              be sure to utilize existing list and node library
//              functions to facilitate your implementation. Do NOT
//              reinvent the wheel.
//
//   modes are: 0 - least to greatest (least is first)
//              1 - greatest to least (greatest is first)
//              2 - reverse order of original list
//
//    behavior: on error, list becomes NULL.
//              on invalid mode, MOD by total modes and continue,
//                  performing whatever that result is.
//
// status code: this function can generate the following status codes
//                DLL_SUCCESS: normal operation
//                DLL_NULL:    list is NULL
//                DLL_EMPTY:   list is empty
//                DLL_ERROR:   error encountered
//                DLL_INVALID: list does not exist
//
//              as with the other functions, you may use no more
//              than one return() statement per function.
//
//              do not count; navigate by comparison
//
code_t sortlist(List ** myList, int mode)
{
	//
	// Initialize tmp variables for traversing list, start error code at
	// DLL_ERROR incase program runs into an error
	//
	code_t status = DLL_ERROR;
	Node *tmp = NULL;
	Node *tmp2 = NULL;
	//
	// Prev is just another tmp variable being used for more clarity in positioning
	//
	Node *prev = NULL;

	//
	// create char for storing tmp value, data to be swapped in sort
	// due to obtain/append/and swap not working as hoped
	//
	char tmpVal;

	//
	// Check if list is not NULL or undefined, then check if list Pointer is not null or
	// undefined.  If list is populated with nodes, begin deciding which mode to use
	//
	if (myList != NULL && myList != UNDEFINED)
	{
		if (*myList != NULL && *myList != UNDEFINED)
		{

			if ((*myList)->engine != NULL
			    && (*myList)->engine != (*myList)->caboose)
			{
				//
				// Mode 2, begin sorting list in reverse by rearrange list pointers
				//
				if (mode == 2)
				{
					tmp = (*myList)->engine;
					//
					// Traverse list from the beginning, rearrange node pointers to
					// set list in reverse
					//
					while (tmp != NULL)
					{
						tmp2 = tmp->to;
						tmp->to = prev;
						prev = tmp;
						tmp = tmp2;
					}
					(*myList)->engine = prev;
					//
					// return success code once list is rearranged
					// properly in reverse
					//
					status = DLL_SUCCESS;
				}

				//
				// Mode 0, rearranging list in order from least to greatest.  This is a bubble type
				// of sort, using data rather than node rearrangement unfortunately
				//
				else if (mode == 0)
				{

					tmp = (*myList)->engine;
					tmp2 = tmp->to;

					//
					// Using nested while loops, program iterates through both lists and compares
					// adjacent nodes, if they are out of order according to mode 0, they swap
					//              
					while (tmp2 != NULL)
					{
						while (tmp2 != tmp)
						{
							if (tmp2->VALUE <
							    tmp->VALUE)
							{
								//** Value implementation **//
								// swap node values //
								tmpVal =
								    tmp->VALUE;
								tmp->VALUE =
								    tmp2->VALUE;
								tmp2->VALUE =
								    tmpVal;
							}
							tmp = tmp->to;
						}
						tmp = (*myList)->engine;
						tmp2 = tmp2->to;
					}
					//
					// return success code once list is
					// rearrange properly
					//
					status = DLL_SUCCESS;
				}
				//
				// Mode 1, rearrange list from greatest to least, program iterates through
				// both lists and compares adjacent nodes. If they are out of order according to
				// mode 1, they swap
				//
				else if (mode == 1)
				{
					tmp = (*myList)->engine;
					tmp2 = tmp->to;

					while (tmp2 != NULL)
					{
						while (tmp2 != tmp)
						{
							if (tmp2->VALUE >
							    tmp->VALUE)
							{
								// ** Value implementation**
								tmpVal =
								    tmp->VALUE;
								tmp->VALUE =
								    tmp2->VALUE;
								tmp2->VALUE =
								    tmpVal;

							}
							tmp = tmp->to;
						}
						tmp = (*myList)->engine;
						tmp2 = tmp2->to;
					}
				}
				//
				// Once list is successfully sorted, return success code
				//
				status = DLL_SUCCESS;

			}
			//
			// If list is one node, return success, it is already sorted according to
			// all modes
			//
			else if ((*myList)->engine != NULL)
				status = DLL_SUCCESS;
			//
			// If list is empty, return empty status code, cannot be sorted
			//
			else
			{
				*myList = NULL;
				status = status | DLL_EMPTY;
			}

		}
		//
		// if List pointer is Null, return null status code
		//
		else
			status = status | DLL_NULL;
	}
	//
	// If list does not exist, return invalid status code
	//
	else
		status = status | DLL_INVALID;

	return (status);
}
