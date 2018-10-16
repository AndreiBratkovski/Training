#include "queue.h"

//////////////////////////////////////////////////////////////////////
//
//  rmqueue() - unset, nullify members, and de-allocate the given 
//              queue. You may want to call purge() to help.
//
//              be sure to utilize existing list and queue library
//              functions to facilitate your implementation.
//
// status code: this function can generate the following status codes
//                  DLQ_SUCCESS: no problems encountered
//                  DLQ_NULL:    normal operation
//                  DLQ_INVALID: queue does not exist
//                  DLQ_ERROR:   error encountered (or queue was
//                               already NULL)
//
//        note: as with the other functions, you may use no more
//              than one return() statement per function.
//
code_t rmqueue(Queue ** curQueue)
{
	//
	// Initialize status code to DLQ_ERROR incase program runs into
	// any errors while removing the queue
	//
	code_t status = DLQ_ERROR;

	//
	// Initialize queueData List to point to curQueue data for
	// successful and clean rmlist execution
	//
	List *queueData = NULL;

	//
	// If current queue does not exist, there is nothing to remove. Return
	// invalid status code
	//
	if (curQueue == NULL)
		status = status | DLQ_INVALID;

	//
	// If current queue pointer is NULL, there is also nothing to remove since
	// the pointer points at nothing. Return NULL status code
	//
	else if (*curQueue == NULL)
	{
		status = status | DLQ_NULL;
	}
	//
	// If queue is empty, deallocate the queue and return successful status code
	// Program can deallocate the queue struct and repoint it  but nothing more
	//
	else if ((*curQueue)->data == NULL)
	{
		free(*curQueue);
		*curQueue = NULL;
		status = DLQ_SUCCESS | DLQ_NULL | DLL_NULL | DLL_SUCCESS;
	}

	//
	// In the final case, a queue is populated. If it is populated, the program
	// deallocates the queue data, frees the queue, and sets the queue pointer to
	// NULL. This is now a successfully deallocated queue.
	//
	else
	{
		queueData = (*curQueue)->data;
		rmlist(&queueData);
		free(*curQueue);
		*curQueue = NULL;
		status = DLQ_SUCCESS | DLQ_NULL | DLL_NULL | DLL_SUCCESS;
	}

	return (status);
}
