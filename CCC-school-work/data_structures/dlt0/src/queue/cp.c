#include "queue.h"

//////////////////////////////////////////////////////////////////////
//
//   cpqueue() - duplicate a given queue (especially the state of
//               its contents), in a new queue.
//
//               be sure to utilize existing list and queue library
//               functions to facilitate your implementation. Do NOT
//               reinvent the wheel.
//
//  status code: this function can generate the following status code
//                 DLQ_SUCCESS:     normal operation
//                 DLQ_CREATE_FAIL: *newQueue already exists
//                 DLQ_EMPTY:       curQueue is EMPTY
//                 DLQ_NULL:        queue is NULL
//                 DLQ_INVALID:     queue does not exist
//                 DLQ_ERROR:       an error occurred
//
//         note: as with the other functions, you may use no more
//               than one return() statement per function.
//
code_t cpqueue(Queue * curQueue, Queue ** newQueue)
{
	//
	// Initialize status code error as DLQ error incase program runs into
	// copying error later on
	//
	code_t status = DLQ_ERROR;

	//
	// Initialize new list as temp list for copying curQueue's list later
	// and pointing newStack's data to it
	//
	List *newList = NULL;

	//
	// If current queue does not exist, return error code depending on state of
	// newqueue.  since the current queue does not exist, there is no way to copy it
	//
	if (curQueue == NULL)
	{
		if (newQueue == NULL)
			status = status | DLQ_INVALID;
		else if (*newQueue == NULL)
			status = status | DLQ_NULL;
		else
			status = status | DLQ_CREATE_FAIL;
	}

	//
	// If newQueue pointer is empty and curQueue exists, we have exactly what
	// we need to copy a queue.
	//
	else if (curQueue != NULL && *newQueue == NULL)
	{
		if (curQueue->data != NULL)
		{
			//
			// If the queue is populated, point newqueue's data at the copied newlist
			// from curQueue, then point the front/back pointers of newQueue to its
			// new list
			//
			if (curQueue->data->engine != NULL
			    && curQueue->data->caboose != NULL)
			{
				mkqueue(newQueue, curQueue->buffer);
				cplist(curQueue->data, &newList);
				(*newQueue)->data = newList;
				(*newQueue)->front = newList->engine;
				(*newQueue)->back = newList->caboose;

				status = DLQ_SUCCESS | DLL_SUCCESS;
			}

			//
			// If curQueue is an empty queue, the newQueue will ned to be an empty 
			// queue. This can be accomplished by making a new queue and returning
			// a loaded status code letting the user know they have a copied and empty
			// queue
			//
			else
			{
				mkqueue(newQueue, curQueue->buffer);
				status =
				    DLQ_SUCCESS | DLQ_EMPTY | DLL_EMPTY |
				    DLL_SUCCESS;
			}
		}
	}

	//
	// If the newQueue is populated, we cannot create over it, thus resulting in
	// a create fail
	//
	else if ((*newQueue)->data->engine == NULL)
		status = status | DLQ_CREATE_FAIL;

	return (status);
}
