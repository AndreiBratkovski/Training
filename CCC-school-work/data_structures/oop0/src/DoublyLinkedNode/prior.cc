#include <DoublyLinkedNode.h>

void DoublyLinkedNode :: setPrior(Node *priorNode)
{
	//
	// Set the current node's prior pointer to the
	// node listed in the parameter
	//
	this -> prior = priorNode;
}

Node * DoublyLinkedNode :: getPrior()
{
	//
	// Grab the node previous to the current
	// doubly linked node
	//
	return(this->prior);
}
