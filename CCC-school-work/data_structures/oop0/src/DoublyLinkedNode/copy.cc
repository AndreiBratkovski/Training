#include <DoublyLinkedNode.h>

Node * DoublyLinkedNode :: copy()
{
	Node *newNode = NULL;

	//
	// Create a new instance of the Doubly Linked node
	// with the same value and same pointers as the node
	// being copied
	//
	newNode = new DoublyLinkedNode(this->getValue());
	newNode -> setAfter(this->getAfter());
	newNode -> setPrior(this->getPrior());

	return (newNode);
}
