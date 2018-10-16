#include "queue.h"

//////////////////////////////////////////////////////////////////////
//
// mkqueue() - allocate and initialize a new queue
//
//       note: the second parameter is to be the created queue's
//             maximum buffer size (bound).
//
//             be sure to utilize existing list and queue library
//             functions to facilitate your implementation. Do NOT
//             reinvent the wheel.
//
//             the front of the queue should track the first of
//             the underlying list; the back of the queue should
//             track the last node of the list.
//
//     bufsiz: a queue buffer size of 0 indicates an unbounded queue
//             > 0 will limit the total number of nodes in the queue
//
//status code: this function can generate the following status codes:
//                 DLQ_SUCCESS:     no problems encountered
//                 DLQ_EMPTY:       result of normal operation
//                 DLQ_CREATE_FAIL: error on creation
//                 DLQ_NULL:        queue remains in NULL state
//                 DLQ_INVALID:     queue does not exist
//                 DLQ_ERROR:       an error has taken place
//
//       note: as with the other functions, you may use no more
//             than one return() statement per function.
//
code_t mkqueue(Queue ** newQueue, ulli bufsiz)
{
	//
	// Initialize status code as an error incase program encounters
	// an error during queue creation
	//
	code_t status = DLQ_ERROR;
	List *newList = NULL;

	//
	// If queue is null or does not exist, return invalid code
	//
	if (newQueue == NULL || newQueue == UNDEFINED)
		status = status | DLQ_INVALID;

	//
	// if Queue pointer is NULL, allocate a new queue, setting the front and back
	// pointers to the correct positions on the list ( engine, caboose).
	//
	else if ((*newQueue) == NULL)
	{
		*newQueue = (Queue *) malloc(sizeof(Queue));
		mklist(&newList);
		(*newQueue)->data = newList;

		(*newQueue)->front = (*newQueue)->data->engine;
		(*newQueue)->back = (*newQueue)->data->caboose;

		//
		// If Queue is NULL after attempting allocation, return Null status code
		//
		if ((*newQueue) == NULL)
			status = status | DLQ_NULL;

		//
		// Else, the Queue is empty, thus creating a successfully new queue
		//
		else
		{
			status =
			    DLQ_EMPTY | DLQ_SUCCESS | DLL_EMPTY | DLL_SUCCESS;
			(*newQueue)->buffer = bufsiz;
		}
	}

	//
	// If none of hte above conditions are met, the queue is already allocated and
	// program returns error create fail status code
	//
	else
		status = status | DLQ_CREATE_FAIL;

	return (status);
}
