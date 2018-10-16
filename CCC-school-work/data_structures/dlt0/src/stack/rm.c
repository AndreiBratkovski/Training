#include "stack.h"

//////////////////////////////////////////////////////////////////////
//
//  rmstack() - unset, nullify members, and de-allocate the given 
//              stack.
//
//              be sure to utilize existing list and stack library
//              functions to facilitate your implementation. Do NOT
//              reinvent the wheel.
//
//              the top of the stack should follow the last node in
//              its underlying list.
//
// status code: this function can generate the following status codes
//                  DLL_SUCCESS: normal operation
//                  DLL_NULL:    stack data element is NULL
//                  DLS_SUCCESS: no problems encountered
//                  DLS_NULL:    normal operation
//                  DLS_INVALID: stack does not exist
//                  DLS_ERROR:   error encountered (or stack was
//                               already NULL)
//
//        note: as with the other functions, you may use no more
//              than one return() statement per function.
//
code_t rmstack(Stack ** oldStack)
{
	//
	// Initialize status code to DLS_ERROR incase program runs into
	// any errors while removing the stack
	//
	code_t status = DLS_ERROR;

	//
	// Initialize stackData List to point to oldStack list data for
	// successful rmlist execution
	//
	List *stackData = NULL;

	//
	// If stack does not exist, there is nothing to remove. Return invalid
	// status code
	//
	if (oldStack == NULL)
		status = status | DLS_INVALID;

	//
	// If oldstack pointer is NULL, return NULL pointer.  Nothing to remove since
	// it points at nothing
	//
	else if (*oldStack == NULL)
	{
		status = status | DLS_NULL;
	}

	//
	// If stack is empty, deallocate the stack and return successful status code
	// program can deallocate the stack but nothing more
	//
	else if ((*oldStack)->data == NULL)
	{
		free(*oldStack);
		*oldStack = NULL;
		status = DLS_SUCCESS | DLS_NULL | DLL_NULL | DLL_SUCCESS;
	}
	//
	// In the final case, a stack is populated. If it is populated the program
	// deallocates stack data, frees the stack, and sets the pointer to NULL.
	// This is a successfully deallocated stack
	//
	else
	{
		stackData = (*oldStack)->data;
		rmlist(&stackData);
		free(*oldStack);
		*oldStack = NULL;
		status = DLS_SUCCESS | DLS_NULL | DLL_NULL | DLL_SUCCESS;
	}

	return (status);
}
