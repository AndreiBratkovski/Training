#include "stack.h"

//////////////////////////////////////////////////////////////////////
//
//      pop() - grab node off top of stack (stack is modified)
//              
//              be sure to utilize existing list and stack library
//              functions to facilitate your implementation. Do NOT
//              reinvent the wheel.
//
//              the top of the stack should track the last node in
//              its underlying list.
//
// status code: this function can generate the following status codes
//                  DLN_INVALID:       newNode doesn't exist
//                  DLN_NULL:          *newNode is NULL (after pop)
//                  DLN_ALREADY_ALLOC: *newNode exists and not NULL
//                  DLS_SUCCESS:       normal operation
//                  DLS_UNDERFLOW:     pop() from an empty stack
//                  DLS_EMPTY:         stack is EMPTY
//                  DLS_NULL:          stack is NULL
//                  DLS_INVALID:       stack does not exist
//                  DLS_ERROR:         error occurred (stack is NULL,
//                                     non-existent, underflow, etc.)
//
//        note: as with the other functions, you may use no more
//              than one return() statement per function.
//
code_t pop(Stack ** myStack, Node ** newNode)
{
	//
	// Set error code to DLS_error incase we run into an error later on
	// trying to pop off the stack
	//
	code_t status = DLS_ERROR;

	//
	// If stack doesn't exist, return invalid stack error code
	//
	if (myStack == NULL)
		status = status | DLS_INVALID;

	//
	// If stack pointer is NULL, return NULL status code
	//
	else if (*myStack == NULL)
		status = status | DLS_NULL;

	//
	// If stack exists, we can begin pop operation
	//
	else if (myStack != NULL && newNode != NULL)
	{
		//
		// If stack is empty, it is a stack underflow, we cannot pop anything
		// off of an empty stack
		//
		if ((*myStack)->data->qty == 0)
			status = status | DLS_UNDERFLOW | DLS_EMPTY | DLN_NULL;

		//
		// if stack has any stack items, we can pop the top of the stack off.
		// following logic removes stack item and returns it in newNode pointer
		// afterwards, the stack data pointers are rearranged to make a neat stack
		// with one less item
		//
		else if ((*myStack)->data->qty != 1
			 && (*myStack)->data->engine !=
			 (*myStack)->data->caboose && (*myStack)->top != NULL)
		{
			*newNode = (*myStack)->top;
			(*myStack)->top = (*myStack)->data->caboose->fro;
			(*myStack)->data->caboose =
			    (*myStack)->data->caboose->fro;
			(*myStack)->data->caboose->to = NULL;
			(*myStack)->data->qty -= 1;
			status = DLS_SUCCESS;
		}

		//
		// If stack had only one item, we return an empty status success code and pop
		// off the node
		//
		else
		{
			*newNode = (*myStack)->top;
			(*myStack)->data->engine = NULL;
			(*myStack)->data->caboose = NULL;
			(*myStack)->data->qty -= 1;
			(*myStack)->top = NULL;
			status = DLS_SUCCESS | DLS_EMPTY;
		}
	}
	//
	// If newnode doesn't exist, return invalid node status code error
	//
	else if (newNode == NULL)
		status = status | DLN_INVALID;
	//
	// If newnode pointer is NULL, return null status code error
	// indicating null pointer
	//
	else
		status = status | DLN_NULL;

	return (status);
}
