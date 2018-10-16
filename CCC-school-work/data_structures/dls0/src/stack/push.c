#include "stack.h"

//////////////////////////////////////////////////////////////////////
//
//     push() - place newNode onto top of given stack
//
//              be sure to utilize existing list and stack library
//              functions to facilitate your implementation. Do NOT
//              reinvent the wheel.
//
//              the top of the stack should track the last node in
//              its underlying list.
//
// status code: this function can generate the following status codes
//                  DLN_NULL:     newNode is NULL (an error)
//                  DLS_SUCCESS:  normal operation (push successful)
//                  DLS_NULL:     stack is NULL
//                  DLS_OVERFLOW: tried to push onto a full bounded
//                                stack (considered an error)
//                  DLS_ERROR:    error encountered
//                  DLS_INVALID:  stack does not exist
//
//        note: as with the other functions, you may use no more
//              than one return() statement per function.
//
code_t push(Stack ** myStack, Node * newNode)
{
	//
	// Set default status code to DLS_ERROR incase of possible
	// pushing error
	//
	code_t status = DLS_ERROR;

	//
	// Check if stack exists, if not return invalid code
	//
	if (myStack == NULL)
		status = status | DLS_INVALID;

	//
	// Check if stack pointer exists, if not, return NULL code
	//
	else if (*myStack == NULL)
		status = status | DLS_NULL;

	//
	// If stack exists and new node exists, we can push onto the stack
	//
	else if (myStack != NULL && newNode != NULL)
	{
		//
		// If the stack is already full, we return a stack overflow error
		//
		if ((*myStack)->data->qty >= (*myStack)->size
		    && (*myStack)->size != 0 && (*myStack)->top != NULL)
			status = status | DLS_OVERFLOW;

		//
		// If the stack is NOT full yet, we can push onto the stack and rearrrage stack
		// pointers
		//
		else if ((*myStack)->data->qty < (*myStack)->size
			 || (*myStack)->size == 0)
		{
			(*myStack)->top = newNode;
			(*myStack)->data->caboose = newNode;
			(*myStack)->data->qty += 1;
			status = DLS_SUCCESS;
		}
	}
	//
	// If newnode doesn't exist, return Null node error
	//
	else if (newNode == NULL)
		status = status | DLN_NULL;

	return (status);
}
