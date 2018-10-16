#include "list.h"

//////////////////////////////////////////////////////////////////////
//
//   rmlist() - a list library function to deallocate an existing
//              list; care must be taken to ensure any component
//              nodes have been properly deallocated so as to prevent
//              a memory leak. The resulting list will be NULL.
//
//              be sure to utilize existing list libraray functions 
//              to facilitate your implementation. Do not reimplement
//              existing list library functionality!
//
// status code: this function can generate the following status codes
//                DLL_SUCCESS: list successfully deallocated
//                DLL_NULL:    normal operation
//                DLL_ERROR:   error encountered (list already
//                             NULL or in invalid state)
//                DLL_INVALID: myList NULL
//
//              as with the other functions, you may use no more
//              than one return() statement per function.
//
//              do not count; navigate by comparison
//
code_t rmlist(List ** oldList)
{
	//
	// Initialize status code as error, incase an error is hit
	// later on in the program
	//
	code_t status = DLL_ERROR;

	//
	// Check that list exists and is not NULL, therefore a list can be
	// deallocated in the first place
	//
	if (oldList != NULL)
	{
		if (*oldList != NULL)
		{
			//
			// If list is not empty, deallocated by emptying it with the empty
			// function, then free the list pointers, reassign to null
			//
			if ((*oldList)->engine != NULL)
			{
				empty(oldList);	// not reinventing the wheel to empty list
				free((*oldList)->engine);
				free((*oldList)->caboose);
				(*oldList)->engine = NULL;
				(*oldList)->caboose = NULL;

				free(*oldList);
				(*oldList) = NULL;
				oldList = NULL;
				//
				// If deallocation is successful, return NULL and success status codes now that
				// list is completely nuked
				//
				status = DLL_SUCCESS | DLL_NULL;
			}
			//
			// if list is empty, simply free the pointers to engine and caboose, reassigning the list
			// pointer to NULL
			//
			else
			{
				free((*oldList)->engine);
				free((*oldList)->caboose);
				(*oldList) = NULL;
				status = DLL_SUCCESS | DLL_NULL;
			}
		}
		//
		// If list is NULL, return NULL status code, nothing to be deallocated
		//
		else
			oldList = NULL;
		status = status | DLL_NULL;
	}
	//
	// If list doesn't exist, return invalid status code
	//
	else
		status = status | DLL_INVALID;

	return (status);

}
