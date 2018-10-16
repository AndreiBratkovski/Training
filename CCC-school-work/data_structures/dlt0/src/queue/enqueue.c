#include "queue.h"

//////////////////////////////////////////////////////////////////////
//
//  enqueue() - place newNode onto back of given queue
//
//              be sure to utilize existing list and queue library
//              functions to facilitate your implementation. Do NOT
//              reinvent the wheel.
//
//              be mindful of bounded queue limits. A bounded
//              queue can overrun, an unbounded queue cannot.
//
//              the front of the queue should follow the first of
//              the underlying list; the back of the queue should
//              follow the last node of the list.
//
// status code: this function generates the following status codes
//                  DLQ_SUCCESS: normal operation (success!)
//                  DLQ_NULL:    queue is NULL
//                  DLQ_OVERRUN: tried to enqueue onto a full
//                               bounded queue (considered an error)
//                  DLQ_INVALID: queue does not exist
//                  DLQ_ERROR:   error encountered
//
//        note: as with the other functions, you may use no more
//              than one return() statement per function.
//
code_t enqueue(Queue ** myQueue, Node * newNode)
{
	//
	// Set default status code to dlq error incase of possible
	// enqueue error in program
	//
	code_t status = DLQ_ERROR;

	//
	// Check if queue exists, if not return invalid code
	//
	if (myQueue == NULL)
		status = status | DLQ_INVALID;

	//
	// Check if queue pointer exists, if not, return NULL pointer status code
	//
	else if (*myQueue == NULL)
		status = status | DLQ_NULL;

	//
	// If queue exists and new node exists, we can enqueue to the queue ( add )
	//
	else if (myQueue != NULL && newNode != NULL)
	{
		//
		// If queue is already full, we return a queue overrun error, can't add more
		//
		if ((*myQueue)->data->qty >= (*myQueue)->buffer
		    && (*myQueue)->back != NULL && (*myQueue)->buffer != 0)
			status = status | DLQ_OVERRUN;

		//
		// If the queue is NOT full yet, we can enqueue onto the queue and rearrange
		// queue pointers for greater sized queue
		//
		else if ((*myQueue)->data->qty < (*myQueue)->buffer
			 || (*myQueue)->buffer == 0)
		{
			(*myQueue)->back = newNode;
			(*myQueue)->data->caboose = newNode;
			(*myQueue)->data->qty += 1;
			//
			// If the queue is of size 1, then the front and back pointers
			// point to the same new Node
			//
			if ((*myQueue)->data->qty == 1)
			{
				(*myQueue)->front = newNode;
				(*myQueue)->data->engine = newNode;
			}
			//
			// Successfully enqueued queue if the above execute well
			//
			status = DLQ_SUCCESS;
		}
	}
	//
	// If newNode doesn't exist, return Null Node error, can't enqueue
	// a null node
	//
	else if (newNode == NULL)
		status = status | DLN_NULL;

	return (status);
}
