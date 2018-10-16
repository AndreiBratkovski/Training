#include "stack.h"

//////////////////////////////////////////////////////////////////////
//
//  isempty() - return an indication as to stack's emptiness
//
//              be sure to utilize existing list and stack library
//              functions to facilitate your implementation. Do NOT
//              reinvent the wheel.
//
//              the top of the stack should follow the last node in
//              its underlying list.
//
// status code: this function can generate the following status codes
//                  DLS_SUCCESS:  normal operations
//                  DLS_OVERFLOW: stack is populated
//                  DLS_NULL:     stack is NULL
//                  DLS_EMPTY:    stack is empty
//                  DLS_ERROR:    error encountered (stack is NULL)
//
//        note: as with the other functions, you may use no more
//              than one return() statement per function.
//
code_t isempty(Stack * myStack)
{
	//
	// Initialize DLS_ERROR status code incase checking if the stack is empty
	// runs into any errors
	//
	code_t status = DLS_ERROR;

	//
	// If the stack does not exist, return NULL stack code.  It does not exist, therefore
	// it is not empty
	//
	if (myStack == NULL)
		status = status | DLS_NULL;

	//
	// If myStack top is NULL, then it is by definition, empty return
	// successful empty status code letting user know the stack is empty
	//
	else if (myStack->top == NULL)
		status = DLS_SUCCESS | DLS_EMPTY;

	//
	// If stack is full, let user know that any more added, and it would be a stack
	// overflow. successful isempty check 
	//
	else if (myStack->data->qty == myStack->size)
		status = DLS_SUCCESS | DLS_OVERFLOW;

	//
	// in any other case, the stack would be full or populated, thus leading to a 
	// successful stack overflow status code
	//
	else
		status = DLS_SUCCESS | DLS_OVERFLOW;

	return (status);
}
