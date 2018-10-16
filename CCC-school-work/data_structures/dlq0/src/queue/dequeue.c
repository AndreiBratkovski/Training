#include "queue.h"

//////////////////////////////////////////////////////////////////////
//
//  dequeue() - grab node off front of queue (queue is modified)
//              
//              be sure to utilize existing list and queue library
//              functions to facilitate your implementation. Do NOT
//              reinvent the wheel.
//
//              the front of the queue should follow the first of
//              the underlying list; the back of the queue should
//              follow the last node of the list.
//
//              the dequeued node pointer, if it exists, does not
//              need to be NULL; any existing content will be
//              discarded.
//
// status code: this function generates the following status codes
//                  DLN_INVALID:  dequeued node does not exist
//                  DLQ_SUCCESS:  normal operation
//                  DLQ_UNDERRUN: tried to dequeue() when empty
//                  DLQ_EMPTY:    queue is EMPTY
//                  DLQ_NULL:     queue is NULL
//                  DLQ_INVALID:  queue does not exist
//                  DLQ_ERROR:    error occurred (queue is NULL,
//                                underrun occurred, etc.)
//
//        note: as with the other functions, you may use no more
//              than one return() statement per function.
//
code_t dequeue(Queue ** myQueue, Node ** newNode)
{
	//
	// Set error code to DLQ error incase program runs into an error later
	// on trying to dequeue the queue
	//
	code_t status = DLQ_ERROR;

	//
	// If queue doesn't exist, return invalid status code
	//
	if (myQueue == NULL)
		status = status | DLQ_INVALID;

	//
	// If queue pointer is NULL, return NULL status code
	//
	else if (*myQueue == NULL)
		status = status | DLQ_NULL;

	//
	// If queue exists, and is not empty, then queue can be diminished ( dequeued )
	//
	else if (myQueue != NULL && newNode != NULL)
	{
		//
		// If queue is empty, return underrun status code, can't empty any further
		//
		if ((*myQueue)->data->qty == 0)
			status = status | DLQ_UNDERRUN;

		//
		// If queue is populated, node can be removed from the front of the list, there
		// fore leading to a successful dequeue. Pointers need to be rearranged to
		// reflect smaller list size
		//
		else if ((*myQueue)->data->qty != 1
			 && (*myQueue)->data->engine !=
			 (*myQueue)->data->caboose && (*myQueue)->back != NULL)
		{
			*newNode = (*myQueue)->front;
			(*myQueue)->front = (*myQueue)->data->engine->to;
			(*myQueue)->data->engine = (*myQueue)->data->engine->to;
			(*myQueue)->data->engine->fro = NULL;
			(*myQueue)->data->qty -= 1;
			status = DLQ_SUCCESS | DLL_SUCCESS;
		}

		//
		// If queue is populated with one node, below code is same as above except maki
		// sure that status code reflects an empty Queue/list as well as repointing the
		// front and back pointers to NULL, now that the queue is empty
		//
		else
		{
			*newNode = (*myQueue)->front;
			(*myQueue)->data->engine = NULL;
			(*myQueue)->data->caboose = NULL;
			(*myQueue)->data->qty -= 1;
			(*myQueue)->front = NULL;
			(*myQueue)->back = NULL;
			status =
			    DLQ_SUCCESS | DLQ_EMPTY | DLL_EMPTY | DLL_SUCCESS;
		}
	}

	//
	// If new node doesn't exist, return invalid node status code
	//
	else if (newNode == NULL)
		status = status | DLN_INVALID;

	//
	// if new node pointer is NULL, return null status code error
	// indicating a null pointer. Dequeue cannot occur with this and the above
	// condition due to a faulty node
	//
	else
		status = status | DLN_NULL;

	return (status);
}
