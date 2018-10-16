#include "stack.h"

//////////////////////////////////////////////////////////////////////
//
//     peek() - read node off top of stack (do not modify stack)
//              passing back a COPY of the node that is read
//
//              be sure to utilize existing list and stack library
//              functions to facilitate your implementation. Do NOT
//              reinvent the wheel.
//
//              peekNode, if it exists, will be discarded in favor
//              of information obtained from the stack (so no need
//              to pre-NULL the value)
//
//              the top of the stack should follow the last node in
//              its underlying list.
//
// status code: this function can generate the following status codes
//                  DLN_INVALID: peeknode doesn't exist
//                  DLS_SUCCESS: normal operation
//                  DLS_NULL:    stack is NULL
//                  DLS_EMPTY:   stack is EMPTY (not an error)
//                  DLS_ERROR:   stack is NULL or other error state
//
//        note: as with the other functions, you may use no more
//              than one return() statement per function.
//
code_t peek(Stack * myStack, Node ** peekNode)
{
	//
	// Initialize status code as DLS_ERROR incase we run into an error
	// later on trying to peek at the stack
	//
	code_t status = DLS_ERROR;

	//
	// If stack exists, we can peek at the top node
	//
	if (myStack != NULL)
	{
		//
		// If stack exists program copies the top node of mystack and points
		// peek node at it. this is a successful peek
		//
		if (myStack->data->engine != NULL && peekNode != NULL)
		{
			*peekNode = NULL;
			cpnode(myStack->top, peekNode);
			status = DLS_SUCCESS;
		}
		//
		// If stack is empty, we point peekNode at NULL, empty stack's top pointer
		// , returning a successful yet empty status code
		//
		else if (myStack->data->engine == NULL && peekNode != NULL)
		{
			*peekNode = NULL;
			cpnode(myStack->top, peekNode);
			status = DLS_SUCCESS | DLS_EMPTY;
		}
		//
		// If peek node is nothing, we cannot point it at the top of mystack, therefore
		// return an invalid status code
		//
		else if (peekNode == NULL)
			status = status | DLN_INVALID;
		//
		// If peek node is NULL yet mystack exists, we cannot copy over to it and peek.
		// therefore, let the user know that the stack is merely empty, nothing more.
		//
		else
			status = status | DLS_EMPTY;

	}
	//
	// If stack is NULL, return null status code, cannot be peeked at because it
	// is nothing
	//
	else
		status = status | DLS_NULL;
	return (status);
}
