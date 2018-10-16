#include "queue.h"

//////////////////////////////////////////////////////////////////////
//
//     purge() - a queue library function to empty an existing queue
//               of any and all of its component nodes (deallocate
//               them).
//
//               The queue itself continues to exist, but is in an
//               empty state following the successful call to
//               purge().
//
//               be sure to utilize existing list and queue library
//               functions to facilitate your implementation. Do NOT
//               reinvent the wheel.
//
//     behavior: on a NULL queue- generate appropriate errors, but
//                  otherwise do nothing (you cannot proceed anyway)
//               on an empty queue, return the queue (job's done!)
//               on other error, generate appropriate errors and
//                  bail out (return the queue).
//
//  status code: this function generates the following status codes
//                   DLQ_SUCCESS: normal operation
//                   DLQ_EMPTY:   normal operation
//                   DLQ_NULL:    *myQueue is NULL
//                   DLQ_INVALID: myQueue does not exist
//                   DLQ_ERROR:   an error or failure was encountered
//
//         note: as with the other functions, you may use no more
//               than one return() statement per function.
//
code_t purge(Queue ** myQueue)
{
	//
	// Initialize status code to DLQ_ERROR incase the program runs into
	// any errors while purging/emptying the queue
	//
	code_t status = DLQ_ERROR;

	//
	// Initialize queueData List to point to myQueue's list data for successful
	// and clean emptying of queue's list
	//
	List *queueData = NULL;

	//
	// If queue does not exist, there is nothing to remove, Return invalid
	// status code
	//
	if (myQueue == NULL)
		status = status | DLQ_INVALID;

	//
	// If queue pointer is NULL, return NULL status code. Nothing to remove here
	// as well.
	//
	else if (*myQueue == NULL)
		status = status | DLQ_NULL;

	//
	// If queue is already empty, return a status code letting the user know they
	// already have an empty queue
	//
	else if ((*myQueue)->data->engine == NULL)
	{
		status = DLQ_EMPTY | DLQ_SUCCESS;
	}

	//
	// In the final case, a queue is populated. If it is populated the program
	// cleans out the list in queue->data and sets the front/back  pointers to NULL
	// since the list is now empty. Let user know they had a successful purge
	//
	else
	{
		queueData = (*myQueue)->data;
		empty(&queueData);
		(*myQueue)->front = NULL;
		(*myQueue)->back = NULL;
		status = DLQ_SUCCESS | DLQ_EMPTY | DLL_EMPTY | DLL_SUCCESS;
	}
	return (status);
}
